class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it : nums) mp[it]++;
        vector<int> v;
        for(auto it : mp)   v.push_back(it.second);
        int e = *min_element(v.begin(), v.end());
        for(int i=e; i>0; i--)  {
            if(isPossible(v, i))   {
                int ans = 0;
                for(auto it : v)    {
                    ans += it / (i+1);
                    if(it % (i+1))  ans++;
                }
                return ans;
            }
        }
        return nums.size();
    }

private :
    bool isPossible(vector<int>& v, int x)  {
        for(auto it : v)
            if(it/x < it%x) return false;
        return true;
    }
};