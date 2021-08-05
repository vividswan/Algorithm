import java.io.*;
import java.util.*;

public class Solution {
    public static int testCase, maxIdx, bef, n;
    public static ArrayList<ArrayList<Integer>> graph;
    public static int[] vis, depth;
    public static int[][] ans;
    public static void init() {
        Queue<Integer> q = new LinkedList();
        int[] par = new int[n + 1];
        Arrays.fill(par,-1);
        q.add(1);
        par[1] = 0;
        depth[0] = -1;
        while (!q.isEmpty()) {
            int now = q.poll();
            depth[now] = depth[par[now]] + 1;
            ans[now][0] = par[now];
            for (int i = 1; i <= maxIdx; i++) {
                int temp = ans[now][i-1];
                ans[now][i] = ans[temp][i - 1];
            }
            for (int i = 0; i < graph.get(now).size(); i++) {
                int next = graph.get(now).get(i);
                if (par[next]!=-1) continue;
                par[next] = now;
                q.add(next);
            }
        }
    }

    public static int getAns(int a, int b) {
        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            for (int i = maxIdx; i >=0 ; i--) {
                if (depth[a] <= depth[ans[b][i]]) {
                    b = ans[b][i];
                }
            }
        }
        int lca = a;
        if (a==b) return lca;
        for (int i = maxIdx; i >=0 ; i--) {
            if (ans[a][i] != ans[b][i]) {
                a = ans[a][i];
                b = ans[b][i];
            }
            lca = ans[a][i];
        }
        return lca;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCase; t++) {
            n = Integer.parseInt(br.readLine());
            vis = new int[n + 1];
            long res = 0;
            depth = new int[n + 1];
            maxIdx = 0;
            int tempDepth = n;
            while (tempDepth > 0) {
                maxIdx++;
                tempDepth /= 2;
            }
            ans = new int[n + 1][maxIdx + 1];
            graph = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i <=n ; i++) graph.add(new ArrayList<>());
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i=2; i<=n; i++) graph.get(Integer.parseInt(st.nextToken())).add(i);
            for (int i = 1; i <= n; i++) Collections.sort(graph.get(i));
            depth[0] = -1;
            init();
            Arrays.fill(vis, -1);
            vis[1] = 0;
            Queue<Integer> q = new LinkedList<>();
            q.add(1);
            bef = 1;
            while (!q.isEmpty()) {
                int now = q.poll();
                int lca = getAns(bef, now);
                res += vis[bef] - vis[lca];
                res += vis[now] - vis[lca];
                for (int i = 0; i <graph.get(now).size() ; i++) {
                    int next = graph.get(now).get(i);
                    if (vis[next] != -1) continue;
                    vis[next] = vis[now]+1;
                    q.add(next);
                }
                bef = now;
            }
            bw.write("#"+t+" "+String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}