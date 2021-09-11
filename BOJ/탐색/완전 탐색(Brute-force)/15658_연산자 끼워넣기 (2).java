import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[] val;
    public static int[] oper = new int[4];
    public static int maxVal = -(int)2e9;
    public static int minVal = (int)2e9;
    public static void recursion(int cnt, int num){
        if (cnt==n){
            maxVal = Math.max(maxVal, num);
            minVal = Math.min(minVal,num);
            return;
        }
        if (oper[0]>0){
            oper[0]--;
            recursion(cnt+1, num+val[cnt]);
            oper[0]++;
        }

        if (oper[1]>0){
            oper[1]--;
            recursion(cnt+1, num-val[cnt]);
            oper[1]++;
        }

        if (oper[2]>0){
            oper[2]--;
            recursion(cnt+1, num*val[cnt]);
            oper[2]++;
        }

        if (oper[3]>0){
            oper[3]--;
            recursion(cnt+1, num/val[cnt]);
            oper[3]++;
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        val = new int[n];
        for(int i=0; i<n; i++){
            val[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<4; i++){
            oper[i] = Integer.parseInt(st.nextToken());
        }

        recursion(1, val[0]);
        bw.write(String.valueOf(maxVal)+"\n");
        bw.write(String.valueOf(minVal)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}