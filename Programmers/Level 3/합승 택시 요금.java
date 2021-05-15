class Solution {
    public static int[][] dist;
    public static final int INF = (int)1e9;

    public int solution(int n, int s, int a, int b, int[][] fares) {
        dist = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (i==j) continue;
                else dist[i][j] = INF;
            }
        }
        for(int i=0; i<fares.length; i++){
            int x =fares[i][0];
            int y =fares[i][1];
            int value =fares[i][2];
            dist[x][y] = value;
            dist[y][x] = value;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(dist[i][k] != INF && dist[k][j] != INF){
                        if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int answer = INF;
        for(int i=1; i<=n; i++){
            if(dist[i][a] != INF && dist[i][b] != INF){
                answer = Math.min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
            }
        }

        return answer;
    }
}