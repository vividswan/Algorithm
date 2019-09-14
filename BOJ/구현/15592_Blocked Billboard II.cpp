#include <iostream>
using namespace std;
int res;
int x1, x2, x3, x4, y1, y2, y3, y4;
int main(void) {
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	res = (x2 - x1) * (y2 - y1);
	if (x3 <= x1 && x2 <= x4) {
		if (y3 <= y1 && y2 <= y4)  res = 0;
		if (y3 <= y1 && y2 > y4) res = (x2 - x1) * (y2 - y4);
		if (y2 <= y4 && y1 < y3) res = (x2 - x1) * (y3 - y1);
	}
	if (y4 >= y2 && y3 <= y1) {
		if (x1 < x3 && x4 >= x2) res = (y2 - y1) * (x3 - x1);
		if (x4 < x2 && x3 <= x1) res = (y2 - y1) * (x2 - x4);
	}
	printf("%d\n", res);
	return 0;
}