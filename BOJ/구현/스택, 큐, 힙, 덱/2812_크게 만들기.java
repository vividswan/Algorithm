import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static int n,k;
    public static Stack<Character> s = new Stack<>();
    public static Stack<Character> reverseS = new Stack<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int cnt = n-k;

        String str = br.readLine();
        String res = "";

        for(int i = 0; i<str.length(); i++){
            int now = str.charAt(i) - '0';
            while(!s.isEmpty() && k >0){
                int stackVal = s.peek() - '0';
                if(stackVal<now) {
                    s.pop();
                    k--;
                    continue;
                }
                break;
            }
            s.push(str.charAt(i));
        }
        while (!s.isEmpty()) {
            reverseS.push(s.pop());
        }
        while (!reverseS.isEmpty() && cnt > 0){
            bw.write(reverseS.pop());
            cnt--;
        }
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();

    }
}