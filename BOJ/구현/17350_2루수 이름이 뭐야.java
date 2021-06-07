import java.io.*;

public class Main {
    public static int n;
    public static boolean chk;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++){
            String str = br.readLine();
            if (str.equals("anj")) chk = true;
        }

        if(chk) bw.write("뭐야;\n");
        else bw.write("뭐야?\n");
        bw.flush();
        br.close();
        bw.close();
    }
}