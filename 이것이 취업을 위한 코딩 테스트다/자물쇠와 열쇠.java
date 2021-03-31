class Solution {
    public static int n;
    public static int m;
    public static boolean isAns(int[][] map, int[][] key, int x, int y){
        int[][] nowMap = new int[3*n][3*n];
        for(int i=0; i<3*n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                nowMap[i][j] = map[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0; j<m; j++){
                nowMap[i+x][j+y] += key[i][j];
            }
        }

        boolean isAns = true;
        for(int i=n; i<2*n;i++){
            if(!isAns) break;
            for(int j=n; j<2*n;j++){
                if(nowMap[i][j]!=1) {
                    isAns = false;
                    break;
                }
            }
        }
        return isAns;
    }

    public static int[][] rotate(int[][] map){
        int n = map.length;
        int[][] rotMap = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                rotMap[i][j] = map[n-j-1][i];
            }
        }
        return rotMap;
    }
    public boolean solution(int[][] key, int[][] lock) {
        n = lock.length;
        m = key.length;
        boolean answer = false;
        int[][] map = new int[3*n][3*n];
        for(int i=n; i<2*n; i++){
            for(int j=n; j<2*n; j++){
                map[i][j] = lock[i-n][j-n];
            }
        }
        for(int i=0; i<2*n;i++){
            for(int j=0; j<2*n;j++){
                for(int k=0;k<4;k++){
                    key = rotate(key);
                    if(isAns(map,key,i,j)) return true;
                }
            }
        }
        return answer;
    }
}