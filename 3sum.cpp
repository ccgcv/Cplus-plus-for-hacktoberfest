class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        if(nums.size()<3)    return triplets;
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)  map[nums[i]] = i;
        
        for(int i = 0;i < nums.size()-2;i++)
        {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1])   continue;
			
            for(int j = i+1;j < nums.size()-1;j++)
            {
                int target = -(nums[i]+nums[j]);
                if(map.count(target) && map.find(target)->second > j)
                {
                    triplets.push_back({nums[i],nums[j],target});
                }
                j = map.find(nums[j])->second;
            }
            i = map.find(nums[i])->second;
            
        }
        return triplets;
    }
};
