#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    int *c;
};

void fun1(struct node*);
void fun2(struct node*);
void fun3(struct node*);
void fun4(struct node*);
void fun5(struct node*);
void fun6(struct node*);
void fun7(struct node*);

int main()
{
    struct node a[2], *p;



    int b[2]={30,40};
    p=&a[0];
    a[0].i = 10;
    a[1].i=20;
    a[0].c=b;
    fun1(p);
    fun2(p);
    fun3(p);
    fun4(p);
    fun5(p);
    fun6(p);
    fun7(p);

    return 0;
}
void fun1(struct node*p){
    printf("++p->i   %d\n",++p->i);
}

void fun2(struct node*p){
    printf("(++p)->i   %d\n",(++p)->i);
}

void fun3(struct node*p){
    printf("(p++)->i    %d\n",(p++)->i);
}

void fun4(struct node*p){
    printf("*p->c   %d\n",*p->c);
}

void fun5(struct node*p){
    printf("*p->c++   %d\n",*p->c++);

}

void fun6(struct node*p){
    printf("(*p->c)++   %d\n",(*p->c)++);
}

void fun7(struct node*p){
    printf("*p++->c  %d\n",*(p++)->c);
}
