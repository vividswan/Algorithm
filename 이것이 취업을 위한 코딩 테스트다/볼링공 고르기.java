import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Pair{
    private int value;
    private int  cnt;

    public Pair(int value){
        this.value = value;
        this.cnt = 1;
    }

    public int getValue() {
        return value;
    }

    public int getCnt() {
        return cnt;
    }

    public void cntPlus(){
        this.cnt++;
    }
}

public class 볼링공 고르기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        List<Pair> list = new ArrayList<>();
        list.add(new Pair(arr[0]));
        int now = arr[0];
        for(int i=1;i<n;i++){
            if(now!=arr[i]){
                list.add(new Pair(arr[i]));
                now = arr[i];
            }
            else{
                list.get(list.size()-1).cntPlus();
            }
        }
        int tot=0;
        for(int i=0;i<list.size();i++) tot += list.get(i).getCnt();
        int result = 0;
        for(int i=0;i<list.size()-1;i++){
            tot -= list.get(i).getCnt();
            result += list.get(i).getCnt() * tot;
        }
        bw.write(String.valueOf(result));
        br.close();
        bw.close();
    }
}