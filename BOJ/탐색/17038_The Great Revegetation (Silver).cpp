#include <iostream>
#include <vector>
using namespace std;
int swc;
int res;
int n, m;
int vis[100001];
vector<vector<int>> sv;
vector<vector<int>> dv;
void visit(int x, int v)
{
	vis[x] = v;
	for (auto n : sv[x]) {
		if (vis[n] == 3 - v) swc++;
		if (vis[n] == 0) visit(n, v);
	}
	for (auto n : dv[x]) {
		if (vis[n] == v) swc++;
		if (vis[n] == 0) visit(n, 3 - v);
	}
}
int main(void) {
	scanf("%d %d", &n, &m);
	sv.resize(n + 1);
	dv.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		char a;
		int b, c;
		scanf(" %c", &a);
		scanf("%d%d", &b, &c);
		if (a == 'S') {
			sv[b].push_back(c);
			sv[c].push_back(b);
		}
		else {
			dv[b].push_back(c);
			dv[c].push_back(b);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			visit(i, 1);
			res++;
		}
	}
	if (swc) {
		printf("%d\n", 0);
	}
	else {
		printf("%d", 1);
		for (int i = 1; i <= res; i++) {
			printf("%d", 0);
		}
		printf("\n");
	}
	return 0;
}