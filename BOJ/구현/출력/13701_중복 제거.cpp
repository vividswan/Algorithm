#include <iostream>
#include <bitset>
using namespace std;

int main(void) {
	bitset<33554432> b;
	int n;
	while (~scanf("%d", &n)) {
		if (!b[n])printf("%d ", n);
		b[n] = 1;
	}
}