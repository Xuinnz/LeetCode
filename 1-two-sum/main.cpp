#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int intFirst = nums[i];
        int intSecond = 0;
        int j = 0;
        while (i != nums.size()){
            if (i == j){
                if(j == nums.size()){
                    i++;
                }
                j++;
                continue;
            }
            intFirst = nums[i];
            intSecond = target - intFirst;
            if(intSecond == nums[j]){
                intSecond = nums[j];
                break;
            }
            j++;
            if (j == nums.size()){
                j = 0;
                i++;
            }
        }
        return {i, j};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    
    cout << "Test Case 1: [2, 7, 11, 15], Target: 9" << endl;
    cout << "Result: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    
    cout << "\nTest Case 2: [3, 2, 4], Target: 6" << endl;
    cout << "Result: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}