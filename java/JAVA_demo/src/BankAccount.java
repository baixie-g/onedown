import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BankAccount {
    private double balance;
    private Lock lock;

    public BankAccount(double initialBalance) {
        balance = initialBalance;
        lock = new ReentrantLock();
    }

    public void deposit(double amount) {
        lock.lock();
        try {
            balance += amount;
            System.out.println("Deposit: " + amount);
            System.out.println("Balance: " + balance);
        } finally {
            lock.unlock();
        }
    }

    public void withdraw(double amount) {
        lock.lock();
        try {
            if (balance >= amount) {
                balance -= amount;
                System.out.println("Withdrawal: " + amount);
                System.out.println("Balance: " + balance);
            } else {
                System.out.println("Insufficient balance");
            }
        } finally {
            lock.unlock();
        }
    }

    public static void main(String[] args) {
        BankAccount account = new BankAccount(1000);

        Thread thread1 = new Thread(() -> {
            account.deposit(500);
        });

        Thread thread2 = new Thread(() -> {
            account.withdraw(800);
        });

        Thread thread3 = new Thread(() -> {
            account.withdraw(600);
        });

        thread1.start();
        thread2.start();
        thread3.start();
    }
}
