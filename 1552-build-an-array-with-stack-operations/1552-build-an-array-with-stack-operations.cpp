class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 0, x = 1;
        vector<string> ans;
        while(i < target.size())    {
            if(target[i] == x)  {
                ans.push_back("Push");
                i++;
            }
            else    {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            x++;
        }
        return ans;
    }
};