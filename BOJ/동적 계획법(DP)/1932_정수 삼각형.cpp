#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[502][502];
int main(void){
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            int value;
            cin >> value;
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
            dp[i][j]+=value;
        }
    }
    int result = 0;
    for(int i=1;i<=n;i++){
        result = max(result, dp[n][i]);
    }
    cout << result << '\n';
    return 0;
}
