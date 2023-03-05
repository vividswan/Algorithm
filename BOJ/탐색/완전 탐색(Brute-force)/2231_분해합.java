import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.StreamTokenizer;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int targetNumber = Integer.parseInt(st.nextToken());
		int result = 0;
		for (int i = 0; i < targetNumber; i++) {
			int tempNumber = i;
			int nowTarget = i;
			while (tempNumber > 0) {
				nowTarget += tempNumber % 10;
				tempNumber = tempNumber / 10;
			}
			if (nowTarget == targetNumber) {
				result = i;
				break;
			}
		}
		bw.write(result+"\n");
		bw.close();
		br.close();
	}
}
