#include <stdio.h>
#include <stdlib.h>
struct node{

    int i;
    struct node *link;

};
int main()
{
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p->i=10;
    printf("%d\n",p->i);
    //the below loop will result to overflow and will freeze your computer, uncomment and run at your own risk
    /*while(1){
            struct node *q = (struct node*) malloc(sizeof(struct node));
            q++;
    }*/
    return 0;
}
