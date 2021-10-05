import java.io.*;
import java.util.Stack;

class Pair{
    int idx;
    int value;

    public Pair(int idx, int value) {
        this.idx = idx;
        this.value = value;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        Stack<Pair> s = new Stack<>();
        Stack<Pair> valueS = new Stack<>();
        boolean isRight = true;
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ')') {
                if (s.isEmpty()) {
                    isRight = false;
                    break;
                } else if (s.peek().value != 10) {
                    isRight = false;
                    break;
                } else {
                    int beforeIdx = s.pop().idx;
                    int tot = 0;
                    while (!valueS.isEmpty()) {
                        if (valueS.peek().idx < beforeIdx) break;
                        tot += valueS.pop().value;
                    }
                    tot *= 2;
                    if (tot==0) tot = 2;
                    if (s.isEmpty()) sum += tot;
                    else{ valueS.push(new Pair(i, tot));}
                }
            }
            else if (str.charAt(i) == ']') {
                if (s.isEmpty()) {
                    isRight = false;
                    break;
                }
                else if (s.peek().value != 20) {
                    isRight = false;
                    break;
                }
                else {
                    int beforeIdx = s.pop().idx;
                    int tot = 0;
                    while (!valueS.isEmpty()) {
                        if (valueS.peek().idx < beforeIdx) break;
                        tot += valueS.pop().value;
                    }
                    tot *= 3;
                    if (tot==0) tot = 3;
                    if (s.isEmpty()) sum += tot;
                    else {
                        valueS.push(new Pair(i, tot));
                    }
                }
            }
            else{
                if (str.charAt(i) == '(') s.push(new Pair(i, 10));
                else s.push(new Pair(i, 20));
            }
        }
        if (!s.isEmpty()) isRight = false;
        if (!isRight) sum = 0;
        bw.write(sum+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}