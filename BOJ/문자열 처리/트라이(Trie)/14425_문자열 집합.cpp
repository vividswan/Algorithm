#include <iostream>
using namespace std;
struct Trie {
	bool isWord;
	Trie* childTrie[26];
	Trie() {
		isWord = false;
		for (int i = 0; i < 26; i++)childTrie[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (childTrie[i]) delete childTrie[i];
		}
	}
	void insert(char* word) {
		if (*word == '\0') isWord = true;
		else {
			int next = *word - 'a';
			if (!childTrie[next]) childTrie[next] = new Trie();
			childTrie[next]->insert(word + 1);
		}
	}
	bool find(char* word) {
		if (*word == '\0') {
			if (isWord) return true;
			else return false;
		}
		else {
			int next = *word - 'a';
			if (!childTrie[next]) return false;
			return childTrie[next]->find(word + 1);
		}
	}
};
int main(void) {
	int N, M, result = 0;
	cin >> N >> M;
	Trie* trie = new Trie();
	for (int i = 0; i < N; i++) {
		char word[501];
		cin >> word;
		trie->insert(word);
	}

	for (int i = 0; i < M; i++) {
		char word[501];
		cin >> word;
		if (trie->find(word)) result++;
	}
	cout << result << '\n';
	return 0;
}