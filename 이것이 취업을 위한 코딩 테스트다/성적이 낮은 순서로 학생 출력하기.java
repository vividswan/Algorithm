import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Student implements Comparable<com.company.Student>{

    Student(String name, int score){
        this.name = name;
        this.score = score;
    }

    private String name;
    private int score;

    public String getName(){
        return name;
    }

    @Override
    public int compareTo(com.company.Student other) {
        if(this.score < other.score){
            return -1;
        }
        return 1;
    }
}

public class 성적이 낮은 순서로 학생 출력하기{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        n = scanner.nextInt();
        List<com.company.Student> students = new ArrayList<>();
        for(int i=0;i<n;i++){
            String name;
            name = scanner.next();
            int score;
            score = scanner.nextInt();
            students.add(new com.company.Student(name,score));
        }
        Collections.sort(students);
        for(int i=0;i<students.size();i++){
            System.out.print(students.get(i).getName()+" ");
        }
    }
}