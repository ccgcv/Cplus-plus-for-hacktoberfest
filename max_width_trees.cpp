class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        // vector <int> a;
        while(!q.empty()){
            int size = q.size();
            int min = q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                
                long cur_id =q.front().second-min;
                TreeNode * node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i==size-1) last=cur_id;
                
                if(node->left)
                    q.push({node->left,cur_id*2+1});
                    if(node->right)
                        q.push({node->right,cur_id*2+2});
                        
                    
                
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};
