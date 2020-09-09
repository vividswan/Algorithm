#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool swc;
char str[200];
bool vis[101];
int ans[101];
void dfs(int idx, int maxx, int cnt) {
	if (swc) return;
	if (idx == strlen(str)) {
		for (int i = 1; i <= maxx; i++) {
			if (!vis[i]) return;
		}
		for (int i = 1; i <= maxx; i++) cout << ans[i] << ' ';
		swc = true;
		return;
	}
	int num = str[idx] - '0';
	if (num != 0 && !vis[num]) {
		vis[num]=true;
		ans[cnt] = num;
		maxx = max(maxx, num);
		dfs(idx + 1, maxx,cnt+1);
		vis[num] = false;
	}
	if (idx + 1 < strlen(str)) {
		num *= 10;
		num += str[idx + 1] - '0';
		if (num != 0 && !vis[num]) {
			vis[num] = true;
			ans[cnt] = num;
			maxx = max(maxx, num);
			dfs(idx + 2,maxx,cnt+1);
			vis[num] = false;
		}
	}
}
int main(void) {
	cin >> str;
	dfs(0,0,1);
}