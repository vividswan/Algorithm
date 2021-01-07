import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 18352_특정 거리의 도시 찾기 {
    public static int n;
    public static int m;
    public static int k;
    public static int x;
    public static int[] depth;
    public static int[] vis;
    public static ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        depth = new int[n+1];
        vis = new int[n+1];
        for(int i=0;i<=n;i++) adj.add(new ArrayList<Integer>());
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int x,y;
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            adj.get(x).add(y);
        }
        vis[x] = 1;
        Queue<Integer>  q = new LinkedList<>();
        q.offer(x);
        while(!q.isEmpty()){
            int now = q.poll();
            for(int i=0;i<adj.get(now).size();i++){
                int next = adj.get(now).get(i);
                if(vis[next]==0){
                    vis[next]=1;
                    depth[next] = depth[now]+1;
                    q.offer(next);
                }
            }
        }

        boolean swc = false;
        for(int i=1;i<=n;i++){
            if(depth[i]==k) {
                swc = true;
                bw.write(String.valueOf(i)+"\n");
            }
        }
        if(!swc) bw.write("-1\n");
        bw.flush();
        br.close();
        bw.close();

    }

}