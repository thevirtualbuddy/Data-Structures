#include <iostream>

using namespace std;

class Stack{
    public:
        int data;
        Stack* link;
};

Stack* head = new Stack();
void push(int);
int pop();
void display();

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
    cout << endl << "Popped element is: " << ele1 << endl;
    int ele2 = pop();
    cout << endl << "Popped element is: " << ele2 << endl;

    return 0;



}

//Linked list implementation for insertion at head
void push(int inputData){
    Stack *temp = new Stack();
    temp->data = inputData;
    temp->link=head;
    head=temp;
}

//Linked list implementation for deletion from head
int pop(){
    if(head==NULL){
        cout << "Underflow!" << endl;
        return -1; //Considering -1 is not a valid  number
    }
    cout << endl << "Before popping: ";
    display();
    Stack *temp = new Stack();
    temp = head;
    head = head->link;
    int data = temp->data;
    free(temp);
    cout << endl << "After popping: ";
    display();
    return data;
}

void display(){
    if(head==NULL){
        return;
    }
    Stack *temp = new Stack();
    temp = head;
    while(temp->link!=NULL){
       cout << temp->data << ",";
       temp = temp->link;
    }

    cout << NULL;

}
