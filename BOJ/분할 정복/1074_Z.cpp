#include <iostream>
#include <cmath>
using namespace std;
long long res;
int n, r, c, ns;
void go(int st_y, int st_x, int ed_y, int ed_x);
int main(void) {
	scanf("%d %d %d", &n, &r, &c);
	r++;
	c++;
	ns = pow(2, n);
	go(1, 1, ns, ns);
	printf("%lld\n", res);
	return 0;
}
void go(int st_y, int st_x, int ed_y, int ed_x) {
	if (st_y == ed_y) return;
	int len = (ed_y - st_y + 1) / 2;
	if (st_y <= r && r <= st_y + len - 1 && st_x <= c && c <= st_x + len - 1) {
		go(st_y, st_x, st_y + len - 1, st_x + len - 1);
		return;
	}
	else res += len * len;
	if (st_y <= r && r <= st_y + len - 1 && st_x + len <= c && c <= ed_x) {
		go(st_y, st_x + len, st_y + len - 1, ed_x);
		return;
	}
	else res += len * len;
	if (st_y + len <= r && r <= ed_y && st_x <= c && c <= st_x + len - 1) {
		go(st_y + len, st_x, ed_y, st_x + len - 1);
		return;
	}
	else res += len * len;
	go(st_y + len, st_x + len, ed_y, ed_x);
	return;
}