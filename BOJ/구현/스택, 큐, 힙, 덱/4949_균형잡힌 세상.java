import java.io.*;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true){
            String str = br.readLine();
            if(str.equals(".")) break;
            boolean noFlag = false;
            Stack<Character> s = new Stack<>();
            for(int i=0; i<str.length();i++){
                if (noFlag) break;
                char now = str.charAt(i);
                if(now == '(' || now== '[') s.push(now);
                else if(now == ')' || now == ']'){
                    if(s.empty()){
                        bw.write("no\n");
                        noFlag = true;
                    }
                    else {
                        char sTop = s.pop();
                        if(sTop == '('){
                            if (now != ')'){
                                bw.write("no\n");
                                noFlag = true;
                            }
                        }
                        else{
                            if (now != ']'){
                                bw.write("no\n");
                                noFlag = true;
                            }
                        }
                    }
                }
            }
            if (noFlag) continue;
            if(s.empty()) bw.write("yes\n");
            else bw .write("no\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}