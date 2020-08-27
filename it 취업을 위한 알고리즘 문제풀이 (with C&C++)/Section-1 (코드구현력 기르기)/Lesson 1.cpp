#include <iostream>
using namespace std;
int main(void) {
	int N, M, sum = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		if (!(i % M)) sum += i;  
	}
	cout << sum;
	return 0;
}