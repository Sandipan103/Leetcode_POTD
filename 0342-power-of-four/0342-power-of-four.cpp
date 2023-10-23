class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)    return false;
        int total_bit = (int)log2(n)+1;
        int set_bit = __builtin_popcount(n);
        return (set_bit == 1) && (total_bit%2 == 1);
    }
};