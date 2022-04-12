import java.util.Random;

public class Main {

    private static final int N = 500;
    private static final int M = 1000000000;
    private static final boolean[] isPrime = sieve(M);

    public static void main(String[] args) {
        int count = 0;

        for (int i = 0; i < N; i++) {
            int a = new Random().nextInt(M) + 5;
            if (a % 2 == 1) a++;

            final var partOfSum = getPartOfSum(a);
            if (partOfSum != 0) {
                System.out.println(partOfSum + " " + (a - partOfSum));
                count++;
            }
        }

        System.out.println(count + " out of " + N + " passed");
    }

    private static boolean[] sieve(int max) {
        boolean[] isPrime = new boolean[max + 1];

        for (int i = 2; i <= max; i++) {
            isPrime[i] = true;
        }

        for (int i = 2; i * i <= max; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= max; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return isPrime;
    }

    private static int getPartOfSum(int number) {
        for (int i = 2; i < number / 2 + 1; i++) {
            if (isPrime[i] && isPrime[number - i]) {
                return i;
            }
        }
        return 0;
    }
}
