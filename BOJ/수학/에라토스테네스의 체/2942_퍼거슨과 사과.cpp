#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void) {
	int r, g;
	int res_r, res_g;
	scanf("%d%d", &r, &g);
	res_r = r;
	res_g = g;
	if (r < g) swap(r, g);
	while (g) {
		int temp = r;
		r = g;
		g = (temp % g);
	}
	for (int i = 1; i <= sqrt(r); i++) {
		if ((r % i) == 0) {
			printf("%d %d %d\n", i, res_r / i, res_g / i);
			if(i!=(r/i))printf("%d %d %d\n", r / i, res_r / (r / i), res_g / (r / i));
		}
	}
	return 0;
}