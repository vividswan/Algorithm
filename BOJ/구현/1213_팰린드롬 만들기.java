import java.io.*;

public class Main {
    public static String str;
    public static int[] cnt = new int[26];
    public static boolean isPossible = true;
    public static int oddNum=  -1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        str = br.readLine();
        if (str.equals("")) {
            bw.write("I'm Sorry Hansoo\n");
            isPossible = false;
        }
        for(int i=0; i<str.length(); i++){
            int now = str.charAt(i) - 'A';
            cnt[now]++;
        }
        for(int i=0; i<26; i++){
            if(cnt[i]%2==1) {
                if(oddNum != -1){
                    isPossible = false;
                    bw.write("I'm Sorry Hansoo\n");
                    break;
                }
                else oddNum = i;
            }
        }
        if (oddNum != -1) cnt[oddNum]--;
        if(isPossible){
            String ans = "";
            for (int i=0; i<26; i++){
                if (cnt[i]%2==1) continue;
                for(int j=0; j<cnt[i]/2; j++) ans+=(char)(i+'A');
            }
            String reversAns = new StringBuffer(ans).reverse().toString();
            if(oddNum!=-1)  ans+=(char)(oddNum+'A');
            ans += reversAns;
            bw.write(ans+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}