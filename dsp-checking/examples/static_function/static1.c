#include<static2.h>
#include<stdio.h>

static void same_name(int *p)
{
    printf("AAA\n");

    assert(p!=NULL);

}

void main()
{
   int val = 10, *p;
   __fixed x;
   same_name(&val);
   same_name(p);

   diff_name(&val);
}


