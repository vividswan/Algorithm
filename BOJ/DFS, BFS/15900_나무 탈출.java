import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[] depth;
    public static boolean[] isLeaf;
    public static void dfs(int idx) {
        int cnt = 0;
        for (int i = 0; i < graph.get(idx).size(); i++) {
            int next = graph.get(idx).get(i);
            if (depth[next]!=-1) continue;
            cnt++;
            depth[next] = depth[idx] + 1;
            dfs(next);
        }
        if (cnt==0) isLeaf[idx] = true;
    }
    public static ArrayList<ArrayList<Integer>> graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        depth = new int[n + 1];
        isLeaf = new boolean[n + 1];
        Arrays.fill(depth, -1);
        depth[1] = 0;
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n-1; i++) {
            int a;
            int b;
            StringTokenizer st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        dfs(1);
        int tot = 0;
        for (int i = 1; i <=n ; i++) {
            if(isLeaf[i]) tot+= depth[i];
        }
        if (tot%2==1) bw.write("Yes\n");
        else bw.write("No\n");
        bw.flush();
        br.close();
        bw.close();
    }
}