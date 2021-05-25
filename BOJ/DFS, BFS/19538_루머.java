import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public  class Main {
    public static int n, m;
    public static int[] cnt;
    public static int[] originCnt;
    public static int[] vis;
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
        cnt = new int[n+1];
        originCnt = new int[n+1];
        vis = new int[n+1];
        for(int i=1; i<=n; i++){
            vis[i] = -1;
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (true){
                int idx = Integer.parseInt(st.nextToken());
                if (idx==0) break;
                cnt[i]++;
                graph.get(i).add(idx);
            }
        }
        for(int i=1; i<=n; i++) originCnt[i] = cnt[i];
        Queue<Integer> q = new LinkedList<>();
        m = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1; i<=m; i++){
            int idx = Integer.parseInt(st.nextToken());
            vis[idx] = 0;
            q.offer(idx);
        }
        while (!q.isEmpty()){
            int now = q.poll();
            for(int i=0; i<graph.get(now).size(); i++){
                int next = graph.get(now).get(i);
                if (vis[next]!=-1) continue;
                cnt[next]--;
                if (cnt[next] <= originCnt[next]/2){
                    vis[next] = vis[now]+1;
                    q.offer(next);
                }
            }
        }
        for(int i=1; i<=n; i++) bw.write(String.valueOf(vis[i])+" ");
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}