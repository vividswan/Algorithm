#include <iostream>
#include <cmath>
using namespace std;
int era[100001], check[100001], nm1, nm2, cnt1, cnt2, res;;
int main(void) {
	cin >> nm1 >> nm2;
	for (int j = 2; j <= sqrt(nm2); j++) {
		if (check[j] == 0) {
			era[cnt1] = j;
			cnt1++;
			int mul = 2;
			int nm3 = mul * j;
			while (nm3 <= nm2) {
				check[nm3] = 1;
				mul++;
				nm3 = mul * j;
			}
		}
	}
	check[0] = 1;
	check[1] = 1;
	for (int i = nm1; i <= nm2; i++) {
		int nm4 = i;
		int st = 2;
		cnt2 = 0;
		while (nm4 != 1) {
			if (check[st] == 0) {
				if (nm4 % st == 0) {
					nm4 = nm4 / st;
					cnt2++;
				}
				else st++;
			}
			else st++;
		}
		if (check[cnt2] == 0) res++;
	}
	printf("%d", res);
}