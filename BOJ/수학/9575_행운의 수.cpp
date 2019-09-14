#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int a[51], b[51], c[51];
int vis[90001];
int main(void) {
	int roof;
	scanf("%d", &roof);
	for (int aa = 1; aa <= roof; aa++) {
		int res_cnt = 0;
		int acnt;
		scanf("%d", &acnt);
		for (int i = 1; i <= acnt; i++) {
			scanf("%d", &a[i]);
		}
		int bcnt;
		scanf("%d", &bcnt);
		for (int i = 1; i <= bcnt; i++) {
			scanf("%d", &b[i]);
		}
		int ccnt;
		scanf("%d", &ccnt);
		for (int i = 1; i <= ccnt; i++) {
			scanf("%d", &c[i]);
		}
		for (int i = 1; i <= acnt; i++) {
			for (int j = 1; j <= bcnt; j++) {
				for (int k = 1; k <= ccnt; k++) {
					int res = a[i] + b[j] + c[k];
					char buf[10];
					sprintf(buf, "%d", res);
					int len = strlen(buf);
					int sn = 0;
					for (int i = 0; i < len; i++) {
						if (buf[i] == '5' || buf[i] == '8') continue;
						else sn++;
					}
					if (!sn && !vis[res]) {
						vis[res]++;
						res_cnt++;
					}
				}
			}
		}
		printf("%d\n", res_cnt);
		res_cnt = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(vis, 0, sizeof(vis));
	}
}