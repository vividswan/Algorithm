import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    public static int[] vis;
    public static boolean[] isCircle;
    public static boolean dfs(int idx, int target){
        for(int i=0; i<graph.get(idx).size(); i++){
            int next = graph.get(idx).get(i);
            if(next == target && vis[idx]>=2 ) return true;
            if(vis[next]!=-1) continue;
            vis[next] = vis[idx] + 1;
            if(dfs(next,target)) return true;
        }
        return false;
    }
    public static int bfs(int idx){
        int[] cnt = new int[n+1];
        for(int i=1; i<=n; i++) cnt[i] = -1;
        Queue<Integer> q = new LinkedList<>();
        q.offer(idx);
        cnt[idx] = 0;
        while (!q.isEmpty()){
            int now = q.poll();
            if (isCircle[now]) return cnt[now];
            for(int i=0; i<graph.get(now).size(); i++){
                int next = graph.get(now).get(i);
                if(cnt[next]==-1){
                    cnt[next] = cnt[now] + 1;
                    q.offer(next);
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        isCircle = new boolean[n+1];
        for(int i=0; i<=n; i++) {
            graph.add(new ArrayList<>());
        }

        for(int i=1; i<=n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a= Integer.parseInt(st.nextToken());
            int b= Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        for(int i = 1; i<=n; i++){
            vis = new int[n+1];
            for(int j=1; j<=n; j++) vis[j] = -1;
            vis[i] = 0;
            if(dfs(i, i)) isCircle[i] = true;
        }
        for(int i=1; i<=n; i++){
            if (isCircle[i]) bw.write("0 ");
            else bw.write(String.valueOf(bfs(i))+" ");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}