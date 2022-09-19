#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data){
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode(){
		delete left;
		delete right;
	}
};

void PrintTree(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;

	cout<<root->data<<" : ";
	if(root->left!=NULL){
		cout<<"L "<<root->left->data;
	}
	if(root->right!=NULL){
		cout<<" R "<<root->right->data;
	}
	cout<<endl;
	PrintTree(root->left);
	PrintTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
	int rootData;
	// cout<<"Enter root Data: ";
	cin>>rootData;
	if(rootData==-1)
		return NULL;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* righttChild = takeInput();

	root->left = leftChild;
	root->right = righttChild;

	return root;
}

// BinaryTreeNode<int>* takeInputLevelWise(){
// 	int rootData;
// 	// cout<<"Enter root Data";
// 	cin>>rootData;
// 	if(rootData==-1)
// 		return NULL;

// 	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

// 	queue<BinaryTreeNode<int>*> pendingNodes;

// 	pendingNodes.push(root);

// 	while(pendingNodes.size()!=0){
// 		BinaryTreeNode<int>* front = pendingNodes.front();
// 		pendingNodes.pop();
// 		// cout<<"Enter left data";
// 		int leftChildData;
// 		cin>>leftChildData;
// 		if (leftChildData!=-1)
// 		{
// 			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
// 			front->left = child;
// 			pendingNodes.push(child);
// 		}

// 		// cout<<"Enter right data";
// 		int rightChildData;
// 		cin>>rightChildData;
// 		if (rightChildData!=-1)
// 		{
// 			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
// 			front->right = child;
// 			pendingNodes.push(child);
// 		}
// 	}
// 	return root;
// }

int main(){

	// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

	// root->left = node1;
	// root->right = node2;

	BinaryTreeNode<int>* root = takeInput();
	BinaryTreeNode<int>* root = takeInputLevelWise();

	PrintTree(root);
	delete root;
}