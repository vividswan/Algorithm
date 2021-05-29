import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static int n, cnt;
    public static ArrayList<Integer> wantTallMan = new ArrayList<>();
    public static ArrayList<Integer> wantSmallMan = new ArrayList<>();
    public static ArrayList<Integer> wantTallGirl = new ArrayList<>();
    public static ArrayList<Integer> wantSmallGirl = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            int now = Integer.parseInt(st.nextToken());
            if(now<0) wantSmallMan.add(Math.abs(now));
            else wantTallMan.add(now);
        }

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            int now = Integer.parseInt(st.nextToken());
            if(now<0) wantSmallGirl.add(Math.abs(now));
            else wantTallGirl.add(now);
        }

        Collections.sort(wantTallMan);
        Collections.sort(wantTallGirl);
        Collections.sort(wantSmallGirl);
        Collections.sort(wantSmallMan);

        int i =0;
        int j = 0;
        while(i<wantSmallMan.size() && j<wantTallGirl.size()){
            if(wantSmallMan.get(i)>wantTallGirl.get(j)){
                cnt++;
                i++;
                j++;
            }
            else i++;
        }

        i = 0;
        j = 0;
        while(i<wantSmallGirl.size() && j<wantTallMan.size()){
            if(wantSmallGirl.get(i)>wantTallMan.get(j)){
                cnt++;
                i++;
                j++;
            }
            else i++;
        }
        bw.write(String.valueOf(cnt)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}