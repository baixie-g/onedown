import java.util.Scanner;
public class littlesf {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        float a=0;
        while(scanner.hasNextFloat()){
            a+=scanner.nextFloat();
        }
        System.out.println(a);
    }
}
