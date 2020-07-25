#include <iostream>
#define MAXSIZE 20
using namespace std;

int stackArray[MAXSIZE]; //This is our basic stack of size 20
int top=-1; //This is the variable which keeps track of our top element

void push(int);
int pop();
void display();

//Driver function
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    display();

    int ele1 = pop();
    cout << "Popped element is: " << ele1 << endl;
    int ele2 = pop();
    cout << "Popped element is: " << ele2 << endl;

    return 0;
}
//This function pushes element in stack
void push(int inputData){
    if(top==MAXSIZE)
    {
        cout << "[-] Buffer overflow\n\n";
        return;
    }
    else{
        stackArray[++top]=inputData;
    }
}

//This function displays the elements of the stack
void display(){
    for(int i=top; i>-1; i--)
        cout << stackArray[i] << ",";
    cout << endl;
}

//This function pops the top element from the stack
int pop(){

    if(top==-1){
        cout << "Underflow\n\n";
        return -1; //Considering -1 is not a valid input to stack
    }
    cout << endl << "Before popping : ";
    display();
    int data = stackArray[top];
    top--;
    cout  << "After popping : ";
    display();
    return data;
}

