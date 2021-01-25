import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Work {
    private int time;
    private int value;

    public int getTime() {
        return time;
    }

    public int getValue() {
        return value;
    }

    Work(int time, int value){
        this.time = time;
        this.value = value;
    }
}

public class 14501_퇴사 {
    public static int n;
    public static ArrayList<Work> list;
    public static int[] dp;
    public static int maxVal;

    public static void main(String[] args) throws IOException {
        list = new ArrayList<>();
        list.add(new Work(0,0));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n =Integer.parseInt(st.nextToken());
        dp = new int[n+2];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());
            list.add(new Work(time, value));
        }

        for(int i=n;i>0;i--){
            int nowTime = list.get(i).getTime();
            int nowValue = list.get(i).getValue();
            if(i+nowTime-1<=n){
                dp[i] = Math.max(maxVal,nowValue+dp[i+nowTime]);
                maxVal = Math.max(maxVal,dp[i]);
            }
            else dp[i] = maxVal;
        }
        bw.write(String.valueOf(maxVal)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}