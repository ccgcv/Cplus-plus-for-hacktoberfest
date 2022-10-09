class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0],count=1;
         for(int i=1;i<nums.size();i++){
             if(nums[i]==prev){
                 nums[i]=500;
             }
             else{
                 prev = nums[i];
                 count++;
             }
         }
        sort(nums.begin(),nums.end());
        return count;
    }
};
