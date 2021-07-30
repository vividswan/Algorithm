import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    public static int n;
    public static int m;
    public static ArrayList<String> list;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int t = 1; t <= 10; t++) {
            list = new ArrayList<>();
            n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                list.add(st.nextToken());
            }
            m = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                String next = st.nextToken();
                if (next.equals("I")) {
                    int idx = Integer.parseInt(st.nextToken());
                    int cnt = Integer.parseInt(st.nextToken());
                    int addNum = 0;
                    for (int j = 1; j <= cnt; j++) {
                        list.add(idx+addNum, st.nextToken());
                        addNum++;
                    }
                } else if(next.equals("D")) {
                    int idx = Integer.parseInt(st.nextToken());
                    int cnt = Integer.parseInt(st.nextToken());
                    for (int j = 1; j <= cnt; j++) {
                        list.remove(idx);
                    }
                } else if (next.equals("A")) {
                    int cnt = Integer.parseInt(st.nextToken());
                    for (int j = 1; j <= cnt; j++) {
                        list.add(st.nextToken());
                    }
                }
            }
            bw.write("#"+t+" ");
            for (int i = 0; i < 10; i++) {
                if (i > list.size()-1) break;
                bw.write(list.get(i)+" ");
            }
            bw.write("\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}