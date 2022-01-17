import java.io.*;
import java.util.Stack;

public class Main {
    public static Stack<Character> s = new Stack<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String target = br.readLine();
        String comp = br.readLine();
        for(int i=0; i<target.length(); i++){
            s.push(target.charAt(i));
            if (s.size()>= comp.length()){
                boolean isRight = true;
                int cnt = 0;
                for(int j=comp.length()-1; j>=0;j--){
                    if(s.get(s.size()-1-cnt) != comp.charAt(j)){
                        isRight = false;
                        break;
                    }
                    cnt++;
                }
                if (isRight){
                    for(int j=0; j< comp.length();j++) s.pop();
                }
            }
        }
        if (s.isEmpty()) bw.write("FRULA\n");
        else{
            StringBuilder sb = new StringBuilder();
            while (!s.isEmpty()){
                sb.append(s.pop());
            }
            bw.write(sb.reverse().toString()+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}