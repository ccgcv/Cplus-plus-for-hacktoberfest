class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto c : words){
            if(F(c) == F(pattern)) ans.push_back(c);
        }
        return ans;
    }
    
    vector<int> F(string s){
        unordered_map<char, int> m;
        vector<int> v;
        int ind=1;
        for(auto c : s){
            if(m.find(c) == m.end()){
                m[c] = ind++;
                v.push_back(m[c]);
            }else{
                v.push_back(m[c]);
            }
        }
        return v;
    }
};