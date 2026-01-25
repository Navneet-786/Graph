class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int currIndex = 0;

        
        int j = currIndex;
        int ans = INT_MIN;
        while(j < n){
            while(currIndex< n && nums[currIndex]==0){
                currIndex++;
                j++;
            }

            while(j<n && nums[j]==1)j++;
            ans = max(ans, j-currIndex);
            currIndex = j;

        }
    return ans;
    }
};