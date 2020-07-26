//Implementation of a circular queue using array, modular increment is done at the front and rear.

#include <iostream>
#define MAXSIZE 20
using namespace std;

int queueArray[MAXSIZE];
int frontPtr=0;
int rearPtr=0;

void enqueue(int);
int dequeue();
void display();

//Driver function
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);

    enqueue(9);
    enqueue(10);
    enqueue(11);
    enqueue(12);

    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);

    enqueue(17);
    enqueue(18);
    enqueue(19);
    enqueue(20);

    enqueue(21);
    enqueue(22);
    enqueue(23);
    enqueue(24);

    int dequeuElement;

    dequeuElement = dequeue();
    cout << "Dequeue element is: " << dequeuElement << endl;
    dequeuElement = dequeue();
    cout << "Dequeue element is: " << dequeuElement << endl;
    dequeuElement = dequeue();
    cout << "Dequeue element is: " << dequeuElement << endl;
    dequeuElement = dequeue();
    cout << "Dequeue element is: " << dequeuElement << endl;
    dequeuElement = dequeue();
    cout << "Dequeue element is: " << dequeuElement << endl;

    display();
    return 0;
}

//This function helps to enqueue data in the queue
void enqueue(int inputData){
    rearPtr = (rearPtr+1)%20; //20 is the n or say the MAXSIZE
    if(rearPtr==frontPtr){
        cout << "Queue is full!" << endl;
        if(rearPtr==0)
            rearPtr=20-1;
        else
            rearPtr=rearPtr-1;
        return;
    }
    else{
        queueArray[rearPtr]=inputData;
        cout << "Value of rear pointer after insertion is: " << rearPtr << endl;
        cout << "Data successfully inserted: " << inputData << endl;
        return;
    }
}

//This function helps to dequeue oldest data from the queue
int dequeue(){
    if(frontPtr==rearPtr){
        cout << "Queue is empty" << endl;
        return -1;
    }
    else{
        int data;
        frontPtr = (frontPtr+1)%20;
        cout << "Value of front pointer after deletion is: " << frontPtr << endl;
        data = queueArray[frontPtr];
        return data;
    }
}

//This function helps to display all the data present in the queue
void display(){
    for(int i=frontPtr; i<rearPtr;i++){
        cout << "[" << queueArray[i] << "]," ;
    }
    cout << "NULL" << endl;
}
