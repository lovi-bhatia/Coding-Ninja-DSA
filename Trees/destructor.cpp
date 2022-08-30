#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
void printLevelWise(TreeNode<int>* root) {
    if(root==NULL)
        return;

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        //loop for children node
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
            if(i==front->children.size()-1)
                cout<<front->children[i]->data;
            else
                cout<<front->children[i]->data<<",";
        }
        cout<<endl;
    }
}

int numNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

int sumNodes(TreeNode<int>* root){
    if(root==NULL)
        return 0;
    int sum = 0;
    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        sum+=front->data;

        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return sum;
}

void printAtLevelK(TreeNode<int>* root,int k){
    if(k==0){
        cout<<root->data<<endl;
        return;
    }

    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}

int getLeafNodeCount(TreeNode<int>* root) {

    int count = 0;
    if(root==NULL)
        return 0;

    if(root->children.size()==0)
        count++;

    for(int i=0;i<root->children.size();i++){
        count+=getLeafNodeCount(root->children[i]);
    }

    return count;
}

void preOrder(TreeNode<int>* root){

    // edge case
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int>* root){

    // edge case
    if(root==NULL)
        return;

    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void deleteTree(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);

    // by function
    deleteTree(root);

    // Class Destructor 
    delete root;
} 