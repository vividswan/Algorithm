import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 먹을 것인가 먹힐 것인가 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        for(int i=0;i<t;i++){
            st = new StringTokenizer(br.readLine());
            int aCnt = Integer.parseInt(st.nextToken());
            int bCnt = Integer.parseInt(st.nextToken());
            int[] aArr = new int[aCnt];
            int[] bArr = new int[bCnt];
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<aCnt;j++){
                aArr[j]=Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<bCnt;j++){
                bArr[j]=Integer.parseInt(st.nextToken());
            }
            Arrays.sort(aArr);
            Arrays.sort(bArr);
            int aPtr = 0;
            int result = 0;
            for(int j=0;j<bCnt;j++){
                if(aPtr!=aCnt) {
                    while (true) {
                        if ((aArr[aPtr] > bArr[j])) break;
                        aPtr++;
                        if (aPtr == aCnt) break;
                    }
                }
                result+=aCnt-aPtr;
            }
            bw.write(String.valueOf(result)+"\n");
        }
        br.close();
        bw.close();
    }
}