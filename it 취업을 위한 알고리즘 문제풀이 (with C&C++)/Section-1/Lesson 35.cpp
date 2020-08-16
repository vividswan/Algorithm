#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<int> adj1;
	vector<int> adj2;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num < 0) adj1.push_back(num);
		else adj2.push_back(num);
	}
	for (int i = 0; i < adj1.size(); i++) cout << adj1[i] << ' ';
	for (int i = 0; i < adj2.size(); i++) cout << adj2[i] << ' ';
	return 0;
}