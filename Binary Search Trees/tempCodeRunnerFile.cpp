TreeNode<int>* minNode = root->right;

                while(minNode->left!=NULL){
                    minNode= minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = remove(root->right,rightMin);
                return root;