#include<iostream>
using namespace std;
struct node{
    public:
    node *left;
    string word;
    string meaning;
    node *right;
};

class Dict{
    public:
    node *root;
    Dict(){
        root = NULL;
    }
    void create();
    void insert(node*, node*);
    void asce(node*);
    void dece(node*);
    void modify(node*, string);
    node *minValue(node*);
    node *delnode(node*, string);
};
void Dict::create(){
    node *temp = new node();
    cout<<"Enter a word - ";
    cin>>temp->word;
    cout<<"Enter meaning - ";
    cin>>temp->meaning;
    temp->left = temp->right = NULL;
    if(root == NULL)
        root = temp;
    else
        insert(root, temp);
}
void Dict::insert(node *root, node *temp){
    if(temp->word < root->word){
        if(root->left == NULL)
            root->left = temp;
        else
            insert(root->left,temp);
    }
    else{
        if(root->right == NULL )
            root->right = temp;
        else
            insert(root->right, temp);
    }
}
void Dict::asce(node *temp){
    if(temp != NULL){
        asce(temp->left);
        cout<<temp->word<<"-"<<temp->meaning<<endl;
        asce(temp->right);
    }
}
void Dict::dece(node *temp){
    if(temp != NULL){
        dece(temp->right);
        cout<<temp->word<<"-"<<temp->meaning<<endl;
        dece(temp->left);
    }
}
void Dict::modify(node *root, string key)
{
	if(key.compare(root->word)<0)
	{
	        if(root->left == NULL) 
	            cout<<"Word not found"<<endl;
	        else 
	            modify(root->left, key);
	}
	else if(key.compare(root->word)>0)
	{
	    if(root->right == NULL) 
	        cout<<"Word not found"<<endl;
	    else 
	        modify(root->right, key);
	}
	else
	{
		cout<<"Meaning - "<<root->meaning<<endl;
		// getline(cin, root->meaning);
		cout<<"Enter new meaning: ";
        cin>>root->meaning;
		// getline(cin, root->meaning);
	}
}
node* Dict::minValue(node *root)
{
	node *curr;
	curr = new node;
	curr = root;
	while(curr->left != NULL)
		curr = curr->left;
	return curr;
}
node* Dict::delnode(node *root, string key)
{
	if(root == NULL) return root;
	node *temp;
	temp = new node;
	if(key.compare(root->word)<0)
    {
        if(root->left == NULL)
            cout<<"Word not found"<<endl;
        else
            root->left = delnode(root->left, key);
    }
	else if(key.compare(root->word)>0)
    {
        if(root->right == NULL)
            cout<<"Word not found"<<endl;
        else
            root->right = delnode(root->right, key);
    }
	else
	{
		if(root->left == NULL)
		{
			temp = root->right;
			delete(root);
			return temp;
		}
		if(root->right == NULL)
		{
			temp = root->left;
			delete(root);
			return temp;
		}
		temp = minValue(root->right);
		root->word = temp->word;
		root->meaning = temp->meaning;
		root->right = delnode(root->right, temp->word);
	}
	return root;
}
int main(){
    Dict D;
    string key;
    char ch;
    int n;
    X:
    D.create();
    cout<<"Do you want to continue(y/n) - ";
    cin>>ch;
    if (ch == 'y') goto X;

    while (1){
        cout<<"\n1. Enter a word";
        cout<<"\n2. Ascending order";
        cout<<"\n3. Descending order";
        cout<<"\n4. Modify";
        cout<<"\n5. Delete";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice - ";
        cin>>n;
        switch (n)
        {
        case 1: D.create();
            break;
        case 2: cout<<"\nAscending order - "<<endl;
            D.asce(D.root);
            break;
        case 3: cout<<"\nDescending order - "<<endl;
            D.dece(D.root);
            break;
        case 4: cout<<"\nEnter a word to modify - ";
            cin>>key;
            D.modify(D.root, key);
            break;
        case 5: cout<<"\nEnter a word to delete - ";
            cin>>key;
            D.root = D.delnode(D.root, key);
            break;
        case 6:  exit(1);
        default: cout<<"\nInvalid choice !";
            break;
        }
    }
    
}