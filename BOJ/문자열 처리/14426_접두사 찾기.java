import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static int n,m;
	public static String[] strs;
	public static String[] finds;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		strs = new String[n];
		finds = new String[m];

		for(int i=0; i<n; i++){
			strs[i] = br.readLine();
		}
		for(int i=0; i<m; i++){
			finds[i] = br.readLine();
		}
		int res = 0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				String now = finds[i];
				String comp = strs[j];
				int len = now.length();
				if (now.equals(comp.substring(0,len))){
					res++;
					break;
				}
			}
		}
		bw.write(String.valueOf(res)+"\n");
		br.close();
		bw.close();
	}
}