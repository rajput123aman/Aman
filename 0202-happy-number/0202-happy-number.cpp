class Solution {
public:
    bool isHappy(int n) {

        // Cycle detect karne ke liye
        unordered_set<int> seen;

        while (n != 1) {

            int sum = 0 ;

            while ( n > 0) {

                int digit = n% 10;

                sum += digit * digit;

                n = n/10;
            }

            // Agar number repeat ho gaya
            if (seen.count(sum))
                return false;

            seen.insert(sum);

            n = sum;
        }

        return true;
    }
};