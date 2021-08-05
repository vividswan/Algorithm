import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    public static int testCase;
    public static int cnt;
    public static int[] value;
    public static int res;
    public static int[] vis;
    private static boolean haveTwo;
    public static void assignValue(int idx, int recursionCnt) {
        if (recursionCnt == cnt) {
            int nowRes = 0;
            for (int i = 0; i < value.length; i++) {
                nowRes *= 10;
                nowRes += value[i];
            }
            res = Math.max(res, nowRes);
            return;
        }
        if (idx == value.length) {
            if (haveTwo) assignValue(idx, recursionCnt+1);
            else{
                int temp = value[value.length-2];
                value[value.length - 2] = value[value.length - 1];
                value[value.length - 1] = temp;
                assignValue(idx, recursionCnt+1);
                temp = value[value.length-2];
                value[value.length - 2] = value[value.length - 1];
                value[value.length - 1] = temp;
            }
            return;
        }
        int maxNum = 0;
        ArrayList<Integer> nums = new ArrayList<>();
        for (int i = idx + 1; i < value.length; i++) {
            maxNum = Math.max(value[i], maxNum);
        }
        for (int i = idx + 1; i < value.length; i++) {
            if (maxNum == value[i]) nums.add(i);
        }
        if (maxNum <= value[idx]) assignValue(idx+1, recursionCnt);
        else{
            for (Integer num : nums) {
                int temp = value[idx];
                value[idx] = value[num];
                value[num] = temp;
                assignValue(idx+1, recursionCnt+1);
                temp = value[idx];
                value[idx] = value[num];
                value[num] = temp;
            }
        }
        return;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            res = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            String now = st.nextToken();
            cnt = Integer.parseInt(st.nextToken());
            value = new int[now.length()];
            haveTwo = false;
            vis = new int[10];
            for (int i = 0; i < value.length; i++) {
                value[i] = now.charAt(i) - '0';
                vis[value[i]]++;
                if(vis[value[i]]>1) haveTwo = true;
            }
            assignValue(0,0);
            bw.write("#"+t+" "+String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}