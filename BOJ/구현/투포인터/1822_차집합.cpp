#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int nA, nB;
	cin >> nA >> nB;
	vector<int> v1(nA);
	vector<int> v2(nB);
	for (int i = 0; i < nA; i++) cin >> v1[i];
	sort(v1.begin(), v1.end());
	for (int i = 0; i < nB; i++) cin >> v2[i];
	sort(v2.begin(), v2.end());

	int ptr1, ptr2;
	ptr1 = ptr2 = 0;

	
	vector<int> result;
	while (ptr1 < nA && ptr2 < nB) {
		if (v1[ptr1] == v2[ptr2]) {
			ptr1++;
			ptr2++;
		}
		else if (v1[ptr1] > v2[ptr2]) ptr2++;
		else {
			result.push_back(v1[ptr1]);
			ptr1++;
		}
	}

	while (ptr1 < nA) {
		result.push_back(v1[ptr1]);
		ptr1++;
	}
	cout << result.size() << '\n';
	for (int i : result) {
		cout << i << ' ';
	}
	cout << '\n';

	
	return 0;
}