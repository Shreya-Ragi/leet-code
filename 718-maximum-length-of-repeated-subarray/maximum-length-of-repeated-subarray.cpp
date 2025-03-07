class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int DP[nums1.size()][nums2.size()];
        int max = 0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(i == 0 || j == 0){
                    DP[i][j] = (nums1[i] == nums2[j]);
                }
                else{
                    if(nums1[i] == nums2[j]) DP[i][j] = DP[i-1][j-1] + 1;
                    else DP[i][j] = 0;
                }
                if(DP[i][j] > max) max = DP[i][j];
            }
        }
        // for(int i=0; i<nums1.size(); i++){
        //     for(int j=i; j<nums2.size(); j++){
        //         cout << DP[i][j] << " ";
        //     }
        // }
        return max;
    }
};