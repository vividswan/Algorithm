#include<stdio.h>
#include<string.h>
int main(void) {
	int a, b, c;
	int arr[11];
	int arr2[10] = { 0, };
	int roof;
	scanf("%d %d %d", &a, &b, &c);
	arr[0] = a * b * c;
	for (roof = 1; 10 >= roof; roof++) {
		if (arr[0] == 0) break;
		else {
			arr[roof] = arr[0] % 10;
			arr[0] = arr[0] / 10;
		}
	}
	for (int a = 0; 9 >= a; a++)
		for (int b = 1; roof > b; b++) {
			if (arr[b] == a) arr2[a]++;
		}
	for (int a = 0; 9 >= a; a++) printf("%d\n", arr2[a]);
	return 0;
}