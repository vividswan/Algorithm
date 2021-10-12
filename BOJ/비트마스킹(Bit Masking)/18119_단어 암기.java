import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static int n, m;
	public static long nowBit = (1L << 27) - 1;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		long[] arr = new long[n + 1];
		for (int i = 1; i <=n ; i++) {
			String now = br.readLine();
			for (int j = 0; j < now.length(); j++) {
				char c = now.charAt(j);
				arr[i] |= 1L << (c - 'a');
			}
		}
		for (int i = 0; i < m; i++) {
			int command;
			char c;
			int cnt = 0;
			st = new StringTokenizer(br.readLine());
			command = Integer.parseInt(st.nextToken());
			c = st.nextToken().charAt(0);
			if (command == 1) {
				nowBit &= ~(1L << (c - 'a'));
			}
			else{
				nowBit |= (1L << (c - 'a'));
			}
			for (int j = 1; j <= n; j++) {
				if ((nowBit & arr[j]) == arr[j]) cnt++;
			}
			bw.write(cnt+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}