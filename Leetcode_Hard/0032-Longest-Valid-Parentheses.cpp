class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> isValid(n,0);
        stack<pair<char,int>> st;
        for(int i=0 ; i<n ; i++)
        {
            if(s[i]=='(') st.push({s[i], i});
            else
            {
                if(!st.empty())
                {
                    isValid[i] = true;
                    isValid[st.top().second] = true;
                    st.pop();
                }
            }
        }
        int ans=0;
        int curr=0;
        int maxStart=-1, maxEnd=-1;
        int currStart=-1, currEnd=-1;
        for(int i=0 ; i<n ; i++)
        {
            if(isValid[i])
            {
                if(i==0) currStart = i;
                else if(isValid[i-1]==0) currStart = i;
                currEnd = i;
                curr++;
            }
            else curr=0;
            if(curr>ans)
            {
                maxStart = currStart+1;
                maxEnd = currEnd+1;
                ans = curr; 
            }
            
        }
        cout<<ans<<endl;
        cout<<maxStart<<' '<<maxEnd<<endl;
        return ans;
    }
};
