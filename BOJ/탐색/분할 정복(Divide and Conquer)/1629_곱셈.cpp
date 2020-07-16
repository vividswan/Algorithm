#include <iostream>
using namespace std;
long long A, B, C;
long long func(long long val, long long num);
int main(void) {
	cin >> A >> B >> C;
	A = A % C;
	long long result = func(A, B) % C;;
	cout << result << '\n';
}
long long func(long long val, long long num) {
	if (num == 1) return val % C;
	else {
		long long nextNum = num / 2;
		long long nowVal = func(val, nextNum)%C;
		if ((num % 2) == 0) return (nowVal * nowVal) % C;
		else return ((nowVal * nowVal % C) * val) % C;
	}
}