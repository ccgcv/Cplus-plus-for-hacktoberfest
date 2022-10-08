class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        vector<vector<int>> first(16),second(16);
        int n=nums.size()/2;
        vector<int> a,b;
        int tot =0;
        for(int i=0;i<2*n;i++){
            if(i<n) a.push_back(nums[i]);
            else b.push_back(nums[i]);
            tot+=nums[i];
        }
        for(int i=0;i<(1<<n);i++){
            int curr =0;
            for(int j=0;j<n;j++){
                if((i>>j)&1) curr+=a[j]; 
            }
            first[__builtin_popcount(i)].push_back(curr);
        }
        for(int i=0;i<(1<<n);i++){
            int curr =0;
            for(int j=0;j<n;j++){
                if((i>>j)&1) curr+=b[j]; 
            }
            second[__builtin_popcount(i)].push_back(curr);
        }
        for(int i=0;i<=15;i++){
            sort(first[i].begin(),first[i].end());
            sort(second[i].begin(),second[i].end());
        }
        int ans = INT_MAX;
        for(int k=0;k<=n;k++){
            int i=0,j=second[n-k].size()-1;
            while(i<first[k].size() and j>=0){
                int curr = first[k][i] + second[n-k][j];
                ans=min(ans,abs(tot - 2*curr));
                if(2*curr > tot)  j--;
                else i++;
            }
        }
        return ans;
    }
};
