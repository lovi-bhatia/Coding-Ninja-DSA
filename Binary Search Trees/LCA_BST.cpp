#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root, int a, int b){
    if(!root || root->data == a || root->data == b)
        return root;
    
    if(root->data<a && root->data<b)
        return helper(root->right,a,b);
    if(root->data>a && root->data>b)
        return helper(root->left,a,b);

    BinaryTreeNode<int>* leftLCA = helper(root->left,a,b);
    BinaryTreeNode<int>* rightLCA = helper(root->right,a,b);

    if(leftLCA && rightLCA)
        return root;
    if(leftLCA)
        return leftLCA;
    return rightLCA;
}
int getLCA(BinaryTreeNode<int>* root , int a , int b){
    BinaryTreeNode<int>* node = helper(root,a,b);

    return (node==NULL) ? -1 : node->data;
}
BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
    
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}