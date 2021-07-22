import java.io.*;

public class Main {
    public static int n;
    public static int[] arr = {500, 100, 50, 10, 5, 1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        int val = 1000 - n;
        int res = 0;
        for(int i=0; i<arr.length; i++){
            res += val/arr[i];
            val %= arr[i];
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}