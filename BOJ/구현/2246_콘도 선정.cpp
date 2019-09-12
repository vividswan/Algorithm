#include <iostream>
#include <vector>
using namespace std;
int n, res;
vector<vector<pair<int, int>>> cond;
int main(void) {
	cin >> n;
	cond.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		cond[i].push_back({ a,b });
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int x_d = cond[i][0].first;
			int x_c = cond[i][0].second;
			int j_d = cond[j][0].first;
			int j_c = cond[j][0].second;
			if (j_d < x_d) {
				if (j_c <= x_c) cnt++;
			}
			if (x_c > j_c) {
				if (x_d >= j_d) cnt++;
			}
			;
		}
		if (!cnt) res++;
		cnt = 0;
	}
	cout << res << '\n';
	return 0;
}