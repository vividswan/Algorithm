#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int value[1001];
int main(void){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> value[i];
        dp[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(value[j]<value[i]){
                dp[i]= max(dp[i],dp[j]+1);
            }
        }
    }
    int result = 0;
    for(int i=1;i<=n;i++){
        result = max(result, dp[i]);
    }
    cout << result << '\n';
    return 0;
}
