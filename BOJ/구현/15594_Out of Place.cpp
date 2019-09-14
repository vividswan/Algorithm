#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
vector<int> a;
vector<int> b;
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int go;
		scanf("%d", &go);
		a.push_back(go);
		b.push_back(go);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) ans++;
	}
	printf("%d\n", ans - 1);
}