// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1;
        int high=n;
        int mid;
        int ans=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            bool x = isBadVersion(mid);
            if(x==true){
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};