import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] strs = br.readLine().split(",");

        bw.write(String.valueOf(strs.length)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}