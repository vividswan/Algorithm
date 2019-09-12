#include <iostream>
#include <cstring>
using namespace std;
char str1[1000005];
int str2[1000005];
int main(void) {
	cin.getline(str1, 1000005);
	int l = strlen(str1);
	int cut = 1;
	int cnt = 0;
	int j = 0;
	for (int i = l - 1; i >= 0; i--) {
		if (str1[i] == '1') {
			if (cut == 1) cnt += 1;
			else if (cut == 2) cnt += 2;
			else if (cut == 3) cnt += 4;
		}
		if (cut == 3 || i == 0) {
			str2[j] = cnt;
			j++;
			cut = 0;
			cnt = 0;
		}
		cut += 1;
	}
	for (int k = j - 1; k >= 0; k--) {
		printf("%d", str2[k]);
	}
}