#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int recursion(int idx);
vector<int>dp;
int n;
int main(void){
    cin >> n;
    dp.resize(n+1);
    fill(dp.begin(),dp.end(),-1);
    int result = recursion(n);
    cout << result << '\n';
    return 0;
}
int recursion(int idx){
    if(idx==1) return 1;
    else if(idx==2) return 2;
    return dp[idx] = recursion(idx-1) + recursion(idx-2);
}
