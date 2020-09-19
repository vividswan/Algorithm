#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> dp;
int main(void){
    cin >> n;
    dp.resize(n+2);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout << dp[n+1] << '\n';
    return 0;
}
