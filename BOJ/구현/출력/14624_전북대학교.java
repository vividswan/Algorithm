import java.io.*;

public class Main {
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        if (n%2==0){
            bw.write("I LOVE CBNU\n");
        }
        else{
            for (int i = 0; i < n; i++) {
                bw.write('*');
            }
            bw.write('\n');
            int len = n / 2;
            for (int i = 0; i < n - 1; i++) {
                if (len ==-1) break;
                for (int j = 0; j < len; j++) {
                    bw.write(' ');
                }
                if (i==0) bw.write('*');
                else{
                    bw.write('*');
                    for (int j = 0; j < 2*i-1 ; j++) {
                        bw.write(' ');
                    }
                    bw.write('*');
                }
                bw.write('\n');
                len--;
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}