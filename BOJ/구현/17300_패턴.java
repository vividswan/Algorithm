import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int l;
    public static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        l = Integer.parseInt(br.readLine());
        arr = new int[l];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<l ; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        boolean isValid = true;

        boolean[] vis = new boolean[10];
        vis[arr[0]] = true;
        int bef = arr[0];
        for(int i=1; i<l; i++){
            int next = arr[i];
            if(vis[next]) {
                isValid = false;
                break;
            }
            vis[next] = true;

            if(!vis[2]){
                if(next+bef == 4){
                    isValid = false;
                    break;
                }
            }

            if(!vis[4]){
                if((next == 1 && bef == 7) || (next == 7 && bef == 1)){
                    isValid = false;
                    break;
                }
            }

            if(!vis[5]){
                if(next+bef == 10){
                    isValid = false;
                    break;
                }
            }

            if(!vis[6]){
                if((next == 3 && bef == 9) || (next == 9 && bef == 3)){
                    isValid = false;
                    break;
                }
            }

            if(!vis[8]){
                if(next+bef == 16){
                    isValid = false;
                    break;
                }
            }
            bef = next;
        }
        if(isValid) bw.write("YES\n");
        else bw.write("NO\n");
        bw.flush();
        br.close();
        bw.close();
    }
}