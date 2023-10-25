class Solution {
public:

    int solve(int n, int k) {
        if(n==0)    return 0;
        int x = solve(n-1, k/2);
        if(x==0)    return k%2;
        return !(k%2);
    }
    
    int kthGrammar(int n, int k) {
        return solve(n-1, k-1);
    }
};