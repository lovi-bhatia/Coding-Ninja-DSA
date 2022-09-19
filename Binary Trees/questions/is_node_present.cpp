template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(!root)
        return false;
    if(root->data == x)
        return true;
    
    bool ans = false;
    
    if(!ans)
        ans = isNodePresent(root->left,x);
    if(!ans)
        ans = isNodePresent(root->right,x);
    
    return ans;
}