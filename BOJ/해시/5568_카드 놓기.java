import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {

    static int n;
    static int k;
    static int[] arr;
    static boolean[] chk;
    static int res;
    static ArrayList<Integer> list;
    static Map<String, Boolean> m;

    static void dfs(int idx, int cnt) {
        if (cnt == k) {
            StringBuilder sb = new StringBuilder();
            for (Integer integer : list) {
                sb.append(arr[integer]);
            }
            String target = sb.toString();
            if (!m.containsKey(target)) {
                res++;
                m.put(target, true);
            }
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            list.add(i);
            dfs(i, cnt + 1);
            list.remove(list.size() - 1);
            chk[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        arr = new int[n + 1];
        chk = new boolean[n + 1];
        m = new HashMap<>();
        list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        dfs(1, 0);
        bw.write(res + "\n");
        bw.flush();
        br.close();
        bw.close();

    }

}
