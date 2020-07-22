#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long getArea(long long x1, long long y1, long long x2, long long y2) {
	return x1 * y2 - x2 * y1;
}
int main(void) {
	int N;
	cin >> N;
	vector<pair<long long, long long>> dot;
	for (int i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		dot.push_back({ x,y });
	}
	vector<pair<long long, long long>> line;
	for (int i = 1; i < N; i++) {
		int x = dot[0].first - dot[i].first;
		int y = dot[0].second - dot[i].second;
		line.push_back({ x,y });
	}
	long long result = 0;
	for (int i = 0; i < line.size()-1; i++) {
		result += getArea(line[i].first, line[i].second, line[i + 1].first, line[i + 1].second);
	}
	printf("%.1lf\n", abs(result / 2.0));
	return 0;
}