class Solution {
public:
    int smallestNumber(int n, int t) {
        // Iterate from n onwards to find the smallest valid number
        for (int current = n; ; ++current) {
            // Calculate the product of all digits in the current number
            int digitProduct = 1;
            int temp = current;
          
            // Extract each digit and multiply them together
            while (temp > 0) {
                int digit = temp % 10;  // Get the last digit
                digitProduct *= digit;   // Multiply to the product
                temp /= 10;              // Remove the last digit
            }
          
            // Check if the product of digits is divisible by t
            if (digitProduct % t == 0) {
                return current;  // Found the smallest number that satisfies the condition
            }
        }
    }
};