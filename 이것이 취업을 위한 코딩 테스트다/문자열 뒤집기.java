import java.io.*;
import java.util.StringTokenizer;

public class 문자열 뒤집기 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String str = st.nextToken();

        int[] value = new int[2];
        int now = str.charAt(0) - '0';
        value[now]++;
        for(int i=1;i<str.length();i++){
            int next = str.charAt(i) - '0';
            if(next==now) continue;
            else{
                now = next;
                value[next]++;
            }
        }
        int result = Math.min(value[0],value[1]);
        bw.write(String.valueOf(result));
        bw.flush();
        br.close();
        bw.close();
    }

}