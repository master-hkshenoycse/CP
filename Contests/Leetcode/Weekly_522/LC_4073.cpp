#include<bits/stdc++.h>
using namespace std;
class Solution {
    static constexpr long long MOD = 1e9 + 7;

    // returns {F(n), F(n+1)}
    pair<long long, long long> fib(long long n) {
        if (n == 0)
            return {0, 1};

        auto [a, b] = fib(n / 2);

        // F(2k) = F(k) * (2F(k+1) - F(k))
        long long c = a * ((2 * b % MOD - a + MOD) % MOD) % MOD;

        // F(2k+1) = F(k)^2 + F(k+1)^2
        long long d = (a * a % MOD + b * b % MOD) % MOD;

        if (n % 2 == 0)
            return {c, d};

        return {d, (c + d) % MOD};
    }

public:
    int countGoodStrings(long long n) {
        auto [fn, fn1] = fib(n);
        return 2 * fn % MOD;
    }
};