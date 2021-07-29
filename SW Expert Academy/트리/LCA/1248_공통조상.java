import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    public static int testCase;
    public static int v, e, a, b, maxDepth;
    public static int[] depth, leafs;
    public static int[][] ans;
    public static ArrayList<ArrayList<Integer>> graph;

    public static int init(int idx, int parent) {

        depth[idx] = depth[parent] + 1;
        ans[idx][0] = parent;

        for (int i = 1; i <= maxDepth; i++) {
            int temp = ans[idx][i - 1];
            ans[idx][i] = ans[temp][i-1];
        }

        int len = graph.get(idx).size();
        if (len == 0) return leafs[idx] = 1;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt += init(graph.get(idx).get(i),idx);
        }
        return leafs[idx] = cnt+1;
    }

    public static int getLCA(int a, int b) {
        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            for (int i = maxDepth; i >=0 ; i--) {
                if (depth[a] <= depth[ans[b][i]]) {
                    b = ans[b][i];
                }
            }
        }
        int lca = a;
        if (a != b) {
            for (int i = maxDepth; i >=0 ; i--) {
                if (ans[a][i] != ans[b][i]) {
                    a = ans[a][i];
                    b = ans[b][i];
                }
                lca = ans[a][i];
            }
        }
        return lca;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCase; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            v = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            maxDepth = 0;
            leafs = new int[v + 1];
            int tempV = v;
            while (tempV >0){
                maxDepth++;
                tempV /= 2;
            }
            ans = new int[v + 1][maxDepth + 1];
            depth = new int[v + 1];
            graph = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i <= v; i++) graph.add(new ArrayList<>());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < e; i++) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                graph.get(x).add(y);
            }
            depth[0] = -1;
            leafs[1] =  init(1,0);
            int res = getLCA(a, b);
            bw.write("#"+t+" "+String.valueOf(res)+" "+leafs[res]+"\n");

        }
        bw.flush();
        br.close();
        bw.close();
    }
}