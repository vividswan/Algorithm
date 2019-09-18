#include <iostream>
using namespace std;
int t;
int main(void) {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int size;
		scanf("%d", &size);
		int map[50][50];
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		int sum = 0;
		int mid = size / 2 + 1;
		for (int i = 1; i <= size / 2; i++) {
			for (int j = mid - (i - 1); j <= mid + (i - 1); j++) {
				sum += map[i][j];
			}
		}
		for (int i = 1; i <= size; i++) sum += map[mid][i];
		int a = 0;
		for (int i = size; i >= mid + 1; i--) {
			for (int j = mid - a; j <= mid + a; j++) {
				sum += map[i][j];
			}
			a++;
		}
		printf("#%d %d\n",i, sum);
	}
	return 0;
}