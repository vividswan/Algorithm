import java.io.*;

public class Main {
    public static int k;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        k = Integer.parseInt(br.readLine());

        for(int i=0; i<k; i++) bw.write("1");
        for(int i=1; i<k; i++) bw.write("0");
        bw.write("\n");
        bw.flush();
        br.close();
        br.close();

    }
}