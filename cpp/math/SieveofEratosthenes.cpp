
const int SEIVE_SIZE = 1e5 + 1;
bool prime[SEIVE_SIZE];

void sieve_of_eratosthenes() {
    for (bool & i : prime) i = true;
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i < SEIVE_SIZE; ++i) {
        if(prime[i]) {
            for (int j = i * i; j < SEIVE_SIZE; j += i)
                prime[j] = false;
        }
    }
}
