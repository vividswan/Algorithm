import java.io.*;
import java.util.StringTokenizer;

public class 1이 될 때까지 {

    public static int n;
    public static int m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int cnt = 0;
        while(true){
            if(n==1) break;
            cnt++;
            if(n%m==0){
                n /= m;
                continue;
            }
            else n -= 1;
        }

        bw.write(String.valueOf(cnt));
        bw.flush();
        br.close();
        bw.close();

    }
}