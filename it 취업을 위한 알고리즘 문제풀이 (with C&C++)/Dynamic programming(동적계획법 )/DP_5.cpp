#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> arr;
vector<int> dp;
int main(void){
    cin >> n;
    arr.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    fill(dp.begin(),dp.end(),1);
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                if(dp[i]<dp[j]+1) dp[i]=dp[j]+1;
            }
        }
    }
    int result = 0;
    for(int i=1;i<=n;i++){
        if(result<dp[i]) result = dp[i];
    }
    cout << result << '\n';
    return 0;
}
