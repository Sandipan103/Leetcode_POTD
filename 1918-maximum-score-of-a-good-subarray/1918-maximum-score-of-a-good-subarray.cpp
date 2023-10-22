class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int mini = nums[k], maxi = nums[k], n = nums.size();
        int i=k-1, j=k+1, cnt = 1;

        while(i>=0 && j<n)  {
            cnt++;
            if(nums[i] < nums[j]) mini = min(mini, nums[j++]);
            else mini = min(mini, nums[i--]);
            maxi = max(maxi, cnt*mini);
        }

        while(i>=0) {
            cnt++;
            mini = min(mini, nums[i--]);
            maxi = max(maxi, cnt*mini);
        }

        while(j<n)  {
            cnt++;
            mini = min(mini, nums[j++]);
            maxi = max(maxi, cnt*mini);
        }

        return maxi;
    }
};