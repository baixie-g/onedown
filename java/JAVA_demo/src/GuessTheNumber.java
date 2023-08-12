import java.util.Scanner;

public class GuessTheNumber {
    public static void main(String[] args) {
        int numberToGuess = (int) (Math.random() * 100) + 1;
        int attempts = 0;
        int guess = 0;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to Guess the Number game!");
        System.out.println("I have chosen a number between 1 and 100.");
        System.out.println("Can you guess what it is?");

        while (guess != numberToGuess) {
            System.out.print("Enter your guess: ");
            guess = scanner.nextInt();
            attempts++;

            if (guess < numberToGuess) {
                System.out.println("Too low! Try again.");
            } else if (guess > numberToGuess) {
                System.out.println("Too high! Try again.");
            } else {
                System.out.println("Congratulations! You guessed the number in " + attempts + " attempts.");
            }
        }

        scanner.close();
    }
}
