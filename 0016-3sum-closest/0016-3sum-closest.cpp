class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Step 1: sort
        sort(nums.begin(), nums.end());

        // Step 2: closest ko initialize karo
        int closest = nums[0] + nums[1] + nums[2];

        // Step 3: i ka loop
        for (int i = 0; i < nums.size() - 2; i++) {

            // Step 4: left and right
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                // Step 5: sum
                int sum = nums[i] + nums[left] + nums[right];

                // Step 6: closest update
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }

                // Step 7: pointer movement
                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    return sum;
                }
            }
        }

        return closest;
    }
};