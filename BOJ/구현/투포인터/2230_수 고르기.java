import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static long m;
    public static long[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Long.parseLong(st.nextToken());
        arr = new long[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }

        Arrays.sort(arr);

        int pt1 = 0;
        int pt2 = 0;
        long diff = 2000000000;

        while (true) {
            if(pt1 >= n || pt2 >=n) break;
            long value = arr[pt2] - arr[pt1];
            if(value >= m ){
                diff = Math.min(diff, value);
                pt1++;
            } else pt2++;
        }
        bw.write(diff+"\n");
        bw.flush();
        br.close();
        bw.close();


    }
}