import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
		int n = Integer.parseInt(stringTokenizer.nextToken());
		int x = Integer.parseInt(stringTokenizer.nextToken());
		stringTokenizer = new StringTokenizer(bufferedReader.readLine());
		while (stringTokenizer.hasMoreTokens()) {
			int now = Integer.parseInt(stringTokenizer.nextToken());
			if (now < x)
				bufferedWriter.write(now+" ");
		}
		bufferedWriter.flush();
		bufferedReader.close();
		bufferedWriter.close();
	}
}
