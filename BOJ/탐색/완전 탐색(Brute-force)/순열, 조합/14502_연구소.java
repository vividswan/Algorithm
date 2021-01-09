
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Combination{
    private int n;
    private int m;
    private ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
    public Combination(int n, int m){
        this.n = n;
        this.m = m;
    }

    public ArrayList<ArrayList<Integer>> getResult(){
        return result;
    }

    public void getCombi(int[] arr, int depth, int idx, int target){
        if(depth==m){
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=0;i<m;i++){
                temp.add(arr[i]);
            }
            result.add(temp);
            return;
        }
        else if(target==n) return;
        else{
            arr[idx] = target;
            getCombi(arr,depth+1,idx+1,target+1);
            getCombi(arr,depth,idx,target+1);
        }
    }
}


class Position{
    private int x;
    private int y;
    public Position(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class 14502_연구소 {

    public static int[][] map;
    public static int n,m;
    public static ArrayList<Position> list = new ArrayList<>();
    public static ArrayList<Position> virus = new ArrayList<>();
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {1,-1,0,0};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j =1; j<=m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==0) list.add(new Position(i,j));
                if(map[i][j]==2) virus.add(new Position(i,j));
            }
        }

        Combination combination = new Combination(list.size(),3);
        combination.getCombi(new int[3],0,0,0);
        ArrayList<ArrayList<Integer>> combiResult = combination.getResult();

        int result = 0;

        for(int i=0;i<combiResult.size();i++){
            int sum = 0;
            ArrayList<Integer> nowCombi = combiResult.get(i);
            int[][] nowMap = new int[n+1][m+1];
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++){
                    nowMap[j][k] = map[j][k];
                }
            }
            Queue<Position> q = new LinkedList<>();
            for(int j=0;j<virus.size();j++) q.offer(virus.get(j));
            for(int j=0;j<nowCombi.size();j++){
                nowMap[list.get(nowCombi.get(j)).getX()][list.get(nowCombi.get(j)).getY()] = 1;
            }
            while(!q.isEmpty()){
                Position position = q.poll();
                for(int j=0;j<4;j++){
                    int nx = position.getX()+dx[j];
                    int ny = position.getY()+dy[j];
                    if(nx<1||ny<1||nx>n||ny>m) continue;
                    if(nowMap[nx][ny]!=0) continue;
                    nowMap[nx][ny] = 2;
                    q.offer(new Position(nx,ny));
                }
            }
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++){
                    if(nowMap[j][k]==0) sum++;
                }
            }
            result = Math.max(result,sum);
        }
        bw.write(String.valueOf(result));
        bw.flush();
        br.close();
        bw.close();
    }
}