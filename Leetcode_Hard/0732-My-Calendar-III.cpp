class MyCalendarThree {
private:
    map<int,int> delta;
public:
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        delta[start]++;
        delta[end]--;
        int ans=0;
        int curr=0;
        for(auto [x, y] : delta)
        {
            curr += y;
            ans = max(ans, curr);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
