import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static long a,b;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());

        if(a>b){
            long temp = a;
            a = b;
            b = temp;
        }

        long res = (b+a) * (b-a+1) / 2L;
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}