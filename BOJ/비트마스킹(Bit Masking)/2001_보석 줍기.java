import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
	int idx;
	int cnt;
	int bit;

	public Pair(int idx, int cnt, int bit) {
		this.idx = idx;
		this.cnt = cnt;
		this.bit = bit;
	}

}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n, m, k;
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int last = (1 << k);
		int[][] map = new int[n + 1][1 << k];
		int[][] bridge = new int[n+1][n+1];
		int[] jewel = new int[n+1];
		Arrays.fill(jewel, -1);
		for (int i = 0; i < k; i++) {
			int idx = Integer.parseInt(br.readLine());
			jewel[idx] = i;
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			bridge[a][b] = c;
			bridge[b][a] = c;
		}
		int tempBitNum = 0;
		int tempCnt = 0;
		if (jewel[1]!=-1){
			tempBitNum |= (1 << jewel[1]);
			tempCnt++;
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <last ; j++) {
				map[i][j] = -1;
			}
		}
		map[1][tempBitNum] = tempCnt;
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(1, tempCnt, tempBitNum));
		q.add(new Pair(1, 0, 0));
		while (!q.isEmpty()) {
			Pair poll = q.poll();
			int idx = poll.idx;
			int cnt = poll.cnt;
			int bitNum = poll.bit;
			for (int i = 1; i <= n ; i++) {
				if(i==idx || bridge[idx][i]==0) continue;
				if (bridge[idx][i] < cnt) continue;
				if (map[i][bitNum] ==-1){
					map[i][bitNum] = cnt;
					q.add(new Pair(i, cnt, bitNum));
				}
				int nextCnt = cnt;
				int nextBitNum = bitNum;
				if (jewel[i]!=-1){
					if ((nextBitNum & (1 << jewel[i])) == 0) {
						nextCnt++;
						nextBitNum |= (1 << jewel[i]);
					}
				}
				if (map[i][nextBitNum]!=-1) continue;
				map[i][nextBitNum] = nextCnt;
				q.add(new Pair(i, nextCnt, nextBitNum));
			}
		}
		int res = 0;
		for (int i = 0; i < last; i++) {
			res = Math.max(res, map[1][i]);
		}
		bw.write(res+"\n");
		bw.flush();
		br.close();
		bw.close();
	}
}