#include <iostream>
using namespace std;
int nm, happy[21], sad[21];
void go(int index, int life, int nowhappy);
int res_max;
int main(void) {
	cin >> nm;
	for (int i = 1; i <= nm; i++) {
		cin >> sad[i];
	}
	for (int i = 1; i <= nm; i++) {
		cin >> happy[i];
	}
	go(0, 100, 0);
	cout << res_max;
}
void go(int index, int life, int nowhappy) {
	if (nowhappy > res_max) res_max = nowhappy;
	if (index >= nm) return;
	if (sad[index + 1] < life) go(index + 1, life - sad[index + 1], nowhappy + happy[index + 1]);
	go(index + 1, life, nowhappy);
}