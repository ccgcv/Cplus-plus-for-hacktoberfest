class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
        int num=0;
        
        for(int i=s.length()-1; i>=0; i--)
        {
            if(i==0)
            {
                if(m[s[i]]<m[s[i+1]])
                  return num;
                else 
                    num+=m[s[i]];
            }
            else if(m[s[i]]<=m[s[i-1]])
                num+=m[s[i]];
            else if(m[s[i]]>m[s[i-1]])
            {
                num+=m[s[i]]-m[s[i-1]];
                i--;
            }
        }
        
        return num;
    }
};
