#include <iostream>
#include <algorithm>
using namespace std;
int maxTime, minTime, cost;
int numberOfTruck[101];
int oneTruck, twoTruck, threeTruck;
int main(void) {
	minTime = 101;
	scanf("%d%d%d", &oneTruck, &twoTruck, &threeTruck);
	for (int i = 0; i < 3; i++) {
		int st;
		int ed;
		scanf("%d %d", &st, &ed);
		minTime = min(minTime, st);
		maxTime = max(maxTime, ed);
		for (int j = st; j < ed; j++) numberOfTruck[j]++;
	}
	for (int i = minTime; i <= maxTime; i++) {
		if (!numberOfTruck[i]) continue;
		else if (numberOfTruck[i] == 1) cost += oneTruck;
		else if (numberOfTruck[i] == 2) cost += twoTruck * 2;
		else cost += threeTruck * 3;
	}
	printf("%d\n", cost);
	return 0;
}