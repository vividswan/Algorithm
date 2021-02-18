import java.io.*;
import java.util.StringTokenizer;

public class 1929_소수 구하기 {
    public static int m;
    public static int n;
    public static boolean[] vis;
    public static boolean[] notPrime;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        vis = new boolean[n+1];
        notPrime = new boolean[n+1];
        notPrime[1] = true;
        double cnt = Math.sqrt(n);
        for(int i=2; i<=cnt;i++){
            if(vis[i]) continue;
            vis[i] = true;
            for(int j=2;;j++){
                if(j*i>n) break;
                vis[j*i] = true;
                notPrime[j*i] = true;

            }
        }
        for(int i=m; i<=n;i++){
            if(!notPrime[i]) bw.write(String.valueOf(i)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}