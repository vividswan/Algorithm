import java.io.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        Stack<Integer> s = new Stack<>();
        while (n>0){
            if (n%2==1) s.push(1);
            else s.push(0);
            n /= 2;
        }
        int cnt = 0;
        long res = 0;
        while (!s.isEmpty()){
            res += Math.pow(2,cnt) * s.pop();
            cnt++;
        }
        bw.write(String.valueOf(res));
        bw.flush();
        br.close();
        bw.close();
    }
}