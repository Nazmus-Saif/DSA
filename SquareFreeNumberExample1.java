import java.util.Scanner;

public class SquareFreeNumberExample1 {
    // function that checks if the given number is square free or not
    static boolean isSquareFree(int num) {
        // finds the remainder
        if (num % 2 == 0)
            // divides the given number by 2
            num = num / 2;
        // if the number again completely divisible by 2, the number is not a square
        // free number
        if (num % 2 == 0)
            return false;
        // num must be odd at the moment, so we have increment i by 2
        for (int i = 3; i <= Math.sqrt(num); i = i + 2) {
            // checks i is a prime factor or not
            if (num % i == 0) {
                num = num / i;
                // if the number again divides by i, it cannot be a square free number
                if (num % i == 0)
                    return false;
            }
        }
        return true;
    }

    // driver code
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int num = sc.nextInt();
        // function calling
        if (isSquareFree(num))
            System.out.println(num + " is a square free number.");
        else
            System.out.println(num + " is not a square free number.");
    }
}