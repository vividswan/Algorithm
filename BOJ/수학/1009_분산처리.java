import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        t = Integer.parseInt(st.nextToken());
        for(int i=0; i<t; i++){
            st = new StringTokenizer(br.readLine());
            int a, b;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            Queue<Integer> q = new LinkedList<>();
            int num = a%10;
            q.offer(num);
            while (true){
                num = (num*a)%10;
                if(num==q.peek()) break;
                q.offer(num);
            }
            b %= q.size();
            ArrayList<Integer> arr = new ArrayList<>();
            while (!q.isEmpty()) arr.add(q.poll());
            int now;
            if(b==0) now = arr.get(arr.size()-1);
            else now = arr.get(b-1);
            if(now==0) now = 10;
            bw.write(String.valueOf(now)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}