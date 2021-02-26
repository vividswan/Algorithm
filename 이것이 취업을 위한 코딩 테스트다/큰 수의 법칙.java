import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 큰 수의 법칙 {

    public static int n;
    public static int m;
    public static int k;
    public static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());

        for(int i=1; i<=n; i++){
            arr[i-1] =Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        int cnt = m / (k+1);
        int result = cnt*(k*arr[n-1]+arr[n-2]);
        int last = m % (k+1);
        result += last*arr[n-1];
        bw.write(String.valueOf(result)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}