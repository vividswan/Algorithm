import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Data {
	int bit;
	int x;
	int y;

	public Data(int bit, int x, int y) {
		this.bit = bit;
		this.x = x;
		this.y = y;
	}

}

public class Main {
	static int n, m, res;
	static char[][] map;
	static int[][] dustMap;
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		while (true) {
			res = -1;
			StringTokenizer st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			if (n == 0 && m == 0) break;
			map = new char[n + 1][m + 1];
			dustMap = new int[n + 1][m + 1];
			int cnt = 1;
			int startX = 0;
			int startY = 0;
			for (int i = 1; i <= n; i++) {
				String str = br.readLine();
				for (int j = 1; j <= m; j++) {
					map[i][j] = str.charAt(j - 1);
					if (map[i][j] == '*') {
						dustMap[i][j] = cnt;
						cnt++;
					} else if (map[i][j] == 'o') {
						startX = i;
						startY = j;
					}
				}
			}
			cnt--;
			int len = 1 << cnt;
			int[][][] vis = new int[len][n + 1][m + 1];
			for (int k = 0; k < len; k++) {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						vis[k][i][j] = -1;
					}
				}
			}
			Queue<Data> q = new LinkedList<>();
			q.add(new Data(0, startX, startY));
			vis[0][startX][startY]= 0;
			while (!q.isEmpty()) {
				Data poll = q.poll();
				int nowBit = poll.bit;
				int nowX = poll.x;
				int nowY = poll.y;
				for (int i = 0; i < 4; i++) {
					int nx = nowX + dx[i];
					int ny = nowY + dy[i];
					if(nx<1 || ny <1 || nx > n || ny > m) continue;
					if (map[nx][ny] == 'x') continue;
					int nextBit = nowBit;
					if (dustMap[nx][ny] != 0) {
						nextBit |= 1 << (dustMap[nx][ny] - 1);
					}
					if(vis[nextBit][nx][ny]!=-1) continue;
					vis[nextBit][nx][ny] = vis[nowBit][nowX][nowY] + 1;
					if (nextBit == ((1 << cnt) - 1)) {
						if(res == -1) res = vis[nextBit][nx][ny];
						else res = Math.min(res, vis[nextBit][nx][ny]);
					}
					q.add(new Data(nextBit, nx, ny));
				}
			}
			bw.write(res+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}

}
