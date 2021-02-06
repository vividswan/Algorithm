import java.io.*;
import java.util.StringTokenizer;

public class 못생긴 수 {

    public static int n;
    public static int idxOf2 = 1, idxOf3 = 1, idxOf5 = 1;
    public static int valueOf2 = 2, valueOf3 =3, valueOf5 = 5;
    public static int[] value;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        value = new int[n+1];

        value[1] = 1;

        for(int i=2; i<=n; i++){
            int next = Math.min(valueOf2, Math.min(valueOf3,valueOf5));
            value[i] = next;
            if(next == valueOf2){
                idxOf2++;
                valueOf2 = value[idxOf2] * 2;
            }
            if(next == valueOf3){
                idxOf3++;
                valueOf3 = value[idxOf3] * 3;
            }
            if(next == valueOf5){
                idxOf5++;
                valueOf5 = value[idxOf5] * 5;
            }
        }

        bw.write(String.valueOf(value[n])+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}