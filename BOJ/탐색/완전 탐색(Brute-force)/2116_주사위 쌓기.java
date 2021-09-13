import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static int n,res;
    public static int[] match = {0,6,4,5,2,3,1};
    public static ArrayList<ArrayList<Integer>> arrayLists = new ArrayList<ArrayList<Integer>>();
    public static void recursion(int bef, int num,int val){
        if (num==n){
            res = Math.max(res, val);
            return;
        }
        int idx = 0;
        for(int j=1; j<=6;j++){
            if (arrayLists.get(num).get(j)==bef){
                idx = j;
                break;
            }
        }
        int now = 0;
        for(int j=1; j<=6; j++){
            if (j!=idx && j!=match[idx]) now = Math.max(now, arrayLists.get(num).get(j));
        }
        recursion(arrayLists.get(num).get(match[idx]),num+1,val+now );
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arrayLists.add(new ArrayList<>());
            arrayLists.get(i).add(0);
            for(int j=0; j<6; j++) arrayLists.get(i).add(Integer.parseInt(st.nextToken()));
        }
        for(int i=1; i<=6; i++) recursion(i,0,0);
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}