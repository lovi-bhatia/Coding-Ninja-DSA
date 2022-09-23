      return true;
    
    if(root->data<min || root->data>max)
        return false;
    
    return helper(root->left,min,root->data) && helper(root->right,max,root->data);
}

bool isBST(BinaryTreeNode<int> *root) {
    return helper(root,INT_MIN,INT_MAX);
}