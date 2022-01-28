import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        int[] sum = new int[n + 1];
        boolean[] targets = new boolean[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i + 1] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i+1]) targets[i] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (targets[i]) sum[i]++;
            sum[i] += sum[i - 1];
        }


        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            int start , end;
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            bw.write((sum[end-1]-sum[start-1])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}