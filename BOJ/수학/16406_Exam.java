import java.io.*;

public class Main {
    public static int k;
    public static String str1, str2;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        k = Integer.parseInt(br.readLine());
        str1 = br.readLine();
        str2 = br.readLine();
        int same = 0;
        int diff = 0;
        int ans = 0;
        for(int i=0; i<str1.length(); i++){
            if (str1.charAt(i) == str2.charAt(i)) same++;
            else diff++;
        }
        if (same >= k) ans = k + diff;
        else  ans = diff -k + same * 2;
        bw.write(String.valueOf(ans)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}