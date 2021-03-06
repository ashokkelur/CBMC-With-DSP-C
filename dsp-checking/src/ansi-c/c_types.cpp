/*******************************************************************\

Module:

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <std_types.h>

#include "c_types.h"
#include "config.h"

/*******************************************************************\

Function: build_float_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet build_float_type(unsigned width)
{
  if(config.ansi_c.use_fixed_for_float)
  {
    fixedbv_typet result;
    result.set_width(width);
    result.set_integer_bits(width/2);
    return result;
  }
  else
  {
    floatbv_typet result;

    switch(width)
    {
    case 32: result=ieee_float_spect::single_precision().to_type(); break;
    case 64: result=ieee_float_spect::double_precision().to_type(); break;
    default: assert(false);
    }
    
    assert(width==result.get_width());

    return result;
  }
}

/*******************************************************************\

Function: index_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet index_type()
{
  // same as signed size type
  return signedbv_typet(config.ansi_c.pointer_width);
}

/*******************************************************************\

Function: enum_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet enum_type()
{
  return signedbv_typet(config.ansi_c.int_width);  
}

/*******************************************************************\

Function: int_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet int_type()
{
  return signedbv_typet(config.ansi_c.int_width);  
}

/*******************************************************************\

Function: uint_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet uint_type()
{
  return unsignedbv_typet(config.ansi_c.int_width);  
}

/*******************************************************************\

Function: size_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet size_type()
{
  return unsignedbv_typet(config.ansi_c.pointer_width);  
}

/*******************************************************************\

Function: signed_size_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet signed_size_type()
{
  return signedbv_typet(config.ansi_c.pointer_width);  
}

/*******************************************************************\

Function: long_int_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet long_int_type()
{
  return signedbv_typet(config.ansi_c.long_int_width);  
}

/*******************************************************************\

Function: long_long_int_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet long_long_int_type()
{
  return signedbv_typet(config.ansi_c.long_long_int_width);  
}

/*******************************************************************\

Function: long_uint_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet long_uint_type()
{
  return unsignedbv_typet(config.ansi_c.long_int_width);  
}

/*******************************************************************\

Function: long_long_uint_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet long_long_uint_type()
{
  return unsignedbv_typet(config.ansi_c.long_long_int_width);  
}

/*******************************************************************\

Function: char_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet char_type()
{
  if(config.ansi_c.char_is_unsigned)
    return unsignedbv_typet(config.ansi_c.char_width);
  else
    return signedbv_typet(config.ansi_c.char_width);
}

/*******************************************************************\

Function: uchar_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet uchar_type()
{
  return unsignedbv_typet(config.ansi_c.char_width);
}

/*******************************************************************\

Function: wchar_t_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet wchar_t_type()
{
  return signedbv_typet(config.ansi_c.wchar_t_width);
}

/*******************************************************************\

Function: float_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet float_type()
{
  return build_float_type(config.ansi_c.single_width);
}

/*******************************************************************\

Function: double_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet double_type()
{
  return build_float_type(config.ansi_c.double_width);
}

/*******************************************************************\

Function: long_double_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet long_double_type()
{
  return build_float_type(config.ansi_c.long_double_width);
}

/*******************************************************************\

Function: fixed_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet fixed_type()
{
    fixedbv_typet result;
    result.set_width(config.ansi_c.fixed_width);
    result.set_integer_bits(1);
    return result;
}

/*******************************************************************\

Function: fixed_short_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet fixed_short_type()
{
    fixedbv_typet result;
    result.set_width(config.ansi_c.short_fixed_width);
    result.set_integer_bits(1);
    return result;
}


/*******************************************************************\

Function: accum_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet accum_type()
{
    fixedbv_typet result;
    result.set_width(config.ansi_c.accum_width);
    result.set_integer_bits(9);
    return result;
}


/*******************************************************************\
      
Function: accum_short_type
      
  Inputs:

 Outputs:
    
 Purpose:
      
\*******************************************************************/
    
typet accum_short_type()
{   
    fixedbv_typet result;
    result.set_width(config.ansi_c.short_accum_width);
    result.set_integer_bits(9);
    return result;
}    


/*******************************************************************\

Function: pointer_diff_type

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

typet pointer_diff_type()
{
  return signedbv_typet(config.ansi_c.pointer_width);
}

