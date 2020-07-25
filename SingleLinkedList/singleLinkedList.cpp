#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* link;
};

void insertData_Head(int);
void insertData_Tail(int);
void insertData_Position(int, int);
void traverse();
void displayReverse(Node*);
void delete_Head();
void delete_Tail();
void delete_Given(int);

Node* head; //this is the pointer which will hold the head address of the linked list

//Driver Function
int main()
{
    head = NULL;

    insertData_Head(5);
    insertData_Head(6);
    insertData_Head(7);
    insertData_Head(8);

    insertData_Tail(4);
    insertData_Tail(2);
    insertData_Tail(1);
    insertData_Head(9);
    insertData_Tail(0);

    insertData_Position(4,3);
    traverse();
    Node *temp = new Node();
    temp = head;
    displayReverse(temp);

    delete_Head();
    delete_Tail();
    delete_Given(5);

    return 0;

}

//This function allows to insert data at the head of the linked list
void insertData_Head(int inputData){
    Node* p = new Node();

    p->data=inputData;
    p->link=head;
    head=p;

    cout << p->data << " inserted successfully\n" << endl;
}

//This function allows to insert data at the end of the linked list
void insertData_Tail(int inputData){

    Node *p = new Node();

    Node *t = new Node();
    t = head;
    if(t==NULL){
        p->data = inputData;
        p->link=NULL;
        head=p;
    }
    else{
        while(t->link!=NULL)
            t=t->link;
        p->data = inputData;
        t->link = p;
        p->link = NULL;
    }

}

//This function allows to add data after a specified element in the linked list
void insertData_Position(int position, int inputData){
    if(position){
        Node* t = new Node();
        t=head;
        while(t->data!=position)
            t=t->link;
        Node* p = new Node();
        p->data=inputData;
        p->link = t->link;
        t->link = p;
    }
}

//This function deletes the first element from the head
void delete_Head(){
    Node* t = new Node();
    t = head;

    cout << endl << "Data before deletion is : \n";
    traverse();

    head = t->link;
    free(t);

    cout << endl << "Data after deletion from head is : \n";
    traverse();
}
void delete_Tail(){
    cout << endl << "Data before deletion is : \n";
    traverse();
    Node *t = new Node();
    t = head;
    while(t->link->link!=NULL)
        t=t->link;
    Node *temp1 = new Node();
    temp1 = t->link;
    t->link=NULL;
    free(temp1);
    cout << endl << "Data after deletion from tail is : \n";
    traverse();
}

void delete_Given(int del_data){
    cout << endl << "Data before deletion is : \n";
    traverse();
    Node *t = new Node();
    t = head;
    while(t->link->data!=del_data)
        t=t->link;
    Node *temp1 = new Node();
    temp1 = t->link;
    t->link = t->link->link;
    free(temp1);
    cout << endl << "Data after deletion of "<< del_data << " is: ";
    traverse();

}

//This function traverses and prints all the elements in the linked list.
void traverse(){

    Node *t = new Node();
    t=head;
    while(t)
    {
        //uncomment the below line if you want both the address and data to be seen in linked list
        //cout << "[" << t->data << "," << t->link << "]" <<"->" ;
        //comment the below line if you uncomment above line to avoid repetition
        cout << "[" << t->data << "]" <<"->";

        t=t->link;
    }
    cout << "NULL\n";

}

//This function displays the element in the linked list in reverse order
void displayReverse(Node *t){
    if(t==NULL)
        return;
    displayReverse(t->link);
    cout << t->data <<" ";
}
