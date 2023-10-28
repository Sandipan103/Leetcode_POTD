class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while(i<j)
            if(s[i++] != s[j--])    return false;
        return true;
    }

    string longestPalindrome(string s) {
        int x=0, y=0, l=0, n=s.length();
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                if(j-i+1 > l && isPal(s, i, j))
                    x=i, y=j, l=y-x+1;

        return s.substr(x, y-x+1);
    }
};