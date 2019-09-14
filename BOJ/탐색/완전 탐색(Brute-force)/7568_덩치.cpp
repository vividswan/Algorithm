#include <iostream>
#include <vector>
using namespace std;
vector <pair<int, int>> inf;
int n, lank[51];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		inf.push_back(make_pair(x, y));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (inf[j - 1].first > inf[i - 1].first && inf[j - 1].second > inf[i - 1].second) {
				lank[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", lank[i] + 1);
	}
}