import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 정렬된 배열에서 특정 수의 개수 구하기 {
    public static int n,x,ans;
    public static List<Integer> arr;

    public static int getLeftIdx(){
        int lowVal = 0;
        int highVal = arr.size()-1;

        while(lowVal<highVal){
            int mid = (lowVal+highVal)/2;
            if(arr.get(mid)>=x) highVal = mid;
            else lowVal = mid+1;
        }

        return highVal;
    }

    public static int getRightIdx(){
        int lowVal = 0;
        int highVal = arr.size()-1;

        while(lowVal<highVal){
            int mid = (lowVal+highVal)/2;
            if(arr.get(mid)>x) highVal = mid;
            else lowVal = mid+1;
        }

        return highVal;
    }


    public static int returnCnt(){
        int leftVal = getLeftIdx();
        int rightVal = getRightIdx();
        return rightVal - leftVal;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        arr = new ArrayList<>();
        st=  new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr.add(Integer.parseInt(st.nextToken()));
        }

        ans = returnCnt();
        if(ans==0) bw.write("-1");
        else bw.write(String.valueOf(ans));
        bw.flush();
        br.close();
        bw.close();
    }
}