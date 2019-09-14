#include <stdio.h>
int main(void) {
	int cute = 0;
	int ncute = 0;
	int num;
	scanf("%d", &num);
	int i = 1;
	int k;
	for (i; num >= i; i++) {
		scanf("%d", &k);
		if (k == 1) cute++;
		else if (k == 0) ncute++;
	}
	if (cute >= ncute) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
}