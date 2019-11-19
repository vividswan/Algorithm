#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> pii;

string s, p[502];
map<char, int> mp;

vector<int> getPi(string p)
{
	int m = (int)p.size();
	int j = 0;

	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
vector<int> kmp(string s, string p)
{
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		vector<int> ans;
		string order, ori, secret;

		cin >> order >> ori >> secret;

		int lenOrder = order.size();
		for (int i = 0; i < lenOrder; i++)
			mp[order[i]] = i;

		int lenOri = ori.size();
		for (int shift = 0; shift < lenOrder; shift++)
		{
			string tmp = ori;
			for (int i = 0; i < lenOri; i++)
				tmp[i] = order[(mp[tmp[i]] + shift) % lenOrder];

			vector<int> vc = kmp(secret, tmp);

			if (vc.size() == 1)
				ans.push_back(shift);
		}

		if (ans.size() == 0)
			cout << "no solution" << endl;
		else if (ans.size() == 1)
			cout << "unique: " << ans[0] << endl;
		else
		{
			cout << "ambiguous: ";
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << " ";
			cout << endl;
		}

	}
	return 0;
}