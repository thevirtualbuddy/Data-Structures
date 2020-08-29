#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* lnode;
        Node* rnode;
        int height;
};

int maxofTwo(int,int);
int heightofTree(Node*);
int getBalance(Node*);
Node* insertData(int,Node*);
Node* leftRotate(Node*);
Node* rightRotate(Node*);
void inorder(Node*);

int main()
{
    cout << "AVL Tree!" << endl;

    Node *head=NULL; //This is the root of the tree

    head=insertData(50,head);
    insertData(15,head);
    insertData(62,head);
    insertData(5,head);
    insertData(20,head);
    insertData(50,head);
    insertData(91,head);
    insertData(5,head);

    inorder(head);

    cout << "Height is " << head->height;

    cout << endl << "Balance factor is: " << getBalance(head);
    return 0;
}

int maxofTwo(int x, int y){
    return x>y?x:y;
}

int heightofTree(Node* n){
    if(n==NULL)
        return 0;
    else
        return n->height;
}

// Get balance factor of the node
int getBalance(Node *p)
{
	if (p == NULL)
		return 0;
	return heightofTree(p->lnode) - heightofTree(p->rnode);
}

Node* rightRotate(Node* z){
    Node *leftSubtree = z->lnode;
    Node *temp = leftSubtree->rnode;

    //Performing rotation
    leftSubtree->rnode = z; //Now Leftsubtree main node becomes the root
    z->lnode = temp;

    //Updating heights

    z->height = maxofTwo(heightofTree(z->lnode),heightofTree(z->rnode)) + 1;
    leftSubtree->height = maxofTwo(heightofTree(leftSubtree->lnode),heightofTree(leftSubtree->rnode)) + 1;

    //Return new root
    return leftSubtree;

}

Node *leftRotate(Node *z){
    Node *rightSubtree = z->rnode;
    Node *temp = z->lnode;

    //Performing rotations
    rightSubtree->lnode = z; //Now rightsubtree main node becomes the root
    z->rnode = temp;

    //Updating heights
    rightSubtree->height = maxofTwo(heightofTree(rightSubtree->lnode),heightofTree(rightSubtree->rnode)) + 1;
    z->height = maxofTwo(heightofTree(z->lnode),heightofTree(z->rnode)) + 1;

    //Return new root
    return rightSubtree;


}

Node* insertData(int inputdata,Node* p){

    // 1. Performing standard BST insertion
    if(p==NULL){
        Node* t = new Node();
        t->data=inputdata;
        t->lnode=NULL;
        t->rnode=NULL;
        t->height = 1;
        //Only for the first time, t is returned to the driver/main function, and
        //thereafter it is returned either to p->rnode or p->lnode
        return t;
    }
    else{

        if(inputdata > p->data)
            p->rnode = insertData(inputdata,p->rnode);
        else if(inputdata == p->data)
            cout << inputdata << " is already in tree!\n";
        else
            p->lnode = insertData(inputdata,p->lnode);
    }

    //2. Updating height of ancestor node
    p->height = 1 + maxofTwo(heightofTree(p->lnode),heightofTree(p->rnode));

    //3. Get balance factor of this ancestor node, and check if it is unbalanced

    int balance = getBalance(p);

    //4. If balance is greater than 1 or less than -1, we get 4 cases

    //Case 1: LL Case
    if(balance>1 && inputdata < p->lnode->data){
        return rightRotate(p);
    }

    //Case 2: RR Case
    if (balance<-1 && inputdata>p->rnode->data){
        return leftRotate(p);
    }

    //Case 3: LR Case
    if (balance>1 && inputdata>p->lnode->data){
        p->lnode = leftRotate(p->lnode);
        return rightRotate(p);
    }

    //Case 4: RL Case
    if(balance<-1 && inputdata<p->rnode->data){
        p->rnode = rightRotate(p->rnode);
        return leftRotate(p);
    }


    //This statement return p, will be executed after all the statement is executed.
    //So, it returns with what the head pointer was sent with i.e. the root.
    return p;
}

void inorder(Node *p){

    if(!p)
        return;
    inorder(p->lnode);
    cout << p->data << " ";
    inorder(p->rnode);
}
