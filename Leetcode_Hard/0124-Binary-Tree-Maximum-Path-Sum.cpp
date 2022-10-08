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
public:
    
    int Sum(TreeNode* root, int &maxi){
        if(root==NULL) return 0;
        
        int left_sum = max(0, Sum(root->left, maxi));
        int right_sum = max(0, Sum(root->right, maxi));
        
        maxi = max(maxi, left_sum + right_sum + root->val);
        
        return root->val + max(left_sum, right_sum);
    }
    
    int maxPathSum(TreeNode* root) {
      
        // maxi variable which will store maximum sum
        int maxi = INT_MIN;
        
        // Call Sum recursive function to calculate maximum path sum 
        Sum(root, maxi);
        
        return maxi;
    }
};
