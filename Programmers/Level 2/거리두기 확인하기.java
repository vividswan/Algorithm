import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Node{
    private int x;
    private int y;
    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }
}

class Solution {
    public static int[] dx = {0,0,-1, 1};
    public static int[] dy = {-1, 1, 0 ,0};
    public static boolean isRight(Node node){
        Queue<Node> q = new LinkedList<>();
        int[][] vis = new int[5][5];
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                vis[i][j] = -1;
            }
        }
        q.offer(node);
        vis[node.getX()][node.getY()]=0;
        while(!q.isEmpty()){
            Node now = q.poll();
            int x = now.getX();
            int y = now.getY();
            if(vis[x][y]==2) continue;
            for(int i=0;i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||ny<0||nx>=5||ny>=5) continue;
                if(vis[nx][ny]!=-1) continue;
                if (map[nx][ny]=='X') continue;
                if(map[nx][ny]=='P') return false;
                vis[nx][ny] = vis[x][y] + 1;
                q.offer(new Node(nx,ny));
            }
        }
        return true;
    }
    public static ArrayList<Integer> arr = new ArrayList<>();
    public static char[][] map;
    public int[] solution(String[][] places) {

        for(int k=0; k<places.length; k++){
            boolean isAns = true;
            String[] place = places[k];
            map = new char[5][5];
            Stack<Node> s = new Stack<>();
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    char now = place[i].charAt(j);
                    map[i][j] = now;
                    if (now=='P') s.push(new Node(i,j));
                }
            }
            while(!s.empty()){
                Node node = s.pop();
                if(isRight(node)!=true){
                    arr.add(0);
                    isAns = false;
                    break;
                }
            }
            if(isAns) arr.add(1);
        }
        int[] answer = new int[arr.size()];
        for(int i=0; i < arr.size(); i++) answer[i] = arr.get(i);
        System.out.println(arr);
        return answer;
    }
}