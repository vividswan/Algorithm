#include <iostream>
#include <cstring>
using namespace std;
struct Trie {
	Trie* next[10];
	bool sen_end;
	Trie() {
		memset(next, 0, sizeof(next));
		sen_end = false;
	}
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i]) delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0') sen_end = true;
		else {
			int curr = *key - '0';
			if (next[curr] == NULL) next[curr] = new Trie;
			next[curr]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0') return 0;
		if (sen_end) return 1;
		int curr = *key - '0';
		return next[curr]->find(key + 1);
	}
};
int tk, n, res;
char str[10001][11];
int main(void) {
	scanf("%d", &tk);
	while (tk--) {
		scanf("%d", &n);
		getchar();
		res = 0;
		Trie* root = new Trie;
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
		}
		for (int i = 0; i < n; i++) root->insert(str[i]);
		for (int i = 0; i < n; i++) {
			if (root->find(str[i])) res = 1;
		}
		if (res) printf("NO\n");
		else printf("YES\n");
	}
}