#include <iostream>
#include <cstring>
char str[101][51];
int vis[101][51],n,cnt;
using namespace std;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str[i]);
		int now = '0'-1;
		int len = strlen(str[i]);
		for (int j = 0; j < len; j++) {
			if (vis[i][j]) continue;
			vis[i][j] = 1;
			now++;
			for (int k = j + 1; k < len; k++) {
				if (str[i][j] == str[i][k]) {
					vis[i][k] = 1;
					str[i][k] = now;

				}
			}
			str[i][j] = now;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (strcmp(str[i], str[j]) == 0) cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}