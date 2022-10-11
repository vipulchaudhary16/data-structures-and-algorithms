import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        int i, num, pos = 0;
        int[] arr = new int[10];
        Scanner s = new Scanner(System.in);

        System.out.print("Enter 10 Elements: ");
        for (i = 0; i < 10; i++)
            arr[i] = s.nextInt();

        System.out.print("Enter an Element to Search: ");
        num = s.nextInt();

        for (i = 0; i < 10; i++) {
            if (num == arr[i]) {
                pos = i + 1;
                break;
            }
        }
        if (pos == 0)
            System.out.println("\nThe element not found!");
        else
            System.out.println("\nThe element found at position: " + pos);
    }
}