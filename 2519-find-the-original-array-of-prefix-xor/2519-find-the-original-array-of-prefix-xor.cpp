class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), x = 0;
        vector<int> ans(n);
        for(int i=0; i<n; i++)
            ans[i] = x ^ pref[i], x ^= ans[i];
        return ans;
    }
};