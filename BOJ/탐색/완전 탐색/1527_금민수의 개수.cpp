#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
void go(int cnt, int depth, long long int now);
long long int a_num, b_num, res;
int main(void) {
	char a[12];
	char b[12];
	scanf("%s%s", a, b);
	a_num = atol(a);
	b_num = atol(b);
	int fin = strlen(b);
	go(0, fin, 0);
	printf("%lld", res);
}
void go(int cnt, int depth, long long int now) {
	if (cnt > depth) return;
	if (now >= a_num && b_num >= now) res++;
	go(cnt + 1, depth, now * 10 + 4);
	go(cnt + 1, depth, now * 10 + 7);
	return;
}