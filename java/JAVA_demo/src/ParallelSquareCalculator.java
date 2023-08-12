import java.util.Arrays;

public class ParallelSquareCalculator {

    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // 创建线程数组，每个线程负责计算一个数字的平方
        SquareCalculatorThread[] threads = new SquareCalculatorThread[numbers.length];

        // 创建并启动线程
        for (int i = 0; i < numbers.length; i++) {
            threads[i] = new SquareCalculatorThread(numbers[i]);
            threads[i].start();
        }

        // 等待所有线程执行完毕
        for (SquareCalculatorThread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // 获取计算结果
        int[] squares = new int[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            squares[i] = threads[i].getResult();
        }

        // 打印结果
        System.out.println("Numbers: " + Arrays.toString(numbers));
        System.out.println("Squares: " + Arrays.toString(squares));
    }

    static class SquareCalculatorThread extends Thread {
        private int number;
        private int result;

        public SquareCalculatorThread(int number) {
            this.number = number;
        }

        public int getResult() {
            return result;
        }

        @Override
        public void run() {
            result = number * number;
            System.out.println("Square of " + number + ": " + result);
        }
    }
}
