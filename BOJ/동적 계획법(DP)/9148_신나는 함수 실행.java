import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int dp[][][] = new int[51][51][51];
    public static int recursion(int a, int b, int c){
        if (a<=0 || b<=0 || c<=0) return 1;
        if (dp[a][b][c] != -1) return dp[a][b][c];
        if (a>20 || b>20 || c>20) return dp[a][b][c] = recursion(20,20,20);
        else if(a < b && b < c) return dp[a][b][c] = recursion(a,b,c-1) + recursion(a,b-1,c-1) - recursion(a,b-1,c);
        else return dp[a][b][c] = recursion(a-1, b, c) + recursion(a-1, b-1, c) + recursion(a-1, b,c-1) - recursion(a-1, b-1, c-1);

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(int i =0; i<= 50; i++){
            for(int j=0; j<=50; j++){
                for(int k=0; k<=50; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (a==-1 && b==-1 && c==-1) break;
            int res = recursion(a,b,c);
            bw.write("w("+a+", "+b+", "+c+") = "+res+"\n");
        }
        bw.flush();
        br.close();
        bw.close();


    }
}