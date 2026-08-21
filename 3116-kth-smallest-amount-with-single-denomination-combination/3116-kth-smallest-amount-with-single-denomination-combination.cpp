class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    // Returns number of distinct valid amounts <= x
    ll countAmounts(ll x, vector<int>& coins) {
        int n = coins.size();
        ll count = 0;

        // Iterate through every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {

            ll lcm = 1;
            int selected = 0;

            for (int i = 0; i < n; i++) {

                // Check if coin i is selected
                if (mask & (1 << i)) {

                    selected++;

                    // Calculate LCM safely
                    ll g = gcd(lcm, (ll)coins[i]);

                    // Avoid unnecessary overflow
                    lcm = (lcm / g) * coins[i];

                    // If LCM already exceeds x,
                    // x / lcm will be 0
                    if (lcm > x) break;
                }
            }

            ll multiples = x / lcm;

            // Inclusion-Exclusion
            if (selected % 2 == 1) {
                count += multiples;
            } else {
                count -= multiples;
            }
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();

        // Optional but useful: remove redundant coins
        sort(coins.begin(), coins.end());

        vector<int> filtered;

        for (int coin : coins) {
            bool redundant = false;

            for (int prev : filtered) {
                if (coin % prev == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant) {
                filtered.push_back(coin);
            }
        }

        coins = filtered;

        // Binary search range
        ll low = 1;
        ll high = (ll)coins[0] * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            ll cnt = countAmounts(mid, coins);

            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};