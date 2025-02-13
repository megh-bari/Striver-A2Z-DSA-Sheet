// using Sieve of Eratosthenes algorithm

int countPrimes(int n) {
    if (n <= 2)
        return 0;

    vector<int> isPrime(n, 1);
    isPrime[0] = isPrime[1] = false;

    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j = 2 * i; j < n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    return count;
}