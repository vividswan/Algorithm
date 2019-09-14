#include <iostream>
#include <queue>
using namespace std;
int n, m, ctp, han, k;
int arr[100001], par[100001], vis[100001];
priority_queue<int> pq;
int find(int u) {
	if (par[u] == u) return u;
	return par[u] = find(par[u]);
}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (arr[u] >= arr[v]) { // u가 더 큰 경우
		arr[u] += arr[v];
		par[v] = u;
	}
	else {
		arr[v] += arr[u]; // v가 더 큰 경우
		par[u] = v;
	}
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		arr[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		uni(a, b);
	}
	scanf("%d %d %d", &ctp, &han, &k);
	int top_ctp = find(ctp);
	int top_han = find(han);
	for (int i = 1; i <= n; i++) {
		int top_i = find(i);
		if (top_i != top_ctp && top_i != top_han && vis[top_i] == 0) {
			vis[top_i] = 1;
			pq.push(arr[top_i]);
		}
	}
	for (int i = 1; i <= k; i++) {
		if (!pq.empty()) {
			arr[top_ctp] += pq.top();
			pq.pop();
		}
		else break;
	}
	printf("%d\n", arr[top_ctp]);
}