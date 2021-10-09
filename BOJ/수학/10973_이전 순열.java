import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st  = new StringTokenizer(br.readLine());
        arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int searchIdx = -1;
        int swapIdx = -1;
        boolean isLast = true;
        for(int i=0; i<n-1; i++){
            if (arr[i]>arr[i+1]){
                isLast = false;
                break;
            }
        }

        if (!isLast){
            for(int i= n-2; i>=0; i--){
                if (arr[i] > arr[i+1]) {
                    searchIdx = i;
                    break;
                }
            }
            for(int i=n-1; i>=0; i--){
                if (arr[searchIdx] >  arr[i]){
                    swapIdx = i;
                    break;
                }
            }
            int temp = arr[searchIdx];
            arr[searchIdx] = arr[swapIdx];
            arr[swapIdx] = temp;
            Stack<Integer> s = new Stack<>();
            for(int i=searchIdx+1; i<n; i++){
                s.push(arr[i]);
            }
            for(int i=searchIdx+1; i<n; i++){
                arr[i] = s.pop();
            }
            for(int i=0; i<n; i++){
                bw.write(String.valueOf(arr[i])+" ");
            }
        }
        else{
            bw.write("-1");
        }
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}