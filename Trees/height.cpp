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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {

    TreeNode<int> * max = new TreeNode<int>(root->data);

    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* child = maxDataNode(root->children[i]);
        if(child->data>=max->data)
            max = child;
    }
    return max;
}

int getHeight(TreeNode<int>* root){
    if(root==NULL)
        return 0;
    int ans = 0;
    for(int i=0;i<root->children.size();i++){
        int childHeight = getHeight(root->children[i]);
        if(childHeight>ans)
            ans = childHeight;
    }
    return ans+1;

}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);

    cout<<"numNodes: "<<numNodes(root)<<endl;
    cout << "Sum: " << sumNodes(root)<<endl;
   TreeNode<int>* ans = maxDataNode(root);

   if(root!=NULL){
    cout << "Max: "<<ans->data<<endl;
   }

   cout<<"Height: "<<getHeight(root)<<endl;
} 