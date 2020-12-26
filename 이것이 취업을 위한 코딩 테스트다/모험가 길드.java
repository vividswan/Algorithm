import java.io.*;
import java.util.StringTokenizer;

public class 모험가 길드 {

    public static int[] value = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st= new StringTokenizer(br.readLine());
        int lastNum = 0;
        for(int i=0;i<n;i++){
            int val = Integer.parseInt(st.nextToken());
            value[val]++;
            lastNum = Math.max(lastNum,val);
        }
        int cnt = 0;
        for(int i=1; i<=lastNum;i++){
            cnt+= value[i]/i;
        }
        bw.write(cnt+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}