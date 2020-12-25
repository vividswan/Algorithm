import java.io.*;
import java.util.StringTokenizer;

public class 곱하기 혹은 더하기 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String s = st.nextToken();

        long res = s.charAt(0)-'0';
        for(int i=1;i<s.length();i++){
            long now = s.charAt(i) - '0';
            if(res<=1 || now<=1) res+=now;
            else res*=now;
        }
        bw.write(String.valueOf(res));
        bw.flush();
        br.close();
        bw.close();
    }
}