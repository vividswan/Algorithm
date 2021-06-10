import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Ball implements Comparable<Ball>{
    private int idx;
    private int color;
    private int weight;

    @Override
    public int compareTo(Ball other){
        return Integer.compare(this.weight,other.weight);
    }

    public int getIdx() {
        return idx;
    }

    public int getColor() {
        return color;
    }

    public int getWeight() {
        return weight;
    }

    public Ball(int idx, int color, int weight){
        this.idx = idx;
        this.color = color;
        this.weight = weight;
    }
}

public class Main {
    public static int n;
    public static ArrayList<Ball> balls = new ArrayList<>();
    public static long[] colorWeight;
    public static long[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        arr = new long[n];
        colorWeight = new long[n+1];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int color = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            balls.add(new Ball(i,color,weight));
        }
        Collections.sort(balls);
        long weightSum = 0;
        int smallWeightIDx = 0;
        for(int i=1; i<n; i++){
            while (true){
                Ball ball = balls.get(smallWeightIDx);
                if (ball.getWeight() >= balls.get(i).getWeight()) break;
                weightSum += ball.getWeight();
                colorWeight[ball.getColor()] += ball.getWeight();
                smallWeightIDx++;
            }
            arr[balls.get(i).getIdx()] = weightSum - colorWeight[balls.get(i).getColor()];
        }
        for(int i=0; i<n; i++){
            bw.write(String.valueOf(arr[i])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}