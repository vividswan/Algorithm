import java.io.*;

class Node{
    private int val;
    private String str;
    public Node(int val, String str){
        this.val = val;
        this.str = str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    public void setVal(int val) {
        this.val = val;
    }

    public int getVal() {
        return val;
    }

    public String getStr() {
        return str;
    }
}

public class Main {
    public static String str1, str2;
    public static int n,m;
    public static Node[][] nodes;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        str1 = br.readLine();
        str2 = br.readLine();
        n = str1.length();
        m = str2.length();
        nodes = new Node[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                nodes[i][j] = new Node(0,"");
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (str1.charAt(i)==str2.charAt(j)){
                    nodes[i+1][j+1].setVal(nodes[i][j].getVal()+1);
                    nodes[i+1][j+1].setStr(nodes[i][j].getStr()+str1.charAt(i));
                }
                else{
                    if(nodes[i+1][j].getVal() >= nodes[i][j+1].getVal()){
                        nodes[i+1][j+1].setVal(nodes[i+1][j].getVal());
                        nodes[i+1][j+1].setStr(nodes[i+1][j].getStr());
                    }
                    else{
                        nodes[i+1][j+1].setVal(nodes[i][j+1].getVal());
                        nodes[i+1][j+1].setStr(nodes[i][j+1].getStr());
                    }
                }
            }
        }
        bw.write(String.valueOf(nodes[n][m].getVal())+"\n");
        bw.write(nodes[n][m].getStr()+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}