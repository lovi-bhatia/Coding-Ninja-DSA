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
};

using namespace std;
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(!root)
        return;
    
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* rootLeft = root->left;

    root->left = newNode;
    newNode->left = rootLeft;

    insertDuplicateNode(rootLeft);
    insertDuplicateNode(root->right);
}

void insertDuplicateRight(BinaryTreeNode<int>*root){
    if(!root)
        return;
    
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* rightNode = root->right;

    root->right = newNode;
    newNode->right = rightNode;


    insertDuplicateRight(rightNode);
    insertDuplicateRight(root->left);
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

void printLevelATNewLine(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    insertDuplicateNode(root);
    printLevelATNewLine(root);
    cout<<endl;
    insertDuplicateRight(root);
    printLevelATNewLine(root);
    delete root;
}