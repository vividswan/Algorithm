import java.io.*;
import java.util.*;

public class Main {

	public static int n, m;
	public static Map<String ,Boolean> map = new HashMap<>();
	public static ArrayList<String > arr = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for(int i=0; i<n; i++){
			String now = br.readLine();
			map.put(now, true);
		}
		for(int i=0; i<m; i++){
			String now = br.readLine();
			if(map.containsKey(now)) arr.add(now);
		}
		Collections.sort(arr);
		bw.write(String.valueOf(arr.size())+"\n");
		for(int i=0; i<arr.size(); i++) bw.write(arr.get(i)+"\n");
		bw.flush();
		br.close();
		bw.close();
	}
}