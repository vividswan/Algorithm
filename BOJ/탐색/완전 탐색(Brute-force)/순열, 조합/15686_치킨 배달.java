import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Combi{
    private int n;
    private int m;
    public Combi(int n, int m){
        this.n = n;
        this.m = m;
    }

    public ArrayList<ArrayList<Integer>> getResult(){
        return result;
    }

    ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();

    public void getCombi(int arr[], int depth, int idx, int target){
        if(m==depth){
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=0;i<m;i++){
                temp.add(arr[i]);
            }
            result.add(temp);
        }
        if(target==n) return;
        arr[idx] = target;
        getCombi(arr,depth+1,idx+1,target+1);
        getCombi(arr,depth,idx,target+1);
    }

}

class Position{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public  Position(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class 15686_치킨 배달 {
    public static int[][] map;
    public static int n;
    public static int m;
    public static int ans = (int) 1e9;

    public static ArrayList<Position> house = new ArrayList<>();
    public static ArrayList<Position> store = new ArrayList<>();

    public static int getDist(Position a, Position b){
        return Math.abs(a.getX()-b.getX()) + Math.abs(a.getY()-b.getY());
    }

    public static int getValue(ArrayList<Integer> arr){
        int total = 0;
        for(int i=0;i<house.size();i++){
            Position nowHouse = house.get(i);
            int nowVal = (int) 1e9;
            for(int j=0;j<arr.size();j++){
                Position now = store.get(arr.get(j));
                nowVal = Math.min(nowVal,getDist(now,nowHouse));
            }
            total += nowVal;
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));



        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==1) house.add(new Position(i,j));
                if(map[i][j]==2) store.add(new Position(i,j));
            }
        }

        Combi combi = new Combi(store.size(),m);
        combi.getCombi(new int[store.size()],0,0,0);
        ArrayList<ArrayList<Integer>> combiArr = combi.getResult();
        for(int i=0;i<combiArr.size();i++){
            ArrayList<Integer> now = combiArr.get(i);
            ans = Math.min(ans,getValue(now));
        }
        bw.write(String.valueOf(ans));
        bw.flush();
        br.close();
        bw.close();
    }
}