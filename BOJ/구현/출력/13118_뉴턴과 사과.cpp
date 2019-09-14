#include <iostream>
using namespace std;
int main(void) {
	int arr[4];
	int cen_x, cen_y, r;
	scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &cen_x, &cen_y, &r);
	for (int i = 0; i < 4; i++) {
		if (arr[i] == cen_x) {
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("0");
}