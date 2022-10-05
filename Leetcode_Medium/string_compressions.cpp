class Solution {
public:
    int compress(vector<char>& chars) {
        char c = chars[0];
        int cnt=0,k=0,n=chars.size();
        for(int i=0 ; i<=n ; i++){
            if(i!=n && chars[i]==c){
                cnt++;
            }
            else{
                if(cnt==1){
                    chars.push_back(c);
                }
                else{
                    chars.push_back(c);
                    vector<int> v;
                    while(cnt>0){
                        v.push_back(cnt%10);
                        cnt/=10;
                    }
                    int j=v.size()-1;
                    while(j>=0){
                        char a = '0' + v[j];
                        chars.push_back(a);
                        j--;
                    }
                }
                c=chars[i];
                cnt=1;
            }
        }
        chars.erase(chars.begin(),chars.begin()+n);
        return chars.size();
    }
};
