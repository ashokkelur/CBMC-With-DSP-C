/*******************************************************************\

Module:

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#ifdef _WIN32
#include <process.h>
#define getpid _getpid
#endif

#include <i2string.h>
#include <str_getline.h>
#include <prefix.h>

#include "cvc_dec.h"

/*******************************************************************\

Function: cvc_temp_filet::cvc_temp_filet

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

cvc_temp_filet::cvc_temp_filet()
{
  temp_out_filename="cvc_dec_out_"+i2string(getpid())+".tmp";

  temp_out.open(
    temp_out_filename.c_str(),
    std::ios_base::out | std::ios_base::trunc);
}

/*******************************************************************\

Function: cvc_temp_filet::~cvc_temp_filet

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

cvc_temp_filet::~cvc_temp_filet()
{
  temp_out.close();
  
  if(temp_out_filename!="")
    unlink(temp_out_filename.c_str());
    
  if(temp_result_filename!="")
    unlink(temp_result_filename.c_str());
}

/*******************************************************************\

Function: cvc_dect::dec_solve

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

decision_proceduret::resultt cvc_dect::dec_solve()
{
  cvc_prop.out << "QUERY FALSE;" << std::endl;
  cvc_prop.out << "COUNTERMODEL;" << std::endl;
  
  post_process();

  temp_out.close();

  temp_result_filename=
    "cvc_dec_result_"+i2string(getpid())+".tmp";
    
  std::string command=
    "cvcl "+temp_out_filename+" > "+temp_result_filename+" 2>&1";
    
  system(command.c_str());
  
  status("Reading result from CVCL");

  return read_cvcl_result();
}

/*******************************************************************\

Function: cvc_dect::read_assert

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void cvc_dect::read_assert(std::istream &in, std::string &line)
{
  // strip ASSERT
  line=std::string(line, strlen("ASSERT "), std::string::npos);
  if(line=="") return;
  
  // bit-vector
  if(line[0]=='(')
  {
    // get identifier
    std::string::size_type pos=
      line.find(' ');

    std::string identifier=std::string(line, 1, pos-1);
    
    // get value
    if(!str_getline(in, line)) return;

    // skip spaces    
    pos=0;
    while(pos<line.size() && line[pos]==' ') pos++;
    
    // get final ")"
    std::string::size_type pos2=line.rfind(')');
    if(pos2==std::string::npos) return;    
    
    std::string value=std::string(line, pos, pos2-pos);
    
    std::cout << ">" << identifier << "< = >" << value << "<";
    
    std::cout << std::endl;
  }
  else
  {
    // boolean
    tvt value=tvt(true);
    
    if(has_prefix(line, "NOT "))
    {
      line=std::string(line, strlen("NOT "), std::string::npos);
      value=tvt(false);
    }
    
    if(line=="") return;
    
    if(line[0]=='l')
    {
      unsigned number=atoi(line.c_str()+1);
      assert(number<cvc_prop.no_variables());
      cvc_prop.assignment[number]=value;
    }
  }
}

/*******************************************************************\

Function: cvc_dect::read_cvcl_result

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

decision_proceduret::resultt cvc_dect::read_cvcl_result()
{
  std::ifstream in(temp_result_filename.c_str());
  
  std::string line;
  
  while(str_getline(in, line))
  {
    if(has_prefix(line, "Invalid."))
    {
      cvc_prop.reset_assignment();
    
      while(str_getline(in, line))
      {
        if(has_prefix(line, "ASSERT "))
          read_assert(in, line);
      }
      
      return D_SATISFIABLE;
    }
    else if(has_prefix(line, "Valid."))
      return D_UNSATISFIABLE;
  }
  
  error("Unexpected result from CVC-Lite");
  
  return D_ERROR;
}

