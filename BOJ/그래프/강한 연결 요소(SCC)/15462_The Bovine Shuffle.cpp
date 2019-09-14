#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, go[100001], res;
int vis[100001];
int fin[100001];

void dfs(int curr) {
	vis[curr] = 1;
	if (!vis[go[curr]]) dfs(go[curr]);
	else if (!fin[go[curr]]) {
		for (int i = go[curr]; i != curr; i = go[i]) res++;
		res++;
	}
	fin[curr] = 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", go + i);
		go[i]--;
	}
	for (int i = 0; i < n; ++i)
		if (!vis[i]) dfs(i);
	printf("%d\n", res);
}