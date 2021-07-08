import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static Queue<Integer> q = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int rest = 0;
        int maxx = -1;
        for(int i=n; i>=1; i--){
            if (k>i-1) {
                q.offer(i);
                k -= i-1;
                continue;
            }
            else if(k==i-1){
                q.offer(i);
                maxx = i-1;
                k = 0;
                break;
            }
            else {
                maxx = i;
                break;
            }
        }
        while (!q.isEmpty()) bw.write( String.valueOf(q.poll())+" ");
        if (maxx != -1){
            int bef = maxx - k - 1;
            for(int i=1; i<=bef; i++) bw.write(String.valueOf(i)+" ");
            bw.write(String.valueOf(maxx)+" ");
            for(int i=1; i<=k; i++) bw.write(String.valueOf(bef+i)+" ");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}