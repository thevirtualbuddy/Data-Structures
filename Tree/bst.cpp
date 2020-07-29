#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* lnode;
        Node* rnode;
};

Node* insertData(int,Node*); //Insertion of data in the tree
void preorder(Node*); //Traversal of the tree in preorder
void inorder(Node*); //Traversal of the tree in in-order
void postorder(Node*);   //Traversal of the tree in postorder

Node* deleteData(int, Node*);   //Deletion of node from the tree
void searchData(int, Node*); //Searching of node in a tree

int countLeafnode(Node*);
int countNonleafnode(Node*);
int countFullnode(Node*);
int heightTree(Node*);
int minNodeTree(Node*);
int maxNodeTree(Node*);
bool isComplete(Node*);

int maxNode(int x, int y){
    return (x>y)?x:y;
}

int main()
{
    Node *head=NULL; //This is the root of the tree

    head=insertData(50,head);
    insertData(15,head);
    insertData(62,head);
    insertData(5,head);
    insertData(20,head);
    insertData(58,head);
    insertData(91,head);
    insertData(3,head);

    cout << "Inorder traversal is: ";
    inorder(head);
    cout << endl;

    cout << "Preorder traversal is: ";
    preorder(head);
    cout << endl;

    cout << "Postorder traversal is: ";
    postorder(head);
    cout << endl;

    searchData(20, head);
    searchData(100, head);



    cout << endl <<  "Before deletion :";
    inorder(head);
    head = deleteData(3,head);
    cout << endl << "After deletion: ";
    inorder(head);

    int leafno, nonleafno, fullnodeno, height;

    leafno = countLeafnode(head);
    cout << endl << "The no of leaf nodes in our tree is: " << leafno << endl;

    nonleafno = countNonleafnode(head);
    cout << endl << "The no of non-leaf nodes in our tree is: " << nonleafno << endl;

    fullnodeno = countFullnode(head);
    cout << endl << "The no of full nodes in our tree is: " << fullnodeno << endl;

    height = heightTree(head);
    cout << endl << "The height of our tree is: " << height << endl;

    int minVal;
    minVal = minNodeTree(head);
    cout << endl << minVal << " is the minimum\n";

    int maxVal;
    maxVal = maxNodeTree(head);
    cout << endl << maxVal << " is the maximum\n";

    bool check;
    check = isComplete(head);

    if(check)
        cout << endl << "It is a complete tree\n";
    else
        cout << endl << "It is a not complete tree\n";
    cout << endl << check << endl;
    return 0;
}

Node* insertData(int inputdata, Node* p){

    if(p==NULL){
        Node* t = new Node();
        t->data=inputdata;
        t->lnode=NULL;
        t->rnode=NULL;
        //Only for the first time, t is returned to the driver/main function, and
        //thereafter it is returned either to p->rnode or p->lnode
        return t;

    }
    else{
        if(inputdata > p->data)
            p->rnode = insertData(inputdata,p->rnode);
        else
            p->lnode = insertData(inputdata,p->lnode);
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
void preorder(Node *p){

    if(!p)
        return;

    cout << p->data << " ";
    preorder(p->lnode);
    preorder(p->rnode);
}
void postorder(Node *p){

    if(!p)
        return;

    postorder(p->lnode);
    postorder(p->rnode);
    cout << p->data << " ";
}

void searchData(int findData, Node* p){
    if(!p){
        cout << endl << findData << " doesn't exist in the tree.\n";
        return;
    }
    else{
        if(p->data==findData){
            cout << endl <<findData << " is found!\n";
        }
        else{
            if(findData>p->data)
                searchData(findData,p->rnode);
            else
                searchData(findData,p->lnode);
        }
    }
}

Node* deleteData(int key, Node* root){

    //base case
    if(!root)
        return root;

    //the element to be deleted is in the right subtree of the tree
    if(key>root->data)
        root->rnode = deleteData(key, root->rnode);

    //the element to be deleted is in the left subtree of the tree
    else if(key<root->data)
        root->lnode = deleteData(key, root->lnode);

    //the element to be deleted is found
    else{

        // Case 1 and 2 : if the element to be deleted has one or no child
        if(root->lnode==NULL){
            Node *temp = root->rnode;
            free(root);
            return (temp);
        }

        if(root->rnode==NULL){
            Node *temp = root->lnode;
            free(root);
            return (temp);
        }

        //Case 3: if the element to be deleted has two children
        else{
                Node *temp = root->rnode;
                //Finding the inorder successor i.e. the least element in the Right subtree of the node.
                while(temp->lnode){
                    temp = temp->lnode;
                }
                //Copy the least value to the current node.
                root->data = temp->data;
                //Deleting the least value in the right subtree, which is a leaf.
                root->rnode = deleteData(temp->data, root->rnode);
        }
    }
    return root;

}

int countLeafnode(Node *p)
{
    if(p==NULL)
        return 0;
    if(!(p->lnode) && !(p->rnode))
        return 1;
    else{
        int l,r;
        l=countLeafnode(p->lnode);
        r=countLeafnode(p->rnode);
        return (l+r);
    }
}

int countNonleafnode(Node *p){
    if(p==NULL)
        return 0;
    if(!(p->lnode) && !(p->rnode))
        return 0;
    else{
        int l,r;
        l=countNonleafnode(p->lnode);
        r=countNonleafnode(p->rnode);
        return (1+l+r);
    }
}

int countFullnode(Node *p){
    if(p==NULL)
        return 0;
    if(!(p->lnode) && !(p->rnode))
        return 0;
    else{
        int l,r;
        l=countFullnode(p->lnode);
        r=countFullnode(p->rnode);
        if(p->lnode && p->rnode)
            return (l+r+1);
        else
            return (l+r);
    }
}

int heightTree(Node *p){
    if(p==NULL)
        return 0;
    if(!(p->lnode) && !(p->rnode))
        return 0;
    else{
        int l,r;
        l=heightTree(p->lnode);
        r=heightTree(p->rnode);
        return (1+(maxNode(l,r)));
    }
}

int minNodeTree(Node *p){
        Node *t = p;
        while(t->lnode)
            t=t->lnode;
        return t->data;
}

int maxNodeTree(Node *p){

        Node *t=p;
        while(t->rnode)
            t=t->rnode;
        return t->data;
}

bool isComplete(Node* p){
    if(p==NULL)
        return true;
    if(p->lnode==NULL && p->rnode==NULL)
        return true;
    if(p->lnode && p->rnode){
        bool l,r;
        l = isComplete(p->lnode);
        r= isComplete(p->rnode);
        return (l && r);
    }
}
