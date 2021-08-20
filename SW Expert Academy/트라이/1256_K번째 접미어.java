import java.io.*;
import java.util.Stack;

class Node {
    private boolean isEnd;
    private Node[] children;

    public void setChildren(Node[] children) {
        this.children = children;
    }

    public void setEnd(boolean end) {
        isEnd = end;
    }

    public Node[] getChildren() {
        return children;
    }

    public boolean isEnd() {
        return isEnd;
    }

    public Node() {
        this.isEnd = false;
        this.children = new Node[26];
    }

    public void addNode(String str) {
        Node node = this;
        for (int i = 0; i <str.length() ; i++) {
            int now = str.charAt(i) - 'a';
            if (node.children[now] == null) node.children[now] = new Node();
            node = node.children[now];
            if (i== str.length()-1) node.setEnd(true);
        }
    }
}

public class Solution {
    public static int testCase, k;
    public static Node rootNode;
    public static String str;
    public static int cnt;
    public static Stack<Integer> s;
    public static String res;

    public static void find(Node node) {
        if (node.isEnd()) {
            cnt++;
            if (cnt == k) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i <s.size() ; i++) {
                    sb.append((char)(s.get(i)+'a'));
                }
                res = sb.toString();
                return;
            }
        }
        for (int i = 0; i <26 ; i++) {
            if (node.getChildren()[i] != null) {
                s.push(i);
                find(node.getChildren()[i]);
                s.pop();
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            cnt = 0;
            s = new Stack<>();
            k = Integer.parseInt(br.readLine());
            str = br.readLine();
            res = null;
            rootNode = new Node();
            for (int i = str.length()-1; i >=0 ; i--) {
                rootNode.addNode(str.substring(i));
            }
            find(rootNode);
            if (res==null) res = "none";
            bw.write("#"+t+" "+res+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}