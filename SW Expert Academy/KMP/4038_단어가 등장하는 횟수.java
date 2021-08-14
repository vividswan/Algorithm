import java.io.*;
import java.util.ArrayList;

public class Solution {
    public static int testCase;
    public static String str1, str2;
    public static ArrayList<Integer> getPi(String p){
        int m = p.length(), j=0;
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            arrayList.add(0);
        }
        for(int i = 1; i< m ; i++){
            while(j > 0 && p.charAt(i) !=  p.charAt(j))
                j = arrayList.get(j-1);
            if(p.charAt(i) == p.charAt(j))
                arrayList.set(i, ++j);
        }
        return arrayList;
    }
    public static int kmp(String s, String p){
        int res = 0;
        ArrayList<Integer> pi = getPi(p);
        int n = s.length(), m = p.length(), j =0;
        for(int i = 0 ; i < n ; i++){
            while(j>0 && s.charAt(i) != p.charAt(j))
                j = pi.get(j-1);
            if(s.charAt(i) == p.charAt(j)){
                if(j==m-1){
                    res++;
                    j = pi.get(j);
                }else{
                    j++;
                }
            }
        }
        return res;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            str1 = br.readLine();
            str2 = br.readLine();
            bw.write("#"+t+" "+kmp(str1, str2)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}