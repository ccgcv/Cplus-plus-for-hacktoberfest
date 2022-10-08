class Solution {
public:
    int target;
    int dp[101][40][101];
    int rec(int idx,int last,int curr,vector<vector<int>> &cost,vector<int> &ar){
        if(idx>=ar.size()) return curr==target?0:1e9;
        if(dp[idx][last+1][curr]!=-1) return dp[idx][last+1][curr];
        if(ar[idx]==0){
            int ans = INT_MAX;
            for(int i=0;i<cost[idx].size();i++)
                ans = min(ans,cost[idx][i] + rec(idx+1,i,curr+(last!=i),cost,ar));
            return dp[idx][last+1][curr] = ans;
        }
        int ans = rec(idx+1,ar[idx]-1,curr + (last!=ar[idx]-1),cost,ar); 
        //cout<<idx<<" "<<last<<" "<<curr<<" "<<ans<<endl;
        return dp[idx][last+1][curr] = ans;
    }
    int minCost(vector<int>& ar, vector<vector<int>>& cost, int m, int n, int t) {
        target =t;
        memset(dp,-1,sizeof(dp));
        int ans =rec(0,-1,0,cost,ar);
        return ans>=(1e9)?-1:ans;
    }
};
