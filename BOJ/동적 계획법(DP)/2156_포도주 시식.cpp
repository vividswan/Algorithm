#include <iostream>
using namespace std;
int n;
int value[10001];
int dp[10001][2];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> value[i];
    for(int i =1; i<=n;i++){
        if(i>=2) dp[i][0]=max(dp[i-2][0],dp[i-2][1])+value[i];
        else dp[1][0] = value[i];
        dp[i][1] = max(dp[i-1][0]+value[i],dp[i-1][1]);
    }
    int result = 0;
    for(int i=0;i<2;i++) result = max(result,dp[n][i]);
    cout << result << '\n';
    return 0;
}
