import java.io.*;

public class Main {
    public static int n;
    public static long cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        int now = 0;
        while (true){
            if (Math.pow(10,now)<= n && n < Math.pow(10,now+1)) break;
            else cnt += (now+1) * (Math.pow(10,now+1) - Math.pow(10, now));
            now++;
        }
        cnt += (now+1) * (n - Math.pow(10, now) + 1);
        bw.write(cnt+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}