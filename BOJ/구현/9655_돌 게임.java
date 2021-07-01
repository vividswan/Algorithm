import java.io.*;

public class Main {
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        if (n%2==1) bw.write("SK\n");
        else bw.write("CY\n");
        bw.flush();
        br.close();
        bw.close();
    }
}