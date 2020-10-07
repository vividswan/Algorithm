#include <iostream>
#include <algorithm>
using namespace std;
int n, result;
int dp[3][1001];
int val[1001];
int main(void){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> val[i];
        dp[0][i]=1;
        dp[1][i]=1;
        dp[2][i]=1;
    }
    for(int i=1; i<=n;i++){
        for(int j=1; j<i;j++){
            if(val[j]<val[i]){
                dp[0][i]= max(dp[0][i], dp[0][j]+1 );
            }
            if(val[j]>val[i]){
                dp[2][i] = max(dp[2][i],dp[2][j]+1);
                dp[1][i] = max(dp[1][i],dp[0][j]+1);
                dp[1][i] = max(dp[1][i],dp[1][j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1; j<3;j++){
            result = max(result,dp[j][i]);
        }
    }
    cout << result << '\n';
    return 0;
}
