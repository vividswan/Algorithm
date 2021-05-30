import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        int ans = 0;
        if (num % 400 == 0) ans = 1;
        else if(num % 100 == 0) ans = 0;
        else if(num % 4 == 0) ans = 1;
        else ans = 0;

        bw.write(String.valueOf(ans)+"\n");

        bw.flush();
        br.close();
        bw.close();

    }
}