#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int arr[1001];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> dp[i];
        arr[i]=dp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dp[i]<dp[j]){
                if(dp[j] < dp[i]+arr[j]){
                    dp[j] = dp[i]+arr[j];
                }
            }
        }
    }
    int result = 0;
    for(int i=0;i<n;i++){
        result = max(result,dp[i]);
    }
    cout << result << '\n';
}
