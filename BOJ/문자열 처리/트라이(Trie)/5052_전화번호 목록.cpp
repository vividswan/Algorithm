#include <iostream>
#include <cstring>
using namespace std;
bool isConsistent = true;
struct Trie {
	bool isWord;
	bool existChild;
	Trie* childTrie[10];
	Trie() {
		isWord = false;
		existChild = false;
		for (int i = 0; i < 10; i++) childTrie[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (childTrie[i]) delete childTrie[i];
		}
	}

	void insert(char* word) {
		if (*word == '\0') isWord = true;
		else {
			int next = *word - '0';
			if (!childTrie[next]) childTrie[next] = new Trie;
			existChild = true;
			childTrie[next]->insert(word + 1);
		}
		if (isWord && existChild) isConsistent = false;
	}
};
int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		isConsistent = true;
		Trie* trie = new Trie;
		int N;
		cin >> N;
		for (int j = 0; j < N; j++) {
			char word[11];
			cin >> word;
			trie->insert(word);
		}
		if (isConsistent) cout << "YES\n";
		else cout << "NO\n";
		delete trie;
	}
}