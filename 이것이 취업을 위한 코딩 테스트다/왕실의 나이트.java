import java.io.*;
import java.util.StringTokenizer;

public class 왕실의 나이트 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String str = st.nextToken();
        int y = str.charAt(0) - 'a' + 1;
        int x = str.charAt(1) - '0';
        int dx[] = {-2, -2, 1, -1, 1, -1, 2, 2,};
        int dy[] = {-1,1,2,2,-2,-2,1,-1};
        int result = 0;
        for(int i=0; i<8; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<1||ny<1||nx>8||ny>8) continue;
            result++;
        }
        bw.write(String.valueOf(result)+"\n");
        bw.flush();
        bw.close();
        br.close();
    }
}