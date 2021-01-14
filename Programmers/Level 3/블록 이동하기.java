import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

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

class Robot{
    private Position position1;
    private Position position2;
    private boolean isHorizon;
    private int num;

    public Robot(Position position1, Position position2, int num){
        this.position1 = position1;
        this.position2 = position2;
        this.num = num;
        if(position1.getX()== position2.getX()) this.isHorizon = true;
        else this.isHorizon = false;
    }

    public Position getPosition1() {
        return position1;
    }

    public Position getPosition2() {
        return position2;
    }

    public boolean isHorizon() {
        return isHorizon;
    }

    public int getNum() {
        return num;
    }
}

class Solution {

    public static int n;
    public static int[][] map;
    public static  int resultVal = (int) 1e9;
    public static int[][][][] vis;

    public ArrayList<Robot> move(Robot robot){
        Position position1 = robot.getPosition1();
        Position position2 = robot.getPosition2();

        int num = robot.getNum();
        int x1 = position1.getX();
        int y1 = position1.getY();
        int x2 = position2.getX();
        int y2 = position2.getY();

        ArrayList<Robot> result = new ArrayList<>();

        if(robot.isHorizon()){
            if(x1-1>=0){
                if(map[x1-1][y1]==0 && map[x2-1][y2]==0){
                    if(vis[x1-1][y1][x2-1][y2]==0){
                        result.add(new Robot(new Position(x1-1,y1), new Position(x2-1,y2),num+1));
                        vis[x1-1][y1][x2-1][y2]=vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(x1+1<n){
                if(map[x1+1][y1]==0 && map[x2+1][y2]==0){
                    if(vis[x1+1][y1][x2+1][y2]==0){
                        result.add(new Robot(new Position(x1+1,y1), new Position(x2+1,y2),num+1));
                        vis[x1+1][y1][x2+1][y2]=vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(y2+1<n) {
                if (map[x2][y2+1]==0) {
                    if (vis[x2][y2][x2][y2 + 1] == 0) {
                        result.add(new Robot(position2, new Position(x2, y2 + 1),num+1));
                        vis[x2][y2][x2][y2+1] = vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(y1-1>=0) {
                if (map[x1][y1-1]==0) {
                    if (vis[x1][y1 - 1][x1][y1] == 0) {
                        result.add(new Robot(new Position(x1,y1-1),position1,num+1));
                        vis[x1][y1 - 1][x1][y1] = vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(x1-1>=0) {
                if (map[x1-1][y1]==0) {
                    if (vis[x1-1][y1 ][x1][y1] == 0) {
                        if(map[x2-1][y2]==0){
                            result.add(new Robot(new Position(x1-1,y1),position1,num+1));
                            vis[x1-1][y1][x1][y1] = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
            if(x2-1>=0) {
                if (map[x2-1][y2]==0) {
                    if (vis[x2-1][y2 ][x2][y2] == 0) {
                        if(map[x1-1][y1]==0){
                            result.add(new Robot(new Position(x2-1,y2),position2,num+1));
                            vis[x2-1][y2][x2][y2] = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
            if(x1+1<n) {
                if (map[x1+1][y1]==0) {
                    if (vis[x1][y1][x1+1][y1 ] == 0) {
                        if(map[x1+1][y1+1]==0){
                            result.add(new Robot(position1,new Position(x1+1,y1),num+1));
                            vis[x1][y1][x1+1][y1] = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
            if(x2+1<n) {
                if (map[x2+1][y2]==0) {
                    if (vis[x2][y2][x2+1][y2 ] == 0) {
                        if(map[x2+1][y2-1]==0){
                            result.add(new Robot(position2,new Position(x2+1,y2),num+1));
                            vis[x2][y2][x2+1][y2] = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
        }
        else{
            if(y1-1>=0){
                if(map[x1][y1-1]==0 && map[x2][y2-1]==0){
                    if(vis[x1][y1-1][x2][y2-1]==0){
                        result.add(new Robot(new Position(x1,y1-1), new Position(x2,y2-1),num+1));
                        vis[x1][y1-1][x2][y2-1]=vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(y1+1<n){
                if(map[x1][y1+1]==0 && map[x2][y2+1]==0){
                    if(vis[x1][y1+1][x2][y2+1]==0){
                        result.add(new Robot(new Position(x1,y1+1), new Position(x2,y2+1),num+1));
                        vis[x1][y1+1][x2][y2+1]=vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(x2+1<n){
                if(map[x2+1][y2]==0){
                    if(vis[x2][y2][x2+1][y2]==0){
                        result.add(new Robot(position2,new Position(x2+1,y2),num+1));
                        vis[x2][y2][x2+1][y2] = vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(x1-1>=0){
                if(map[x1-1][y1]==0){
                    if(vis[x1-1][y1][x1][y1]==0){
                        result.add(new Robot(new Position(x1-1,y1),position1,num+1));
                        vis[x1-1][y1][x1][y1] = vis[x1][y1][x2][y2]+1;
                    }
                }
            }
            if(y1+1<n){
                if(map[x1][y1+1]==0){
                    if(vis[x1][y1][x1][y1+1]==0){
                        if(map[x2][y2+1]==0){
                            result.add(new Robot(position1,new Position(x1,y1+1),num+1));
                            vis[x1][y1][x1][y1+1] = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
            if(y2+1<n){
                if(map[x2][y2+1]==0){
                    if(vis[x2][y2][x2][y2+1]==0){
                        if(map[x1][y1+1]==0){
                            result.add(new Robot(position2,new Position(x2,y2+1),num+1));
                            vis[x2][y2][x2][y2+1] = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
            if(y1-1>=0){
                if(map[x1][y1-1]==0){
                    if(vis[x1][y1-1][x1][y1]==0){
                        if(map[x2][y2-1]==0){
                            result.add(new Robot(new Position(x1,y1-1),position1,num+1));
                            vis[x1][y1-1][x1][y1] = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
            if(y2-1>=0){
                if(map[x2][y2-1]==0){
                    if(vis[x2][y2-1][x2][y2]==0){
                        if(map[x1][y1-1]==0){
                            result.add(new Robot(new Position(x2,y2-1),position2,num+1));
                            vis[x2][y2-1][x2][y2]  = vis[x1][y1][x2][y2]+1;
                        }
                    }
                }
            }
        }
        return result;
    }

    public int solution(int[][] board) {
        n = board.length;
        map = board;
        vis = new int[board.length][board.length][board.length][board.length];
        Queue<Robot> q = new LinkedList<>();
        q.offer(new Robot(new Position(0,0), new Position(0,1),0));
        vis[0][0][0][1] = 1;
        while(!q.isEmpty()){
            Robot robot = q.poll();
            if(robot.getPosition2().getX()==n-1&&robot.getPosition2().getY()==n-1) resultVal = Math.min(resultVal,robot.getNum());
            ArrayList<Robot> moveReturn = move(robot);
            for(int i=0;i<moveReturn.size();i++){
                q.offer(moveReturn.get(i));
            }
        }
        return resultVal;
    }
}