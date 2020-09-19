#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> dp;
int recursion(int idx){
    if(dp[idx]!=-1) return dp[idx];
    if(idx==1) return 1;
    else if(idx == 2) return 2;
    return dp[idx]= recursion(idx-1)+recursion(idx-2);
}
int main(void){
    cin >> n;
    dp.resize(n+1);
    fill(dp.begin(),dp.end(),-1);
    recursion(n);
    cout << dp[n] << '\n';
    return 0;
}
