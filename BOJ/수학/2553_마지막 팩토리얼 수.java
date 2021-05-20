import java.io.*;

public class Main {
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        long res = 1;
        for(int i=2; i<=n; i++){
            res *= i;
            res %= 1000000000000L;
            while (res%10==0){
                res /=10;
            }
        }
        bw.write(String.valueOf(res%10)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}