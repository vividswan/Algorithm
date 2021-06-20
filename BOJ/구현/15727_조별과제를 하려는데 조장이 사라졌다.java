import java.io.*;
import java.util.Arrays;

public class Main {
    public static int l;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        l = Integer.parseInt(br.readLine());
        int res = l/5;
        if (l%5 >0) res++;
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}