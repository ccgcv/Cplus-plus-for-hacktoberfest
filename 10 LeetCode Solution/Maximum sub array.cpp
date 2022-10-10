class Solution {
public:
 int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        int n = nums.size(), i=0;
        
        while(i<n){
            currSum += nums[i];
            maxSum = max(maxSum,currSum);
            
            if(currSum < 0){
                currSum = 0;
            }   
            i++;
        }
        return maxSum;
    }
};