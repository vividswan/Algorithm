import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long sum = 0;
        sum += Long.parseLong(st.nextToken());
        sum += Long.parseLong(st.nextToken());
        sum += Long.parseLong(st.nextToken());
        bw.write(String.valueOf(sum)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}