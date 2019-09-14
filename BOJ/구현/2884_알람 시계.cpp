#include <iostream>
using namespace std;
int n, m;
int main(void) {
	cin >> n >> m;
	if (m >= 45) printf("%d %d", n, m - 45);
	else {
		if (n == 0) printf("%d %d", 23, 60 - (45 - m));
		else printf("%d %d", n - 1, 60 - (45 - m));
	}
	return 0;
}