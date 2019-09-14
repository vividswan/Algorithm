#include <iostream>
using namespace std;
int fact(int num);
int check[15];
int main(void) {
	int num;
	cin >> num;
	cout << fact(num);
	return 0;
}
int fact(int num) {
	if (num == 0) return 1;
	if (check[num]) return check[num];
	return check[num] = num * fact(num - 1);
}