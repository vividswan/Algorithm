import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public  class 14888_연산자 끼워넣기 {

    public static int n;
    public static ArrayList<Integer> arr;
    public static int[] op;
    public static int maxNum = -1000000001;
    public static int minNum = 1000000001;
    public static void dfs(int idx, int value){
        if(idx==n){
            maxNum = Math.max(maxNum,value);
            minNum = Math.min(minNum,value);
            return;
        }

        if(op[0]>0){
            op[0]--;
            dfs(idx+1,value+arr.get(idx));
            op[0]++;
        }
        if(op[1]>0){
            op[1]--;
            dfs(idx+1,value-arr.get(idx));
            op[1]++;
        }
        if(op[2]>0){
            op[2]--;
            dfs(idx+1,value*arr.get(idx));
            op[2]++;
        }
        if(op[3]>0){
            op[3]--;
            dfs(idx+1,value/arr.get(idx));
            op[3]++;
        }


    }

    public static void main(String[] args) throws IOException {
        arr = new ArrayList<>();
        op = new int[4];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            int num = Integer.parseInt(st.nextToken());
            arr.add(num);
        }

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<4;i++) op[i] = Integer.parseInt(st.nextToken());

        dfs(1,arr.get(0));

        bw.write(String.valueOf(maxNum)+"\n");
        bw.write(String.valueOf(minNum)+"\n");

        bw.flush();
        br.close();
        bw.close();


    }

}