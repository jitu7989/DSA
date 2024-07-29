#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    vector<int> primes;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

class Solution {
public:
    int nonSpecialCount(int l, int r) {

        int max_prime = static_cast<int>(sqrt(r));
        vector<int> primes = sieve_of_eratosthenes(max_prime);

        set<int> special_numbers;
        for (int prime : primes) {
            int special_number = prime * prime;
            if (l <= special_number && special_number <= r) {
                special_numbers.insert(special_number);
            }
        }

        int total_count = r - l + 1;
        int non_special_count = total_count - special_numbers.size();

        return non_special_count;
    }
};