import java.io.*;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

class Pair {
    int idx;
    int value;

    public Pair(int idx, int value) {
        this.idx = idx;
        this.value = value;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        int[] res = new int[n + 1];
        int[] value = new int[1000001];
        Arrays.fill(res,-1);
        Stack<Pair> s = new Stack<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = new Integer(st.nextToken());
            value[arr[i]]++;
        }
        for (int i = 1; i <= n ; i++) {
            int now = arr[i];
            while (!s.isEmpty()) {
                if (value[s.peek().value] >= value[now]) break;
                res[s.pop().idx] = now;
            }
            s.push(new Pair(i, now));
        }

        for (int i = 1; i <=n ; i++) {
            bw.write(res[i] + " ");
        }
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();

    }
}