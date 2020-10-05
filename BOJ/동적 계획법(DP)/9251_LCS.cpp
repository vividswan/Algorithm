#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char str1[1001], str2[1001];
int dp[1001][1001];
int main(void){
    cin >> str1 >> str2;
    for(int i=0; str1[i]!='\0'; i++){
        for(int j=0; str2[j]!='\0'; j++){
            if(str1[i]==str2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else {
                dp[i+1][j+1]= max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    cout << dp[strlen(str1)][strlen(str2)] << '\n';
    return 0;
}
