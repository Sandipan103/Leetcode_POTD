#define vl vector<long long>
#define vvl vector<vl>

class Solution {
public:

    int mod = 1e9 + 7;

    int countVowelPermutation(int n) {

        vvl dp(n, vl(5, 0));
        for(int i=0; i<5; i++)  dp[0][i] = 1;

        for(int i=1; i<n; i++)  {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + 0ll + dp[i-1][2]) % mod;
            dp[i][2] = ((dp[i-1][0] + 0ll + dp[i-1][1]) % mod + 0ll + (dp[i-1][3] + 0ll + dp[i-1][4]) % mod) % mod;
            dp[i][3] = (dp[i-1][2] + 0ll + dp[i-1][4]) % mod;
            dp[i][4] = dp[i-1][0] % mod;
        }

        long long ans = 0;
        for(int i=0; i<5; i++)
            ans = (ans + dp[n-1][i]) % mod;
        return ans;
    }
};