class Solution {
public:
    int climbStairs(int n) {
    vector<int> dp(n+1);
        int prev=1;
        int now=1;
        int ans=0;
        if(n==1) return 1;
        
        //cout<<dp[0]<<" "<<dp[1]<<" ";
        for (int i=2; i<n+1 ; i++)
        {
            ans=now+prev;
            prev=now;
            now=ans;
         //   cout<<dp[i]<<" ";
        }
       return ans;
    }
};

