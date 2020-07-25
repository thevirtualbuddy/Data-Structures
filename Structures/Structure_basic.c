#include <stdio.h>
#include <stdlib.h>

struct node{
    int i;
    int j;
};

int main()
{
    struct node x={2,3},*ps;
    ps=&x;

    printf("%d\t%d\n",x.i,x.j);
    printf("%d\t%d\n",(ps)->i,(ps)->j);
    printf("%d\t%d\n",(*ps).i,(*ps).j);

    char c, *pc;
    int a, *pi;

    //size of the pointer remains the same irrespective of the data type.

    printf("size of the character : %d\n",sizeof(c)); //size of the character
    printf("size of the character pointer : %d\n",sizeof(pc)); //size of the character pointer
    printf("size of the integer : %d\n",sizeof(a)); //size of the integer
    printf("size of the integer pointer : %d\n",sizeof(pi)); //size of the integer pointer
    printf("size of the structure : %d\n",sizeof(x)); //size of the structure
    printf("size of the structure pointer : %d\n",sizeof(ps)); //size of the structure pointer


    return 0;
}
