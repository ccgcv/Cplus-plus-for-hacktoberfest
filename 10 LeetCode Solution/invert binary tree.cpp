/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(TreeNode* &root){
        if(root == NULL)
            return NULL;
        
        TreeNode* leftAns = solve(root->left);
        TreeNode* rightAns = solve(root->right);
        
        root->left = rightAns;
        root->right = leftAns;
        return root;
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* ans = solve(root);
        return ans;
    }
};