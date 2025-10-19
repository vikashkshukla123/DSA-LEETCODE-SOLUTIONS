class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            if (nums[i] == val) {
                // move j left until we find a non-val element
                while (j >= i && nums[j] == val) {
                    j--;
                }
                if (i < j) {
                    swap(nums[i], nums[j]);
                    j--;
                } else {
                    break; // i and j crossed, stop
                }
            }
            i++;
        }

        return j + 1; // new length = last valid index + 1
    }
};
