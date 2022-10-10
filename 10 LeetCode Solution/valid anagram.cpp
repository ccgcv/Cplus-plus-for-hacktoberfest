class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        
        int sc[26] = {0}; 
        
        for(char ch : s) sc[ch - 'a'] ++;
        
        for(char ch : t) sc[ch - 'a'] --;
        
        for(int num : sc) if(num != 0) return false;
        
        return true;
    }
};