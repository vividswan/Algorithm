import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 11437_LCA {

    public static int n;
    public static int m;
    public static int max_height;

    public static double baseLog(double a, double b) {
        return Math.log(a) / Math.log(b);
    }

    public static int[] depth;
    public static int[][] ans;
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();

    public static void getTree(int now, int parent) {
        depth[now] = depth[parent] + 1;
        ans[now][0] = parent;

        for (int i = 1; i <= max_height; i++) {
            int temp = ans[now][i - 1];
            ans[now][i] = ans[temp][i - 1];
        }

        int len = graph.get(now).size();
        for (int i = 0; i < len; i++) {
            int next = graph.get(now).get(i);
            if (next != parent) getTree(next, now);
        }


    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        depth = new int[n + 1];
        depth[0] = -1;
        ans = new int[n + 1][20];
        max_height = (int) baseLog(n, 2);
        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
        for (int i = 1; i <= n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        getTree(1, 0);

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (depth[a] != depth[b]) {
                if (depth[a] > depth[b]) {
                    int temp = a;
                    a = b;
                    b = temp;
                }
            }
            for (int j = max_height; j >= 0; j--) {
                if (depth[a] <= depth[ans[b][j]]) b = ans[b][j];
            }
            int lca = a;
            if (a != b) {
                for (int j = max_height; j >= 0; j--) {
                    if (ans[a][j] != ans[b][j]) {
                        a = ans[a][j];
                        b = ans[b][j];
                    }
                    lca = ans[a][j];
                }
            }
            bw.write(String.valueOf(lca) + "\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}