#include<iostream>
using namespace std;

struct node{
    public:
    node *left;
    int data;
    node *right;
};

class BST{
    public:
    node *root;
    BST(){
        root = NULL;
    }
    void create();
    void insert(node*, node*);
    void mirror(node*);
    void search(node*, int);
    void Inorder(node *);
    void treeTraversal();
    int min(node*);
    int nodes_lp(node*);
};

void BST::create(){
    node *temp = new node();
    cout<<"Enter data - ";
    cin>>temp->data;
    temp->left = temp->right = NULL;
    if(root == NULL)
        root = temp;
    else
        insert(root, temp);
    }

void BST::insert(node *root, node *temp){
    if(temp->data < root->data){
        if(root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else{
        if(root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}

int BST::nodes_lp(node *root){
    if(root == NULL)
        return 0;
    int leftt = nodes_lp(root->left);
    int rightt = nodes_lp(root->right);
    return max(leftt,rightt)+1;
}

int BST::min(node *root){
    if (root->left == NULL)
        return root->data;
    else
        return min(root->left);
}


void BST::mirror(node *root){
    if(root == NULL)
        return;
    else{
        node *temp = new node();
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void BST::search(node *root, int key){
    if(key < root->data){
        if(root->left == NULL)
            cout<<"Not Found !"<<endl;
        else
            search(root->left,key);
    }
    else if(key > root->data){
        if(root->right == NULL)
            cout<<"Not Foundv!"<<endl;
        else
            search(root->right, key);
    }
    else{
        cout<<"Found"<<endl;
    }
}

void BST::Inorder(node *temp) 
{
    if(temp != NULL)
    {
        Inorder(temp->left);
        cout<<temp->data<<" ";
        Inorder(temp->right);
    }
}

void BST::treeTraversal()
{
    cout<<"\n Inoder Traversal = ";
    Inorder(root); cout<<endl; 
}

int main(){
    BST B;
    int ch,n;
    x: B.create();
    cout<<"Do you want to continue(1/0): ";
    cin>>n;
    if(n==1) goto x;

    while(1){
        cout<<"\n1. Enter value";
        cout<<"\n2. No. of nodes in longest path";
        cout<<"\n3. Min value";
        cout<<"\n4. Mirror";
        cout<<"\n5. Search";
        cout<<"\n6. Inorder";
        cout<<"\n7. Exit";
        cout<<"\nEnter choice - ";
        cin>>ch;
        switch (ch){
        case 1: B.create();
            break;
        case 2: cout<<"\nNodes - "<<B.nodes_lp(B.root)<<endl;
            break;
        case 3: cout<<"\nMin Value - "<<B.min(B.root)<<endl;
            break;
        case 4: B.mirror(B.root);
            break;
        case 5: 
                cout<<"\nEnter no. you want to search - ";
                cin>>n;
                B.search(B.root, n);
            break;
        case 6: B.treeTraversal();
            break;
        case 7: exit(1);
            break;
        default: cout<<"Invalid choice !";
            break;
        }
    }
}