#include <iostream>
#include <vector>
using namespace std;
int n, result;
vector<int> arr;
vector<int> dp;
vector<int> reDp;
int main(void){
    cin >> n;
    arr.resize(n+1);
    dp.resize(n+1);
    reDp.resize(n+1);
    for(int i=1;i<=n;i++) cin >> arr[i];
    fill(reDp.begin(),reDp.end(),1);
    fill(dp.begin(),dp.end(),1);
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                if(dp[i]<dp[j]+1) dp[i]=dp[j]+1;
            }
            if(arr[i]<arr[j]){
                if(reDp[i]<reDp[j]+1) reDp[i]=reDp[j]+1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(result < dp[i]) {
            result = dp[i];
        }
        if(result<reDp[i]){
            result = reDp[i];
        }
    }
    cout << result << '\n';
    return 0;
}
