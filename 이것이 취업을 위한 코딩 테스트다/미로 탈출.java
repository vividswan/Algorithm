import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pair<T>{
    private T first;
    private  T second;
    Pair(T first, T second){
        this.first = first;
        this.second = second;
    }
    public T first(){
        return first;
    }
    public T second(){
        return second;
    }
}

public class 미로 탈출 {

    public static int dx[] = {1,-1,0,0};
    public static int dy[] = {0,0,1,-1};
    public static int map[][] = new int[201][201];
    public static int vis[][] = new int[201][201];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, m;
        n = scanner.nextInt();
        m = scanner.nextInt();
        scanner.nextLine();

        for(int i=0;i<n;i++){
            String str = scanner.nextLine();
            for(int j=0;j<m;j++){
                map[i][j] = str.charAt(j) - '0';
            }
        }

        Queue<Pair<Integer>> q = new LinkedList<>();
        q.offer(new Pair<Integer>(0,0));
        vis[0][0] = 1;
        while(!q.isEmpty()){
            Pair<Integer> pair = q.poll();
            int x = pair.first();
            int y = pair.second();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0||ny<0||nx>n||ny>m) continue;
                if(map[nx][ny] == 0) continue;
                if(vis[nx][ny] != 0) continue;
                vis[nx][ny] = vis[x][y]+1;
                q.offer(new Pair<Integer>(nx,ny));
            }
        }
        System.out.println(vis[n-1][m-1]);
    }
}
