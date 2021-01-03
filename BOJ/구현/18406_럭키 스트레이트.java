import java.io.*;
import java.util.StringTokenizer;

public class 18406_럭키 스트레이트 {

    public static boolean chkFunc(String str){
        int tot1 = 0;
        for(int i=0;i<str.length()/2;i++){
            char c = str.charAt(i);
            tot1 += c-'0';
        }

        int tot2 = 0;
        for(int i=str.length()/2;i<str.length();i++){
            char c = str.charAt(i);
            tot2+=c-'0';
        }

        if(tot1==tot2) return true;
        else return false;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String str = st.nextToken();
        if(chkFunc(str)) bw.write("LUCKY\n");
        else bw.write("READY\n");
        bw.flush();
        br.close();
        bw.close();
    }
}