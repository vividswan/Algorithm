#include <iostream>
#include <cstring>
using namespace std;
int roof, vis[55], cnt;
char str[51][51];
int main(void) {
	cin >> roof;
	getchar();
	for (int i = 1; i <= roof; i++) {
		cin.getline(str[i], 51);
	}
	for (int i = 1; i <= roof; i++) {
		if (vis[i] != 0) continue;
		vis[i]++;
		int swc = 0;
		for (int j = i + 1; j <= roof; j++) {
			if (vis[j] != 0) continue;
			if (strlen(str[i]) != strlen(str[j])) continue;
			char str_check[51], str_check_sec[51];
			strcpy(str_check_sec, str[i]);
			int now = strlen(str[i]);
			while (1) {
				for (int k = 0; k < now - 1; k++) str_check[k] = str_check_sec[k + 1];
				str_check[now - 1] = str_check_sec[0];
				str_check[now] = '\0';
				if (!strcmp(str_check, str[j])) {
					vis[j]++;
					swc++;
					break;
				}
				if (!strcmp(str_check, str[i])) {
					break;
				}
				strcpy(str_check_sec, str_check);
			}
		}
		cnt++;
	}
	cout << cnt;
}