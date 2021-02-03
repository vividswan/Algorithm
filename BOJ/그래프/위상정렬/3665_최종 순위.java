import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 3665_최종 순위 {
    public static int t,n,m;
    public static boolean[][] outDegree;
    public static int[] inDegree;
    public static int[] rank;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        for(int k=0;k<t;k++){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            outDegree = new boolean[n+1][n+1];
            inDegree = new int[n+1];
            rank = new int[n+1];
            st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n; i++) rank[i] = Integer.parseInt(st.nextToken());
            for(int i=n; i>0; i--){
                inDegree[rank[i]] = i-1;
                for(int j=1;j<i;j++) outDegree[rank[j]][rank[i]] = true;
            }
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            for(int i=0;i<m;i++){
                int x, y;
                st = new StringTokenizer(br.readLine());
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
                if(outDegree[x][y]){
                    outDegree[x][y] = false;
                    outDegree[y][x] = true;
                    inDegree[y]--;
                    inDegree[x]++;
                }
                else {
                    outDegree[x][y] = true;
                    outDegree[y][x] = false;
                    inDegree[x]--;
                    inDegree[y]++;
                }
            }
            Queue<Integer> q = new LinkedList<>();
            Queue<Integer> rankQ = new LinkedList<>();
            boolean isRight = true;
            boolean[] chk = new boolean[n+1];
            for(int i=1;i<=n;i++) if(inDegree[i]==0) q.add(i);
            while(!q.isEmpty()){
                if(q.size()!=1){
                    isRight = false;
                    break;
                }
                int now = q.poll();
                rankQ.add(now);
                chk[now] = true;
                for(int i=1; i<=n; i++){
                    if(i==now) continue;
                    if(outDegree[now][i]){
                        inDegree[i]--;
                        if(inDegree[i]==0) q.offer(i);
                    }
                }
            }
            for(int i=1; i<=n; i++) {
                if(!chk[i]) isRight = false;
            }
            if(isRight){
                while(!rankQ.isEmpty()){
                    bw.write(String.valueOf(rankQ.poll())+" ");
                }
                bw.write("\n");
            }
            else {
                bw.write("IMPOSSIBLE\n");
            }
            bw.flush();
        }
        br.close();
        bw.close();
    }

}