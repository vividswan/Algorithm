#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> adj;
int s, n, m;
int change[1001];
int bef[1001];
int aft[1001];
int now_pm;
int pre = 1;
int now_len = 2;
int n_res, m_res;
int main(void) {
	scanf("%d%d%d", &s, &n, &m);
	adj.resize(s + 1);
	for (int i = 1; i <= s; i++) scanf("%d", &adj[i]);
	if (adj[1] > adj[2]) now_pm = -1;
	else now_pm = 1;
	for (int i = 2; i < s; i++) {
		int curr = 0;
		if (adj[i] > adj[i + 1]) curr = -1;
		else curr = 1;
		if (curr != now_pm) {
			change[i] = 1;
			if (curr == 1) {
				aft[pre] = -now_len;
				bef[i] = -now_len;
			}
			else {
				aft[pre] = now_len;
				bef[i] = now_len;
			}
			now_len = 1;
			pre = i;
		}
		now_pm = curr;
		now_len++;
	}
	int fin_curr;
	if (adj[s - 2] > adj[s - 1]) fin_curr = -1;
	else fin_curr = 1;
	if (fin_curr == now_pm) {
		aft[pre] = now_pm * (now_len);
	}
	else aft[pre] = now_pm * (2);
	for (int i = 1; i <= s; i++) {
		if (change[i]) {
			if (aft[i] > 0) {
				if (abs(aft[i]) >= m && abs(bef[i]) >= m) m_res++;
			}
			else if (aft[i] < 0) {
				if (abs(aft[i]) >= n && abs(bef[i]) >= n) n_res++;
			}
		}
	}
	printf("%d %d\n", n_res, m_res);
	return 0;
}