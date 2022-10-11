/* PROBLEM STATEMENT :-
   
   Given a string s, find the length of the longest substring without repeating characters.
                    Input: s = "abcabcbb"
                      Output: 3

*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            //sliding windows technique
    //we will store no. of occurace of char and if it is greater than one then  remove it
      // 1.coun[s[j]++] and check if count[s[j]++]>1 then remove it
      //2.ans=max(ans,j-i+1)  i and j are windows and 1 for its index
      //3.increment j++
                  //while count[s[j]]>1
      //1.count[s[j]]--;
     //2.increment i++
        vector<int>cnt(256 ,0); //starting value 0
        int start=0;
        int end=0;
        int ans=0; //to store final ans
        while(end<s.size()){
             cnt[s[end]]++; //at starting storing no occrurance into cnt vector
            while(cnt[s[end]]>1){
                 cnt[s[start]]--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
