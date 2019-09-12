#include <iostream>
using namespace std;
int res, sch = 0;
int main(void) {
	int num, tim;
	scanf("%d %d", &num, &tim);
	for (int i = 0; i < num; i++) {
		int fir, inter, cnt;
		scanf("%d %d %d", &fir, &inter, &cnt);
		for (int j = 0; j < cnt; j++) {
			if (sch == 0) {
				if (fir - tim >= 0) {
					res = fir - tim;
					sch = 1;
				}
			}
			if (fir - tim >= 0) {
				int min = fir - tim;
				if (min < res) {
					res = min;
					break;
				}
			}
			fir += inter;
		}
	}
	if (sch == 1) 	printf("%d", res);
	else printf("-1");
}