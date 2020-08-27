#include <iostream>
using namespace std;
int main(void) {
	int N;
	int result = 0;
	int level = 1;
	int levelValue = 9;
	int levelSum = 9;
	cin >> N;
	while (levelSum < N) {
		result += level * levelValue;
		level++;
		levelValue *= 10;
		levelSum += levelValue;
	}
	levelSum -= levelValue;
	result += (N - levelSum) * level;
	cout << result << '\n';
	return 0;
}