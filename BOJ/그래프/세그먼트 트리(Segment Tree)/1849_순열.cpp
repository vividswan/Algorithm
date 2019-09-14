#include <iostream>
#include <vector>
using namespace std;
vector <int> seg;
int query(int num, int index);
void update(int index, int val);
int n, arr[100001], h = 1;
int main(void) {
	scanf("%d", &n);
	while (n > h) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		update(i, 1);
	}
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int res = query(x + 1, 1);
		update(res, 0);
		arr[res] = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}
}
void update(int index, int val) {
	index += h - 1;
	seg[index] = val;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
	return;
}
int query(int num, int index) {
	if (index > h - 1) return index - h + 1;
	if (num <= seg[index * 2]) return query(num, index * 2);
	else return query(num - seg[index * 2], index * 2 + 1);
}