#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>>adj;
int n, vis[27];
void pre(int idx);
void mid(int idx);
void end(int idx);
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		adj[a - 'A' + 1].push_back(b - 'A' + 1);
		adj[a - 'A' + 1].push_back(c - 'A' + 1);
	}
	pre(1);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	mid(1);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	end(1);
}
void pre(int idx) {
	printf("%c", idx + 'A' - 1);
	if (vis[adj[idx][0]] == 0 && adj[idx][0] != '.' - 'A' + 1) pre(adj[idx][0]);
	if (vis[adj[idx][1]] == 0 && adj[idx][1] != '.' - 'A' + 1) pre(adj[idx][1]);
	vis[idx] = 1;
}
void mid(int idx) {
	if (vis[adj[idx][0]] == 0 && adj[idx][0] != '.' - 'A' + 1) mid(adj[idx][0]);
	printf("%c", idx + 'A' - 1);
	if (vis[adj[idx][1]] == 0 && adj[idx][1] != '.' - 'A' + 1) mid(adj[idx][1]);
	vis[idx] = 1;
}
void end(int idx) {
	if (vis[adj[idx][0]] == 0 && adj[idx][0] != '.' - 'A' + 1) end(adj[idx][0]);
	if (vis[adj[idx][1]] == 0 && adj[idx][1] != '.' - 'A' + 1) end(adj[idx][1]);
	printf("%c", idx + 'A' - 1);
	vis[idx] = 1;
}