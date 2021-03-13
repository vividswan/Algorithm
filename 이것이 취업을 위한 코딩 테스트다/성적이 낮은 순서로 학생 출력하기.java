import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{

    private String name;
    private int score;

    public Node(String name, int score){
        this.name = name;
        this.score = score;
    }

    public String getName() {
        return name;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.score,other.score);
    }
}

public class 성적이 낮은 순서로 학생 출력하기 {
    public static int n;
    public static ArrayList<Node> list = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            list.add(new Node(st.nextToken(), Integer.parseInt(st.nextToken())));
        }
        Collections.sort(list);
        for(int i=0; i<n; i++){
            bw.write(list.get(i).getName()+" ");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}