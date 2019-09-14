#include <iostream>
#include <algorithm>
using namespace std;
int roof;
int main(void) {
	scanf("%d", &roof);
	for (int i = 1; i <= roof; i++) {
		double team_win[1001] = { 0, };
		double team_loose[1001] = { 0, };
		double res[1001];
		int team, mat;
		scanf("%d %d", &team, &mat);
		for (int j = 1; j <= mat; j++) {
			int a, b, p, q;
			scanf("%d %d %d %d", &a, &b, &p, &q);
			team_win[a] += p;
			team_loose[a] += q;
			team_win[b] += q;
			team_loose[b] += p;
		}
		for (int j = 1; j <= team; j++) {
			if (!team_win[j] && !team_loose[j]) {
				res[j] = 0;
				continue;
			}
			else {
				res[j] = (team_win[j] * team_win[j]) / (team_win[j] * team_win[j] + team_loose[j] * team_loose[j]);
			}
		}
		double res_max = 0;
		double res_min = 1;
		for (int j = 1; j <= team; j++) {
			res_max = max(res_max, res[j]);
			res_min = min(res_min, res[j]);
		}
		printf("%d\n%d\n", (int)(res_max * 1000), (int)(res_min * 1000));
	}
}