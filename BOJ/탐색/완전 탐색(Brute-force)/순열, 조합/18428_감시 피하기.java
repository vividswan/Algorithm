import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Node{
    private int x;
    private int y;

    public Node(int x,int y){
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

public class Main {

    public static int n;
    public static char[][] map;
    public static ArrayList<Node> arrayList = new ArrayList<>();
    public static ArrayList<ArrayList<Integer>> comb = new ArrayList<ArrayList<Integer>>();
    public static boolean[] chk;
    public static int size;
    public static boolean isPossible;
    public static ArrayList<Node> teachers = new ArrayList<>();
    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {-1,1,0,0};

    public static boolean getAns(ArrayList<Integer> nowComb){
        char[][] tempMap = new char[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                tempMap[i][j] = map[i][j];
            }
        }
        for(int i=0; i<nowComb.size();i++){
            Node node = arrayList.get( nowComb.get(i));
            tempMap[node.getX()][node.getY()] = 'O';
        }

        for(int i=0; i<teachers.size();i++){
            Node node = teachers.get(i);
            for(int j=0; j<4; j++){
                int x = node.getX();
                int y =node. getY();
                while(true){
                    x += dx[j];
                    y += dy[j];
                    if(x<1||y<1||x>n||y>n) break;
                    if(tempMap[x][y]=='O') break;
                    if(tempMap[x][y]=='T') break;
                    if(tempMap[x][y]=='S') return false;
                }
            }
        }
        return true;
    }
    public static void recursion(int idx, int cnt){
        if(cnt==3){
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=0; i<size;i++){
                if (chk[i]) temp.add(i);
            }
            comb.add(temp);
            return;
        }
        for(int i=idx; i<size;i++){
            if(!chk[i]){
                chk[i] = true;
                recursion(i,cnt+1);
                chk[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        map = new char[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = st.nextToken().charAt(0);
                if (map[i][j] == 'X') {
                    arrayList.add(new Node(i, j));
                }
                else if(map[i][j]=='T'){
                    teachers.add(new Node(i,j));
                }
            }
        }
        size = arrayList.size();
        chk = new boolean[size];
        recursion(0, 0);
        for(int i=0; i < comb.size(); i++){
            if(isPossible) break;
            ArrayList<Integer> nowComb = comb.get(i);
            isPossible = getAns(nowComb);
        }

        if(isPossible) bw.write("YES\n");
        else bw.write("NO\n");
        bw.flush();
        br.close();
        bw.close();
    }
}