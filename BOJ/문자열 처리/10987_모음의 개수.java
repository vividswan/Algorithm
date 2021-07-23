import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String str = br.readLine();
		int cnt = 0;
		for(int i=0; i<str.length();i++){
			char now = str.charAt(i);
			if (now == 'a'  ||  now == 'e' || now ==  'i' || now == 'o' || now == 'u') cnt++;
		}
		bw.write(String.valueOf(cnt)+"\n");
		bw.flush();
		bw.close();
	}
}

