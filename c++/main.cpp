#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 500
#define M 1000000000

using namespace std;

bool isPrime[M + 1];

/**
 * @brief      Initializes the isPrime array.
 */
static void sieve() {
    for (int i = 2; i <= M; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= M; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= M; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

/**
 * @param number - number to check
 * @return part of the sum if both parts are prime and sum to the number or 0 if such parts do not exist
 */
static int getPartOfSum(int number) {
    for (int i = 2; i < number / 2 + 1; i++) {
        if (isPrime[i] && isPrime[number - i]) {
            return i;
        }
    }
    return 0;
}

int main() {
    sieve();
    srand(time(NULL));
    int count = 0;

    for (int i = 0; i < N; i++) {
        int number = rand() % M + 5;
        if (number % 2 == 1) number++;

        int partOfSum = getPartOfSum(number);
        if (partOfSum != 0) {
            cout << partOfSum << " " << number - partOfSum << endl;
            count++;
        }
    }
    cout << count << " out of " << N << " passed" << endl;
    return 0;
}