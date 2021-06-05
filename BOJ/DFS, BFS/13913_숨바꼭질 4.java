import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX = 100000;
    public static int n,k;
    public static int vis[] = new int[MAX+1];
    public static int pre[] = new int[MAX+1];
    public static int[] dx = {-1,1,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i<= MAX; i++){
            vis[i] = -1;
            pre[i] = -1;
        }
        vis[n] = 0;
        pre[n] = n;
        Queue<Integer> q = new LinkedList<>();
        q.offer(n);
        while (!q.isEmpty()) {
            int x = q.poll();
            for (int i = 0; i < 3; i++) {
                int nx = x + dx[i];
                if (i == 2) nx = 2 * x;
                if (nx < 0 || nx > MAX) continue;
                if (vis[nx] != -1) continue;
                vis[nx] = vis[x] + 1;
                pre[nx] = x;
                q.offer(nx);
            }
        }
        bw.write(String.valueOf(vis[k])+"\n");
        Stack<Integer> s = new Stack<>();
        s.push(k);
        while (true){
            if (pre[s.peek()] == s.peek()) break;
            s.push(pre[s.peek()]);
        }
        while (!s.isEmpty()){
            bw.write(String.valueOf(s.pop())+" ");
        }
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}