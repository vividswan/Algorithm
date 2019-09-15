#include <iostream>
using namespace std;
int swc, res, tk, n, m;
struct Trie {
	Trie* next[128];
	bool finish;
	bool ok;
	bool first_ok;
	Trie() {
		fill(next, next + 128, nullptr);
		finish = false;
		ok = false;
	}
	~Trie() {
		for (int i = 0; i < 128; i++) if (next[i]) delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
			if (!swc) ok = true;
			else ok = false;
			return;
		}
		if (!swc) {
			ok = true;
		}
		else ok = false;
		int curr = *key;
		if (next[curr] == nullptr) next[curr] = new Trie();
		next[curr]->insert(key + 1);
	}
	void find() {
		if (ok) {
			res++;
			return;
		}
		else if (finish) res++;
		for (int i = 0; i < 128; i++) {
			if (next[i]) next[i]->find();
		}
	}
};
int main(void) {
	scanf("%d", &tk);
	while (tk--) {
		Trie* root = new Trie();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char str[21];
			scanf(" %s", str);
			root->insert(str);
		}
		scanf("%d", &m);
		swc = 1;
		for (int i = 0; i < m; i++) {
			char str[21];
			scanf(" %s", str);
			root->insert(str);
		}
		root->find();
		printf("%d\n", res - m);
		res = 0;
		swc = 0;
		delete root;
	}
}