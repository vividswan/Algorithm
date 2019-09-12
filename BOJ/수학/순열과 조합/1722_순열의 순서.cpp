#include <iostream>
using namespace std;
void go(long long nm);
long long back(void);
int arr[21], vis[21];
long long fact[21];
int nm;
int main(void) {
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 20; i++) {
		fact[i] = i * fact[i - 1];
	}
	cin >> nm;
	int sel;
	cin >> sel;
	if (sel == 1) {
		long long st;
		cin >> st;
		go(st);
	}
	if (sel == 2) {
		for (int i = 0; i < nm; i++) {
			cin >> arr[i];
		}
		cout << back();
	}
}
void go(long long st) {
	for (int i = 0; i < nm; i++) {
		int ser = nm - i - 1;
		if (st <= fact[ser]) {
			for (int j = 1; j <= nm; j++) {
				if (!vis[j]) {
					arr[i] = j;
					vis[j]++;
					break;
				}
			}
			continue;
		}
		else if (st > fact[ser]) {
			int cnt = 0;
			while (st > fact[ser]) {
				st -= fact[ser];
				cnt++;
			}
			for (int j = 1; j <= nm; j++) {
				if (!vis[j]) {
					if (!cnt) {
						arr[i] = j;
						vis[j]++;
						break;
					}
					else if (cnt) {
						cnt--;
						continue;
					}
				}
			}
			continue;
		}
	}
	for (int i = 0; i < nm; i++) {
		printf("%d ", arr[i]);
	}
}
long long back(void) {
	long long res = 1;
	for (int i = 0; i < nm; i++) {
		int ser = nm - i - 1;
		for (int j = 1; j <= nm; j++) {
			if (!vis[j]) {
				if (j != arr[i]) {
					res += fact[ser];
					continue;
				}
				else if (j == arr[i]) {
					vis[j]++;
					break;
				}
			}
		}
	}
	return res;
}