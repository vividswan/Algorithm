import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static long k, res;
    static Map<Long, Long> m;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        m = new HashMap<>();
        long[] sum = new long[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            sum[i] = Long.parseLong(st.nextToken());
            sum[i] += sum[i - 1];
            if(sum[i] == k) res++;
            Long temp = sum[i] - k;
            if (m.containsKey(temp)) {
                res += m.get(temp);
            }
            if(m.containsKey(sum[i])){
                m.put(sum[i], m.get(sum[i]) + 1);
            } else m.put(sum[i], 1L);
        }
        bw.write(res+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}