class Solution {
public:
    static const int MOD = 1e9+7;
    int dp[51][51][51];
    int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

    int fun(int i , int j , int m, int n, int k){
        if(i < 0 || j < 0 || i >= m || j >= n) return 1;   // Out of boundary
        if(k == 0) return 0;                               // No moves left

        if(dp[i][j][k] != -1) return dp[i][j][k];

        long long ans = 0;
        for(auto d : dir) {
            ans += fun(i + d[0], j + d[1], m, n, k - 1);
            ans %= MOD;   // apply modulo at every step
        }
        return dp[i][j][k] = (int)ans;
    }

    int findPaths(int m, int n, int k, int r, int c) {
        memset(dp, -1, sizeof(dp));
        return fun(r, c, m, n, k);
    }
};