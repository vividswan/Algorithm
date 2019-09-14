#include <iostream>
using namespace std;
int cnt(int i);
int main(void) {
	int num;
	int res = 0;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		res += cnt(i);
	}
	printf("%d", res);
	return 0;
}
int cnt(int i) {
	int plu = 0;
	while (i) {
		i = i / 10;
		plu++;
	}
	return plu;
}