class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumodd = 1LL * n * n;
        long long sumeven = 1LL * n * (n + 1);

        return __gcd(sumodd, sumeven);
    }
};