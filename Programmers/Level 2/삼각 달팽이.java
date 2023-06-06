import java.util.ArrayList;

class Solution {
	public static int[] dx = {-1,0,1};
	public static int[] dy = {0,1,-1};

	public static int[][] initArray(int size) {
		int[][] array = new int[size+1][size+1];
		for (int i = 1; i <= size; i++){
			for (int j = 1; j <= size; j++){
				array[i][j] = -1;
			}
		}
		return array;
	}

	public static int[][] processCircle(int[][] array, int size) {
		int x = size + 1;
		int y = 1;
		int dir = 0;
		int nowCount = 0;
		int circleCount = size * (size + 1) / 2;
		while (true) {
			nowCount++;
			if (nowCount > circleCount) {
				break;
			}
			int nextX = x + dx[dir];
			int nextY = y + dy[dir];
			if (nextX < 1 || nextY < 1 || nextX > size || nextY > size || array[nextX][nextY] != -1) {
				dir++;
				if (dir > 2) {
					dir = 0;
				}
				nextX = x + dx[dir];
				nextY = y + dy[dir];
			}
			array[nextX][nextY] = nowCount;
			x = nextX;
			y = nextY;
		}

		return array;
	}

	public static ArrayList<Integer> getAnsArray(int[][] array, int size){
		ArrayList<Integer> integers = new ArrayList<>();
		for (int i = size; i >= 1; i--){
			for (int j = 1; j <= size; j++){
				if (array[i][j] != -1) {
					integers.add(array[i][j]);
				}
			}
		}
		return integers;
	}

	public int[] solution(int n) {
		int[][] array = initArray(n);
		array = processCircle(array, n);
		ArrayList<Integer> integers = getAnsArray(array, n);
		int[] answer = new int[integers.size()];
		for (int i =0; i < answer.length; i++) {
			answer[i] = integers.get(i);
		}
		return answer;
	}
}


