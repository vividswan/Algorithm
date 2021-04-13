import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Node{
    private int x;
    private int y;
    public Node(int x, int y){
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

public class 15686_치킨 배달 {

    public static int n;
    public static int m;
    public static int[] [] map;
    public static ArrayList<Node> chicken = new ArrayList<>();
    public static ArrayList<Node> house = new ArrayList<>();
    public static ArrayList<ArrayList<Integer>> combs = new ArrayList<ArrayList<Integer>>();
    public static boolean[] chk;

    public static int getDis(Node a, Node b){
        int result = 0;
        result+= Math.abs(a.getX() - b.getX());
        result+= Math.abs(a.getY() - b.getY());
        return  result;
    }


    public static void recursion(int idx, int cnt){
        if(cnt == m){
            ArrayList<Integer> arr = new ArrayList<>();
            for(int i=0; i<chk.length; i++){
                if(chk[i]) arr.add(i);
            }
            combs.add(arr);
            return;
        }

        for(int i = idx; i<chk.length; i++){
            if(chk[i]) continue;
            chk[i] = true;
            recursion(i,cnt+1);
            chk[i] = false;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==1) house.add(new Node(i,j));
                else if(map[i][j]==2) chicken.add(new Node(i,j));
            }
        }
        chk = new boolean[chicken.size()];
        recursion(0,0);
        int res = (int)1e9;
        for(int i =0; i<combs.size();i++){
            int value = 0;
            for(int j=0; j<house.size();j++){
                Node houseNode = house.get(j);
                int temp = 0;
                for(int k=0;k<combs.get(i).size();k++){
                    Node chickenNode = chicken.get(combs.get(i).get(k));
                    int dist = getDis(houseNode, chickenNode);
                    if(k==0) temp = dist;
                    else temp = Math.min(dist,temp);
                }
                value += temp;
            }
            res = Math.min(res,value);
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}