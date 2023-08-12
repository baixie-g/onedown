import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class ComplexCodeExample {
    public static void main(String[] args) {
        // 创建一个列表来存储学生对象
        List<Student> studentList = new ArrayList<>();

        // 添加一些学生对象到列表中
        studentList.add(new Student("John", 20));
        studentList.add(new Student("Alice", 22));
        studentList.add(new Student("Bob", 21));

        // 使用比较器对学生列表进行排序
        Collections.sort(studentList, new Comparator<Student>() {
            @Override
            public int compare(Student s1, Student s2) {
                return s1.getName().compareTo(s2.getName());
            }
        });

        // 创建一个映射来存储学生的成绩
        Map<String, Integer> studentGrades = new HashMap<>();
        studentGrades.put("John", 85);
        studentGrades.put("Alice", 90);
        studentGrades.put("Bob", 75);

        // 遍历学生列表并输出姓名、年龄和成绩
        for (Student student : studentList) {
            String name = student.getName();
            int age = student.getAge();
            int grade = studentGrades.get(name);
            System.out.println("Name: " + name + ", Age: " + age + ", Grade: " + grade);
        }

        // 将学生列表写入文件
        try {
            File file = new File("students.txt");
            FileWriter writer = new FileWriter(file);
            for (Student student : studentList) {
                writer.write(student.getName() + "," + student.getAge() + "\n");
            }
            writer.close();
            System.out.println("Student data written to file successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 学生类
    static class Student {
        private String name;
        private int age;

        public Student(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public String getName() {
            return name;
        }

        public int getAge() {
            return age;
        }
    }
}
