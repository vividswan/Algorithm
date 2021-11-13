import java.io.*;
import java.util.Stack;

public class Main {
    static String str;
    static Stack<Integer> s;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        str = br.readLine();
        s = new Stack<>();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= '0' && str.charAt(i) <= '9') {
                s.push(str.charAt(i) - '0');
            }
            else {
                int num2 = s.pop();
                int num1 = s.pop();
                if (str.charAt(i)=='+') s.push(num1 + num2);
                else if (str.charAt(i)=='-') s.push(num1 - num2);
                else if (str.charAt(i)=='*') s.push(num1 * num2);
                else s.push(num1 / num2);
            }
        }
        bw.write(s.pop()+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}