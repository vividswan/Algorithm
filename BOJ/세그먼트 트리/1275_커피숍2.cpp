#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, q, h = 1;
vector <ll> seg;
ll go_sum(ll L, ll R, ll now, ll now_L, ll now_R);
void upd(ll index, ll val);
int main(void) {
	scanf("%lld %lld", &n, &q);
	while (n > h) h *= 2;
	seg.resize(h * 2);
	for (ll i = 1; i <= n; i++) {
		long long a;
		scanf("%lld", &a);
		upd(i, a);
	}
	for (ll i = 0; i < q; i++) {
		ll x, y, a, b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		ll y_go = max(x, y);
		ll x_go = min(x, y);
		printf("%lld\n", go_sum(x_go, y_go, 1, 1, h));
		upd(a, b);
	}
}
void upd(ll index, ll val) {
	index += h - 1;
	seg[index] = val;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
ll go_sum(ll L, ll R, ll now, ll now_L, ll now_R) {
	if (L <= now_L && now_R <= R) return seg[now];
	else if (now_R < L || R < now_L) return 0;
	ll mid = (now_L + now_R) / 2;
	return go_sum(L, R, now * 2, now_L, mid) + go_sum(L, R, now * 2 + 1, mid + 1, now_R);
}