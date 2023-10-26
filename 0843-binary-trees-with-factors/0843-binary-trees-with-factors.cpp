class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans = 0, mod = 1e9+7;

        unordered_map<long long, long long> mp;
        for(auto it : arr)  mp[it] = 1;

        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                if(arr[i] % arr[j] == 0 && mp.find(arr[i]/arr[j]) != mp.end())
                    mp[arr[i]] = (mp[arr[i]] + 0ll + (mp[arr[i]/arr[j]] * 1ll * mp[arr[j]]) % mod) % mod;

        for(auto it : arr)
            ans = (ans + 0ll + mp[it]) % mod;

        return ans;
    }
};