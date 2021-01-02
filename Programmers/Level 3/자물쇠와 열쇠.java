class Solution {

    public static boolean isSuccsess(int[][] map){
        int size= map.length/3;
        boolean result = true;
        for(int i=size;i<2*size;i++){
            for(int j=size;j<2*size;j++){
                if (map[i][j]!=1) result=false;
            }
        }
        return result;
    }

    public static int[][] rotMap(int[][] map){
        int[][] returnMap = new int[map.length][map.length];
        int mapSize = map.length;
        for(int i=0;i<mapSize;i++){
            for(int j=0;j<mapSize;j++){
                returnMap[i][j] = map[mapSize-j-1][i];
            }
        }
        return returnMap;
    }

    public boolean solution(int[][] key, int[][] lock) {
        int m = key.length;
        int n = lock.length;

        int[][] map = new int[n*3][n*3];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[n+i][n+j] = lock[i][j];
            }
        }

        for(int z=0;z<4;z++){
            key = rotMap(key);
            for(int x=0;x<2*n;x++){
                for(int y=0;y<2*n;y++){
                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            map[x+i][y+j]+=key[i][j];
                        }
                    }
                    if(isSuccsess(map)) return true;
                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            map[x+i][y+j]-=key[i][j];
                        }
                    }
                }
            }
        }

        return false;
    }
}