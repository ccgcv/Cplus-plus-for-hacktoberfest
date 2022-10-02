int traversal(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int opt1 = traversal(root->left);
        int opt2 = traversal(root->right);
        
        int ans = max(opt1,opt2) + 1;
        return ans;
        
    }
    int maxDepth(TreeNode* root) {
        
        int ans = traversal(root);
        return ans;
    }
