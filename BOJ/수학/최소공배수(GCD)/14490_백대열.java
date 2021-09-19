import java.io.*;

public class Main {
    public static int gcb(int a, int b){
        while (b>0){
            int temp = a;
            a = b;
            b = temp%b;
        }
        return a;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] strArr = br.readLine().split(":");
        int a = Integer.parseInt(strArr[0]);
        int b = Integer.parseInt(strArr[1]);
        int val = gcb(a,b);
        bw.write(a/val+":"+b/val+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}