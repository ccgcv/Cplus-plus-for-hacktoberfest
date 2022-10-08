class Solution
{
public:
    int dp[4005];
    int minMoves(int idx, string &s)
    {
        if (dp[idx] != -1)
            return dp[idx];
        int n = s.size();
        string str;
        for (int i = idx; i < n; i++)
            str.push_back(s[i]);
        vector<int> pi(str.size());
        pi[0] = 0;
        int ans = 1;
        for (int i = 1; i < str.size(); i++)
        {
            int j = pi[i - 1];
            while (str[i] != str[j] && j > 0)
                j = pi[j - 1];
            if (str[i] == str[j])
                j++;
            pi[i] = j;
            if (j * 2 == i + 1)
                ans = max(ans, 1 + minMoves(idx + j, s));
        }
        return dp[idx] = ans;
    }
    int deleteString(string s)
    {
        memset(dp, -1, sizeof(dp));
        int ans = minMoves(0, s);
        return ans;
    }
};
