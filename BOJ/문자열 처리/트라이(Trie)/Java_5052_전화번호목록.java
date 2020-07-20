import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_5052_전화번호목록 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int i=0;i<T;i++) {
			int n = Integer.parseInt(br.readLine());
			Trie trie = new Trie();
			for(int j=0;j<n;j++) {
				String word = br.readLine();
				trie.insert(word);
			}
			if(Trie.isConsistency) System.out.println("YES");
			else System.out.println("NO");
			Trie.isConsistency=true;
		}
	}

}

class Trie {
	static boolean isConsistency=true;
	boolean isWord = false;
	boolean existChild = false;
	Trie[] childTrie = new Trie[10];
	void insert(String word) {
		int len = word.length();
		Trie nowTrie = this;
		for(int i=0;i<len;i++) {
			int nextNum = word.charAt(i)-'0';
			if(nowTrie.childTrie[nextNum]==null) nowTrie.childTrie[nextNum] = new Trie();
			nowTrie = nowTrie.childTrie[nextNum];
			if(i==len-1) nowTrie.isWord=true;
			else nowTrie.existChild=true;
			if(nowTrie.isWord && nowTrie.existChild) isConsistency = false;
		}
	}
}