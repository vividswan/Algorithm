import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main{
	public static int getDecompositionSum(int value){
		int sum = value;
		String valueString = String.valueOf(value);
		for (int i = 0; i < valueString.length(); i++) {
			char now = valueString.charAt(i);
			sum += now - '0';
		}
		return sum;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int num = Integer.parseInt(st.nextToken());
		int ans = 0;
		for (int i = 1; i <= num; i++) {
			if (getDecompositionSum(i) == num) {
				ans = i;
				break;
			}
		}
		bw.write(ans+"\n");
		bw.flush();
		br.close();
		bw.close();
	}
}
