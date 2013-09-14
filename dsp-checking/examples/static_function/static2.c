
#include <stdio.h>

static int same_name(int * p);
static int same_name(int * p)
{

    printf("same name %d", *p);
}


void diff_name(int *p)
{

   printf("Diff name %d", *p);

}
