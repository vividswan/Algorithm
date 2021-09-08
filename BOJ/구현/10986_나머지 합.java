import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static long n,m;
    public static long sum;
    public static long[] groups;
    public static long res;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st  = new StringTokenizer(br.readLine());

        n = Long.parseLong(st.nextToken());
        m = Long.parseLong(st.nextToken());

        groups = new long[(int)m];

        st = new StringTokenizer(br.readLine());
        for(int i =0; i<n; i++){
            long now = Long.parseLong(st.nextToken());
            sum += now;
            sum %= m;
            if (sum == 0) res++;
            groups[(int)sum]++;
        }
        for(int i=0; i<m; i++){
            res += (groups[i]) * (groups[i]-1) / 2;
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}