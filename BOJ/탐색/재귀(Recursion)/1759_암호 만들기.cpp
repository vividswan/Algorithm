#include <iostream>
#include <algorithm>
using namespace std;
char map[16];
int cap(char a);
void go(int index, int cnt);
int tr[16];
int l, c;
int main() {
	scanf("%d%d", &l, &c);
	for (int i = 0; i < c; i++) {
		scanf(" %c", &map[i]);
	}
	sort(map, map + c);
	go(0, 0);
}
int f_cap(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return 0;
	else return 1;
}
void go(int index, int cnt) {
	if (index > c) return;
	if (cnt == l) {
		int cap = 0, ncap = 0;
		for (int i = 0; i < c; i++) {
			if (tr[i]) {
				if (f_cap(map[i])) cap++;
				else ncap++;
			}
		}
		if (cap >= 2 && ncap >= 1) {
			for (int i = 0; i < c; i++) {
				if (tr[i]) {
					printf("%c", map[i]);
				}
			}
			printf("\n");
		}
		return;
	}
	tr[index] = 1;
	go(index + 1, cnt + 1);
	tr[index] = 0;
	go(index + 1, cnt);
}