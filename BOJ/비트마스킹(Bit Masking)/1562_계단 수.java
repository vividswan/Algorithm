import java.io.*;


public class Main {
	public static final int MOD = 1000000000;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int ans = 0;
		int bitNum = 1 << 10;
		long[][][] dp = new long[n + 1][10][bitNum];
		for (int i = 1; i < 10; i++) {
			dp[1][i][1 << i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < bitNum; k++) {
					if (j-1 != -1) {
						int tempBit = (k | (1 << (j - 1)));
						dp[i + 1][j - 1][tempBit] += dp[i][j][k];
						dp[i + 1][j - 1][tempBit] %= MOD;
					}
					if (j + 1 != 10) {
						int tempBit = (k | (1 << (j + 1)));
						dp[i + 1][j + 1][tempBit] += dp[i][j][k];
						dp[i + 1][j + 1][tempBit] %= MOD;
					}
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			ans += dp[n][i][(1 << 10) - 1];
			ans %= MOD;
		}
		bw.write(ans+"\n");
		bw.flush();
		br.close();
		bw.close();
	}
}