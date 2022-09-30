#include <iostream>
#include <stdexcept>
using namespace std;
int toh (int n,char source,char mediatator,char destination){
    if(n==1){
        cout<<source<<"-->"<<destination<<endl;
    }
    else{
        toh(n-1,source,destination,mediatator);
          cout<<source<<"-->"<<destination<<endl;
          toh(n-1,mediatator,source,destination);
    }
    return 0;
}
int main(){
    int n{};
    cin>>n;
    char s{'S'},d{'D'},m{'M'};
    cout<<toh(n,s,m,d);

    return 0;
}
