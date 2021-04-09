import java.util.ArrayList;
import java.util.Collections;

class Node implements Comparable<Node>{
    private int x;
    private int y;
    private int a;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getA() {
        return a;
    }

    public Node(int x, int y, int a){
        this.x = x;
        this.y = y;
        this.a = a;
    }

    @Override
    public int compareTo(Node other) {
        if(this.x != other.x) return Integer.compare(this.x,other.x);
        else if(this.y != other.y) return Integer.compare(this.y,other.y);
        else return Integer.compare(this.a,other.a);
    }
}

class Solution {

    public static ArrayList<Node> list = new ArrayList<>();

    public boolean search(ArrayList<Node> temp){
        for(int i=0; i<temp.size();i++){
            Node node = temp.get(i);
            boolean chk = false;
            int  x = node.getX();
            int y = node.getY();
            int a = node.getA();

            if(a==0) {
                if(y==0) chk = true;
                for(int j=0; j<temp.size();j++){
                    Node side = temp.get(j);
                    if(side.getA()==0 && side.getY()==y-1 && side.getX() == x) chk=true;
                    if(side.getA()==1 && side.getY() ==y && side.getX() == x-1) chk = true;
                    if(side.getA()==1 && side.getY() ==y && side.getX() == x) chk = true;
                }
                if(!chk) return false;
            }
            else {
                boolean right = false;
                boolean left = false;
                for(int j=0; j<temp.size(); j++){
                    Node side = temp.get(j);
                    if(side.getA()==0 && side.getY()==y-1 && (side.getX() == x || side.getX() == x+1)) chk = true;
                    if(side.getA()==1 && side.getY()==y && side.getX()==x+1) right = true;
                    if(side.getA()==1 && side.getY()==y && side.getX()==x-1) left = true;
                }
                if(right && left) chk = true;
                if(!chk) return false;
            }

        }
        return true;
    }

    public boolean isPossible(int x, int y, int a, int b){
        ArrayList<Node> temp = new ArrayList<>();
        for(int i=0; i<list.size();i++){
            temp.add(list.get(i));
        }
        Node node = new Node(x,y,a);
        if(b==1) temp.add(node);
        else {
            for(int i=0; i<temp.size();i++){
                Node now = temp.get(i);
                if(now.getX()==x && now.getY()==y && now.getA() == a) temp.remove(i);
            }
        }
        return search(temp);
    }

    public int[][] solution(int n, int[][] build_frame) {
        for(int i=0; i < build_frame.length; i++){
            int x = build_frame[i][0];
            int y = build_frame[i][1];
            int a = build_frame[i][2];
            int b = build_frame[i][3];
            if(isPossible(x,y,a,b)){
                Node node = new Node(x,y,a);
                if(b==1) list.add(node);
                else {
                    for(int j=0; j<list.size();j++){
                        Node now = list.get(j);
                        if(now.getX()==x && now.getY()==y && now.getA() == a) list.remove(j);
                    }
                }
            }
        }

        Collections.sort(list);


        int[][] answer = new int[list.size()][3];
        for(int i=0; i<list.size();i++){
            answer[i][0] = list.get(i).getX();
            answer[i][1] = list.get(i).getY();
            answer[i][2] = list.get(i).getA();
        }


        return answer;
    }
}