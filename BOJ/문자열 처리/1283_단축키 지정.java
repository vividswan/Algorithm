import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
	public static String[] strs;
	public static boolean[] vis = new boolean[100];
	public static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());

		strs = new String[n+1];

		for(int i=1; i<=n; i++){
			st = new StringTokenizer(br.readLine());
			String res = "";
			boolean isSolved = false;
			while(st.hasMoreTokens()){
				String now = st.nextToken();
				if(!isSolved){
					if(!vis[now.toUpperCase(Locale.ROOT).charAt(0)-'A']){
						vis[now.toUpperCase(Locale.ROOT).charAt(0)-'A'] = true;
						now = "["+now.charAt(0)+"]" + now.substring(1);
						isSolved = true;
					}
				}
				res+=now;
				if(st.hasMoreTokens()) res+=" ";
			}
			if(!isSolved){
				for(int j=0; j < res.length(); j++){
					if(res.charAt(j) == ' ') continue;
					char now = res.toUpperCase(Locale.ROOT).charAt(j);
					if(!vis[now-'A']){
						vis[now-'A'] = true;
						res = res.substring(0,j)+"["+res.charAt(j)+"]"+res.substring(j+1);
						break;
					}
				}
			}
			strs[i] = res;
			bw.write(strs[i]+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}