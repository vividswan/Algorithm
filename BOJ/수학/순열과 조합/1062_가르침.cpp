#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int chk[27], n, k, res;
string s[51];
void dfs(int idx, int cnt, int k);
int main(void) {
	cin >> n >> k;
	if (k < 5) {
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	chk['a' - 'a'] = 1;
	chk['n' - 'a'] = 1;
	chk['t' - 'a'] = 1;
	chk['i' - 'a'] = 1;
	chk['c' - 'a'] = 1;
	k -= 5;
	dfs(0, 0, k);
	printf("%d", res);
}
void dfs(int idx, int cnt, int k) {
	if (cnt == k) {
		int go = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < s[i].size(); j++) {
				if (chk[s[i][j] - 'a']) go++;
			}
			if (go == s[i].size()) ans++;
			go = 0;
		}
		res = max(res, ans);
	}
	for (int i = idx; i < 26; i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		dfs(i, cnt + 1, k);
		chk[i] = 0;
	}
}