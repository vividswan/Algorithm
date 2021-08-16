import java.io.*;

class Trie {
    long cnt;
    long total;
    Trie[] children;

    public Trie() {
        children = new Trie[26];
        cnt = 0;
        total = 0;
    }
}

public class Solution {

    static int n, m;
    static long res;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int testCase = Integer.parseInt(br.readLine());


        char chrs[];
        boolean flag;
        Trie now, head;
        for (int t = 1; t <= testCase; t++) {
            head = new Trie();
            res = 0;
            n = Integer.parseInt(br.readLine());

            for (int i = 0; i < n; i++) {
                chrs = br.readLine().toCharArray();

                now = head;
                long tmpTotal = 0;
                for (int j = 0; j < chrs.length; j++) {
                    if (now.children[chrs[j] - 'a'] == null) {
                        now.children[chrs[j] - 'a'] = new Trie();
                    }
                    now.cnt++;
                    tmpTotal += now.cnt;
                    now = now.children[chrs[j] - 'a'];
                }
                now.cnt++;
                tmpTotal += now.cnt;
                now.total = tmpTotal;
            }
            m = Integer.parseInt(br.readLine());
            for (int i = 0; i < m; i++) {
                chrs = br.readLine().toCharArray();
                now = head;
                flag = false;
                long count = 0;
                for (int j = 0; j <= chrs.length; j++) {
                    count += now.cnt;
                    if (j == chrs.length) {
                        flag = true;
                        break;
                    }
                    if (now.children[chrs[j] - 'a'] == null) {
                        flag = false;
                        break;
                    }
                    now = now.children[chrs[j] - 'a'];
                }

                if (flag && now.total > 0) {
                    res += now.total;
                } else {
                    res += count;
                }
            }
            bw.write("#"+t+" "+res+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}