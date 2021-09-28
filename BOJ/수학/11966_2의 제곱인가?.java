import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        boolean isAns = true;
        while (true){
            if (n  ==1 ) break;
            if (n%2==1) {
                isAns = false;
                break;
            }
            n /= 2;
        }
        if (isAns) bw.write(1+"\n");
        else bw.write(0+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}