import java.io.*;
import java.util.StringTokenizer;

public class 1로 만들기 {
    public static int n;
    public static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        arr = new int[n+1];
        for(int i=2; i<=n; i++) arr[i] = n+1;
        for(int i=1; i<=n; i++){
            if(i*5<=n) arr[i*5] = Math.min(arr[i]+1, arr[i*5]);
            if(i*3<=n) arr[i*3] = Math.min(arr[i]+1, arr[i*3]);
            if(i*2<=n) arr[i*2] = Math.min(arr[i]+1, arr[i*2]);
            if(i+1<=n) arr[i+1] = Math.min(arr[i]+1, arr[i+1]);
        }
        bw.write(String.valueOf(arr[n]));
        bw.flush();
        br.close();
        bw.close();
    }
}