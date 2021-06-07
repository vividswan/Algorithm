import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX = 1000;
    public static boolean[] vis = new boolean[MAX+1];
    public static boolean[] vis2 = new boolean[MAX+1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            int now = Integer.parseInt(st.nextToken());
            if (now>=0)  vis[now] = true;
            else vis2[now*-1] = true;
        }

        for(int i=MAX; i>0; i--){
            if (vis2[i]) bw.write(String.valueOf(-1*i)+" ");
        }

        for(int i=0; i<=MAX; i++){
            if (vis[i]) bw.write(String.valueOf(i)+" ");
        }
        bw.write("\n");

        bw.flush();
        br.close();
        bw.close();

    }
}