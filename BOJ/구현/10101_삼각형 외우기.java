import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static int n, res;
    private static ArrayList<Integer> arrayList = new ArrayList<>();
    public static void recursion(int val){
        if (arrayList.size()==2){
            res = Math.max(res,val);
            return;
        }
        for(int i=1; i<arrayList.size()-1; i++){
            int plusVal = arrayList.get(i-1) * arrayList.get(i+1);
            int tempVal = arrayList.get(i);
            arrayList.remove(i);
            recursion(val + plusVal);
            arrayList.add(i,tempVal);
        }
    }
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());

        String ans = "";

        if(a==60 && b == 60 && c == 60) ans =  "Equilateral";
        else if(a+b+c==180 && ((a==b) || (b==c) || (c==a))) ans = "Isosceles";
        else if(a+b+c==180 && a!=b && b!=c && a!=c) ans = "Scalene";
        else ans = "Error";



        bw.write(ans +"\n");
        bw.flush();
        br.close();
        bw.close();


    }
}