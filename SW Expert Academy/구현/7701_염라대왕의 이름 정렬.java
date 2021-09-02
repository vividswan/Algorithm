import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

class Node implements Comparable<Node>{
    private int len;
    private String str;

    public int getLen() {
        return len;
    }

    public String getStr() {
        return str;
    }

    public Node(String str) {
        this.str = str;
        this.len = str.length();
    }

    @Override
    public int compareTo(Node other) {
        if (this.len == other.len) return String.CASE_INSENSITIVE_ORDER.compare(this.str, other.str);
        else return Integer.compare(this.len, other.len);
    }
}

public class Solution {
    public static int testCase;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCase ; t++) {
            bw.write("#"+t+"\n");
            int n = Integer.parseInt(br.readLine());
            ArrayList<Node> nodes = new ArrayList<>();
            for (int i = 0; i <n ; i++) {
                nodes.add(new Node(br.readLine()));
            }
            Collections.sort(nodes);
            for (int i = 0; i <nodes.size() ; i++) {
                if(i>0){
                    if (nodes.get(i-1).getStr().equals(nodes.get(i).getStr())) continue;
                }
                bw.write(nodes.get(i).getStr()+"\n");
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}