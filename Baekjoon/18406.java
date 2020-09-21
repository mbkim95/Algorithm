import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        String n = scan.nextLine();
        int left = 0;
        int right = 0;

        for (int i = 0; i < n.length() / 2; i++) left += (n.charAt(i) - '0');
        for (int i = n.length() / 2; i < n.length(); i++) right += (n.charAt(i) - '0');

        if (left == right) System.out.println("LUCKY");
        else System.out.println("READY");
    }
}