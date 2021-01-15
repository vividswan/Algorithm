import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Student implements Comparable<Student>{
    private String name;
    private int kor;
    private int eng;
    private int math;

    public Student(String name, int kor, int eng, int math){
        this.name = name;
        this.kor = kor;
        this.eng = eng;
        this.math = math;
    }

    @Override
    public int compareTo(Student other) {
        if(this.kor != other.kor) return Integer.compare(other.kor,this.kor);
        else if(this.eng != other.eng) return Integer.compare(this.eng, other.eng);
        else if(this.math != other.math) return Integer.compare(other.math, this.math);
        else return this.name.compareTo(other.name);
    }

    public String getName() {
        return name;
    }
}

public class 1082_국영수 {
    public static int n;
    public static ArrayList<Student> students;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        students = new ArrayList<>();
        for(int i = 0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int kor = Integer.parseInt(st.nextToken());
            int eng = Integer.parseInt(st.nextToken());
            int math = Integer.parseInt(st.nextToken());
            students.add(new Student(name,kor,eng,math));
        }
        Collections.sort(students);
        for(int i=0;i<n;i++) bw.write(students.get(i).getName()+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}