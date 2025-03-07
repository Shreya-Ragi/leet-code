class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        auto left = nums.begin();
        auto right = nums.begin();
        int min = INT_MAX;
        int sum = 0;
        while(right != nums.end() && left != nums.end()){
            sum += *right;
            if(sum >= target){
                if(right - left + 1 < min) min = right - left + 1;
                sum -= *left;
                sum -= *right;
                left++;
                continue;
            }
            right++;
        }
        if(min == INT_MAX) return 0;
        return min;
    }
};