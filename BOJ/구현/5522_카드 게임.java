import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int sum = 0;

        for(int i=0; i<5; i++){
            int num = Integer.parseInt(br.readLine());
            sum += num;
        }

        bw.write(String.valueOf(sum)+"\n");

        bw.flush();
        br.close();
        bw.close();

    }
}