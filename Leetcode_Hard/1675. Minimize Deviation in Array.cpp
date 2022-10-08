class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> m;
        for(int i :nums) m.insert((i%2? i*2 :i));
        int ans = *m.rbegin() - *m.begin();
        while( *m.rbegin() % 2 ==0){
            int curr = *m.rbegin();
            m.erase(curr);
            m.insert(curr / 2);
            ans = min(ans,*m.rbegin() - *m.begin());
        }
        ans = min(ans,*m.rbegin() - *m.begin());
        return ans;
    }
};
