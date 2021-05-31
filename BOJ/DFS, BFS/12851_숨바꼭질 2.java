import java.io.*;
import java.util.*;

public class Main {
    public static int n,k,res;
    public static final int MAX = 100000;
    public static final int INF = (int)1e9;
    public static int[] dx = {1,-1};
    public static int[] vis = new int[MAX+1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        if (k==n){
            bw.write("0\n");
            bw.write("1\n");
        }
        else{
            Arrays.fill(vis,-1);
            vis[k] = INF;
            vis[n] = 0;
            Queue<Integer> q = new LinkedList<>();
            q.offer(n);
            while (!q.isEmpty()){
                int  x = q.poll();
                for(int i=0; i<3; i++){
                    int nx = 0;
                    if(i==2) nx = x*2;
                    else nx = x + dx[i];
                    if (nx>MAX || nx < 0 ) continue;
                    else if (nx==k ){
                        if (vis[x]+1 < vis[nx]){
                            res = 1;
                            vis[nx] = vis[x]+1;
                        }
                        else if (vis[x]+1 == vis[nx]){
                            res++;
                        }
                    }
                    else if (vis[nx]==-1 || vis[nx]>=vis[x]+1) {
                        vis[nx] = vis[x] + 1;
                        q.offer(nx);
                    }
                }
            }
            bw.write(String.valueOf(vis[k])+"\n");
            bw.write(String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}