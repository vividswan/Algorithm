import java.io.*;
import java.util.*;

public class Main {
	public static int n;
	public static Set<String> s = new HashSet<>();
	private static BufferedReader br;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		for(int i=0; i<n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			String status = st.nextToken();
			if (status.equals("enter")) s.add(name);
			else s.remove(name);
		}
		ArrayList<String> arrayList = new ArrayList<>();
		Iterator<String> it =  s.iterator();
		while (it.hasNext()){
			String now = it.next();
			arrayList.add(now);
		}
		Collections.sort(arrayList);
		for(int i =arrayList.size()-1; i>=0; i--){
			bw.write(arrayList.get(i)+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}