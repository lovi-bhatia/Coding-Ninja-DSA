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

// Input Function
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
	printTree(root);
}


// 			1
// 		2 			3	4
// 	5		6		7	8



// 1
// 3
// 2
// 2
// 5
// 0
// 6
// 0
// 3
// 1
// 7
// 0
// 4
// 1
// 8
// 0