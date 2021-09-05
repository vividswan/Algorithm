#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int testCase;
int dp[3002][2][102][102];

int nArr[3002];
int mArr[102];
int MAX = 100001;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> testCase;
    for (int t = 1; t <= testCase; ++t) {
        int n, m;
        cin >> n;
        for (int i = 2; i <= n + 1; i++) cin >> nArr[i];
        cin >> m;
        for (int i = 2; i <= m + 1; i++) {
            cin >> mArr[i];
            mArr[i] *= -1;
        }
        mArr[0] = -MAX;
        mArr[1] = -MAX;
        sort(mArr, mArr+102);
        mArr[0] = 0;
        mArr[1] = 0;

        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= m + 1; j++) {
                for (int k = 1; k <= m - j + 2; k++) {
                    dp[i][0][j][k] = 0;
                    dp[i][1][j][k] = 0;
                }
            }
        }

        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= m + 1; j++) {
                for (int k = 1; k <= m - j + 2; k++) {
                    dp[i][0][j][k] = max(max(dp[i - 1][0][j][k], dp[i - 1][1][j][k]), max(dp[i][0][j][k - 1], dp[i][1][j][k-1]));
                    dp[i][1][j][k] = max(dp[i - 1][0][j][k] + nArr[i], dp[i][0][j - 1][k] - (mArr[j]));
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= m+1 ; i++) {
            for (int k = 0; k < 2; k++) {
                res = max(res, dp[n+1][k][i][m + 2 - i]);
            }
        }

        printf("#%d %d\n", t, res);
    }
    return 0;
}