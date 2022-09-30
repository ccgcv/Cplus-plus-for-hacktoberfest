class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res ; 
        
        sort(intervals.begin(),intervals.end());
        vector<int> pair = intervals[0];
        
        for(int i=0;i<intervals.size();i++){    
            
            if(intervals[i][0]<=pair[1]){
                pair[1]=max(intervals[i][1],pair[1]);
            }
            else{
                res.emplace_back(pair);
                pair = intervals[i];
            }
        }
        res.emplace_back(pair);
        return res;
    }
};
