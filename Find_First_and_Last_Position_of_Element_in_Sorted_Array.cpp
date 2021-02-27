class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int length = nums.size(), lowIndex = 0, midIndex = length / 2, highIndex = length - 1;
        
        vector <int> finalResult = {-1, -1};
        
        if (length < 1) {
            return finalResult;
        }
        
        while (lowIndex <= highIndex) {
            if (nums[midIndex] == target && (midIndex == 0 || nums[midIndex - 1] != target) ) {
                finalResult[0] = midIndex;
                break;
            }
            else if (nums[midIndex] < target) {
                lowIndex = midIndex + 1;
                midIndex = (highIndex + lowIndex) / 2;
            }
            else {
                highIndex = midIndex - 1;
                midIndex = (highIndex + lowIndex) / 2;
            }
        } 
        
        lowIndex = 0, midIndex = length / 2, highIndex = length - 1;
        
        while (lowIndex <= highIndex) {
            if (nums[midIndex] == target && (midIndex == length - 1 || nums[midIndex + 1] != target) ) {
                finalResult[1] = midIndex;
                break;
            }
            else if (nums[midIndex] > target) {
                highIndex = midIndex - 1;
                midIndex = (highIndex + lowIndex) / 2;
            }
            else {
                lowIndex = midIndex + 1;
                midIndex = (highIndex + lowIndex) / 2;
            }
        }
        
        return finalResult;
    }
};