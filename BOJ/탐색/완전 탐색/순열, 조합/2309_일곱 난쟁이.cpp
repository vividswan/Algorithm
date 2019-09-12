#include <iostream>
#include <algorithm>
using namespace std;
void go(int index, int cnt);
int dwarf[10], tr[10], check[10], res;
int main(void) {
	for (int i = 1; i <= 9; i++) {
		cin >> dwarf[i];
	}
	sort(dwarf, dwarf + 10);
	go(0, 0);
	return 0;
}
void go(int index, int cnt) {
	if (index > 9) return;
	if (res) return;
	if (cnt == 7) {
		int sum = 0;
		for (int i = 1; i <= 9; i++) {
			if (tr[i]) sum += dwarf[i];
		}
		if (sum == 100) {
			for (int i = 1; i <= 9; i++) {
				if (tr[i]) cout << dwarf[i] << "\n";

			}
			res++;
			return;
		}
	}
	tr[index + 1] = 1;
	go(index + 1, cnt + 1);
	tr[index + 1] = 0;
	go(index + 1, cnt);
}