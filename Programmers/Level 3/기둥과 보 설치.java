import java.util.ArrayList;
import java.util.Collections;

class Node implements Comparable<Node>{
    private int x;
    private int y;
    private  int article;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getArticle() {
        return article;
    }

    public Node(int x, int y, int article){
        this.x = x;
        this.y = y;
        this.article = article;
    }

    @Override
    public int compareTo(Node other) {
        if(this.x==other.x && this.y == other.y) return Integer.compare(this.article,other.article);
        else if(this.x == other.x) return Integer.compare(this.y, other.y);
        else return Integer.compare(this.x, other.x);
    }
}

class Solution {

    public static boolean chkPossible(){
        for(int i=0;i<result.size();i++){
            ArrayList<Integer> nowNode = result.get(i);
            int x = nowNode.get(0);
            int y = nowNode.get(1);
            int a = nowNode.get(2);

            if(a==0){
                boolean chk = false;
                if(y==0) chk = true;
                for(int j=0; j<result.size();j++){
                    ArrayList<Integer> otherNode = result.get(j);
                    int otherX = otherNode.get(0);
                    int otherY = otherNode.get(1);
                    int otherA = otherNode.get(2);
                    if(otherA==0){
                        if(otherX==x && otherY==y-1) chk = true;
                    }
                    else {
                        if(otherX==x && otherY==y) chk = true;
                        else if(otherX==x-1 && otherY==y) chk = true;
                    }
                }
                if(chk==false) return false;
            }
            else if(a==1){
                boolean chk = false;
                boolean le = false;
                boolean ri = false;
                if(y==0) chk = true;
                for(int j=0; j<result.size();j++){
                    ArrayList<Integer> otherNode = result.get(j);
                    int otherX = otherNode.get(0);
                    int otherY = otherNode.get(1);
                    int otherA = otherNode.get(2);
                    if(otherA==0){
                        if(otherX==x && otherY == y-1) chk = true;
                        if(otherX==x+1 && otherY == y-1) chk = true;
                    }
                    else {
                        if(otherX==x-1 && otherY == y) le = true;
                        if(otherX==x+1 && otherY == y) ri = true;
                    }
                }
                if(le&&ri) chk = true;
                if(chk==false) return false;
            }
        }
        return true;
    }

    public static ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();

    public int[][] solution(int n, int[][] build_frame) {

        for(int i=0;i<build_frame.length;i++){
            int x = build_frame[i][0];
            int y = build_frame[i][1];
            int a = build_frame[i][2];
            int b = build_frame[i][3];

            if(b==1){
                ArrayList<Integer> nowNode = new ArrayList<>();
                nowNode.add(x);
                nowNode.add(y);
                nowNode.add(a);
                result.add(nowNode);
                if(!chkPossible()) result.remove(result.size()-1);
            }
            else if(b==0){
                int idx = 0;
                for(int j=0;j<result.size();j++){
                    if(x==result.get(j).get(0)&&y==result.get(j).get(1)&&a==result.get(j).get(2)){
                        idx = j;
                        break;
                    }
                }
                ArrayList<Integer> nowNode = result.get(idx);
                result.remove(idx);
                if(!chkPossible()) result.add(nowNode);
            }


        }

        ArrayList<Node> list = new ArrayList<>();

        for(int i = 0; i<result.size();i++){
            list.add(new Node(result.get(i).get(0),result.get(i).get(1),result.get(i).get(2)));
        }

        Collections.sort(list);

        int[][] answer = new int[list.size()][3];
        for(int i=0;i<list.size();i++){
            answer[i][0] = list.get(i).getX();
            answer[i][1] = list.get(i).getY();
            answer[i][2] = list.get(i).getArticle();
        }
        return answer;
    }
}