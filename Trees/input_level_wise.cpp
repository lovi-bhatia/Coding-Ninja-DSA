#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode{
public:
	int data;
	// childrens will automatically of type T
	vector<TreeNode<T>* > children; 

	TreeNode(T data){
		this->data = data;
	}
};

TreeNode<int>* takeInputLevelWise(){
	int rootData; 
	// cout<<"Enter rootData: ";
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);

	while(pendingNodes.size()!=0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		// cout<<"Enter number of childrens of "<<front->data<<endl;
		int numChild;
		
		cin>>numChild;
		for(int i=0;i<numChild;i++){
			int childData;
			// cout<<"Enter "<<i<<" child of "<<front->data<<endl;
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}

	}
	return root;
}

TreeNode<int>* takeInput(){
	int rootData; 
	// cout<<"Enter rootData: ";
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	// cout<<"Enter Number of nodes: ";
	cin>>n;

	for(int i=0;i<n;i++){
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root){
	// Edge Case
	if(root==NULL)
		return;

	cout<<root->data<<" : ";
	for(int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printTree(root->children[i]);
	}

}

int main(){
	// TreeNode<int>* root = new TreeNode(1);
	// TreeNode<int>* node1 = new TreeNode(2);
	// TreeNode<int>* node2 = new TreeNode(3);

	// root->children.push_back(node1);
	// root->children.push_back(node2);

	TreeNode<int>* root = takeInput();
	// TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
}


// 			1
// 		2 			3	4
// 	5		6		7	8