class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        
        unordered_map<int, set<int>> map;
        
        for(int i=0;i<n;i++) map[stones[i]]={};
        
        map[0].insert(1);
        
        for(int i=0;i<n;i++){
            int currstone = stones[i];
            
            set<int> st = map[currstone];
            
            for(auto x : st){
                int pos = currstone + x;
                
                if(pos==stones[stones.size()-1]) return true;
                
                if(map.find(pos)!=map.end()){
                    if(x-1>0)
                        map[pos].insert(x-1);
                    
                    map[pos].insert(x);
                    map[pos].insert(x+1); 
                }
            }
        }
      
        return false;
    }
};
