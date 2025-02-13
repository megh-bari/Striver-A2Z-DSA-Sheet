vector<int> spf;
    
void sieve() {
    spf.resize(100001, 1);  // Initialize vector with size and value
    spf[0] = spf[1] = 0;
    
    for (int i = 2; i <= 100000; i++) {
        if (spf[i] == 1) {
            spf[i] = i;  // Mark prime numbers with themselves
            for (int j = i; j <= 100000; j += i) {
                if (spf[j] == 1) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> findPrimeFactors(int N) {
    vector<int> factors;
    while (N != 1) {
        factors.push_back(spf[N]);
        N /= spf[N];
    }
    return factors;
}