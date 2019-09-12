#include <iostream>
#include <cstring>
using namespace std;
char sen[51][51], ans[51];
int roof, cnt;
int main(void) {
	scanf("%d", &roof);
	for (int i = 0; i < roof; i++) {
		scanf("%s", sen[i]);
	}
	int len = strlen(sen[0]);
	char fir;
	for (int j = 0; j < len; j++) {
		for (int i = 0; i < roof; i++) {
			if (i == 0) {
				fir = sen[i][j];
			}
			if (fir != sen[i][j]) {
				cnt++;
				break;
			}
		}
		if (cnt == 0) ans[j] = fir;
		else {
			ans[j] = '?';
			cnt = 0;
		}
	}
	printf("%s", ans);
}