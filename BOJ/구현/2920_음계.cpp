#include<stdio.h>
int main(void) {
	int arr[9];
	for (int roof = 1; 8 >= roof; roof++) scanf("%d", &arr[roof]);
	if (arr[1] == 1 && arr[2] == 2 && arr[3] == 3 && arr[4] == 4 && arr[5] == 5 && arr[6] == 6 && arr[7] == 7 && arr[8] == 8) printf("ascending\n");
	else if (arr[1] == 8 && arr[2] == 7 && arr[3] == 6 && arr[4] == 5 && arr[5] == 4 && arr[6] == 3 && arr[7] == 2 && arr[8] == 1) printf("descending\n");
	else printf("mixed\n");
	return 0;
}