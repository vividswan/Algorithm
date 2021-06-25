import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int sum = 0;
        int diff = (int) 1e9;
        int res = -1;

        for(int i=1; i<=10; i++){
            int now = Integer.parseInt(br.readLine());
            sum+= now;
            int nowDiff = Math.abs(sum-100);
            diff = Math.min(diff, nowDiff);
            if (nowDiff==diff) res = sum;
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}