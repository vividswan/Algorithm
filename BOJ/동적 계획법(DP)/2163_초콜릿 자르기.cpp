#include <iostream>
#include <cstring>
using namespace std;
int dp[90001];
int n, m, result;
int recursion(int size){
    int &ret = dp[size];
    if(ret!=-1) return dp[size];
    if(size%2==0) return ret = 1+ 2*recursion(size/2);
    return ret= 2+ 2*recursion(size/2) ;
}
int main(){
    memset(dp,-1,sizeof(dp));
    dp[2]=1;
    dp[1]=0;
    cin >> n >> m;
    result = recursion(n*m);
    cout << result << '\n';
    return 0;
}
