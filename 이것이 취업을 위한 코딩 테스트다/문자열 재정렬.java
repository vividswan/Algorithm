import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class 문자열 재정렬 {

    public static String writeFunc(String str){
        List<Character> list = new ArrayList<>();
        int tot = 0;
        for(int i=0;i<str.length();i++){
            char c = str.charAt(i);
            if('0'<= c && c <= '9') tot += c-'0';
            else {
                list.add(c);
            }
        }
        Collections.sort(list);
        String result = "";
        for(int i=0;i<list.size();i++){
            result+=list.get(i);
        }
        result+=tot;
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String str = st.nextToken();
        bw.write(writeFunc(str+"\n"));
        bw.flush();
        br.close();
        bw.close();
    }
}