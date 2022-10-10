class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0, j = s.size()-1;
        
        while( i<j ){
            
//             these conditions are used to skip the non alphanumeric characters like spaces and special characters
            while( i < j && !isalnum(s[i])){
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }
            
            if(tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }
        
        return true;
        
    }
};