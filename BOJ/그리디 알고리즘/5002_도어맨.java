import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int res = 0;
        int man = 0;
        int girl = 0;
        char[] array = new char[str.length()];
        for (int i = 0; i < array.length; i++) {
            array[i] = str.charAt(i);
        }
        for (int i = 0; i < str.length(); i++) {
            if (Math.abs(man - girl) > n) break;
            boolean needNext = false;
            if (array[i]=='M'){
                if (Math.abs(man+1 - girl) > n){
                    needNext = true;
                }
            }
            else {
                if (Math.abs(man- (girl+1)) > n){
                    needNext = true;
                }
            }
            if (needNext){
                if (i == str.length()-1) break;
                else {
                    if (array[i+1]=='M') man++;
                    else girl++;
                    char temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }
            else {
                if (array[i]=='M') man++;
                else girl++;
            }
            if (Math.abs(man - girl) > n) break;
            res++;
        }
        bw.write(res+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}