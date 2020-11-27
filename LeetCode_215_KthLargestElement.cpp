class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int finalIndex = nums.size() - k;

        while(left < right) {
            int pivot = partition(nums, left, right);
            if(pivot < finalIndex){
                left = pivot + 1;
            }
            else if (pivot > finalIndex) {
                right = pivot - 1;
            }
            else {
                break;
            }
        }

        return nums[finalIndex];
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};