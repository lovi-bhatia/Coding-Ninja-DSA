/*
    Time Complexity : O(N)
    Space Complexity : O(N)
	
    Where 'N' is the number of nodes in the given binary tree.
*/
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

int getDiameter(TreeNode<int> *root, int &height)
{
    if (root == NULL)
    {
        // Height and diameter of an empty tree will be 0.
        height = 0;
        return 0;
    }

    // To store the height of left and right subtrees.
    int leftHeight = 0;
    int rightHeight = 0;

    // Recur for left subtree and get the height as well as diameter.
    int leftDiameter = getDiameter(root->left, leftHeight);

    // Recur for right subtree and get the height as well as diameter.
    int rightDiameter = getDiameter(root->right, rightHeight);

    // Update the height of the given binary tree.
    height = max(leftHeight, rightHeight) + 1;

    // Diameter of given binary tree.
    int diameter = max(leftDiameter, max(rightDiameter, leftHeight + rightHeight));

    return diameter;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Initialize a variable to store the height of the of binary tree.
    int height = 0;

    // Recursive function to find diameter.
    return getDiameter(root, height);
}
