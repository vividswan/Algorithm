#include <iostream>
#include <algorithm>
using namespace std;
int caseNum;
int main(void) {
	while (true) {
		caseNum++;
		int L, P, V;
		scanf("%d%d%d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0) break;
		int numValue = (V / P) * L;
		int remainder = min(L, V % P);
		int result = numValue + remainder;
		printf("Case %d: %d\n", caseNum, result);
	}
	return 0;
}