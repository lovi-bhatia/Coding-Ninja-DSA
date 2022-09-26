#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
   public:
    BST() { 
        // Implement the Constructor
        root=NULL;
    }
    ~BST(){
        delete root;
    }

	/*----------------- Public Functions of BST -----------------*/
    private:
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data){
        if(node==NULL)
            return NULL;
        if(data<node->data){
            node->left = remove(node->left,data);
            return node;
        }else if(data>node->data){
            node->right = remove(root->right,data);
            return node;
        }else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left == NULL){
                BinaryTreeNode<int>* temp = root->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(!node->right){
                BinaryTreeNode<int>* temp = node->left;
                root->left = NULL;
                delete node;
                return temp;
            }
            else{
                // BinaryTreeNode<int>* maxNode = root->left;

                // while(root->right){
                //     maxNode = maxNode->right;
                // }

                // int leftMax = maxNode->data;
                // root->data = leftMax;
                // root->left = remove(root->left, leftMax);
                // return root; 

                BinaryTreeNode<int>* minNode = node->right;

                while(minNode->left!=NULL){
                    minNode= minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(node->right,rightMin);
                return node;
            }
        }
    }
    public:
    void remove(int data) { 
        // Implement the remove() function 
        this->root = remove(this->root,data);
    }

    private:
    void print(BinaryTreeNode<int>* node){
        if(!node)
            return;
        
        cout<<node->data<<":";
        if(node->left)
            cout<<"L:"<<node->left->data<<",";
        if(node->right)
            cout<<"R:"<<node->right->data;
        
        cout<<endl;

        print(node->left);
        print(node->right);
    }
    public:
    void print() { 
        // Implement the print() function
        print(root);
    }
    private:
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data){
        if(!node){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data<=node->data)
            node->left = insert(node->left,data);
        else
            node->right = insert(node->right,data);
        return node;
    }   
    public:
    void insert(int data) { 
        // Implement the insert() function 
        this->root = insert(this->root,data);
    }

    private:
    bool search(BinaryTreeNode<int>* node,int data){
        if(node==NULL)
            return false;
        
        if(node->data==data)
            return true;
        else if(data < node->data){
            return search(node->left,data);
        }
        return search(node->right,data);
        
    }
    public:
    bool search(int data) {
		// Implement the search() function 
        return search(root,data);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}