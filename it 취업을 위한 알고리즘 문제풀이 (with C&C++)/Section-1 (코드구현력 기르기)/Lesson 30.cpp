#include <iostream>
using namespace std;
long long result;
long long sumResult(int leftNum, int rightNum, int swc, int digit);
int main(void) {
	int N;
	cin >> N;
	int rightNum = 0;
	int leftNum = N;
	int nowdigit = 1;
	while (leftNum) {
		int lastNum = leftNum % 10;
		leftNum /= 10;
		int swc;
		if (lastNum < 3) swc = -1;
		else if (lastNum == 3) swc = 0;
		else swc = 1;
		result += sumResult(leftNum, rightNum, swc, nowdigit);
		rightNum += lastNum * nowdigit;
		nowdigit *= 10;
	}
	cout << result << '\n';
	return 0;
}
long long sumResult(int leftNum, int rightNum, int swc, int digit) {
	if (swc == -1) {
		return leftNum * digit;
	}
	else if (swc == 0) {
		return leftNum * digit + rightNum + 1;
	}
	else {
		return (leftNum + 1) * digit;
	}
}