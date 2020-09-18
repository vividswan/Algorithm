#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> dp;
int main(void){
    cin >> n;
    dp.resize(n+1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout << dp[n]<<'\n';
    return 0;
}
