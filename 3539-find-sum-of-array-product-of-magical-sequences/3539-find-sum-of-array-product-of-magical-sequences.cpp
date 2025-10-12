class Solution {
    int MOD = 1E9+7;
  
    vector<vector<long long>> combin;
    void constructPascal(int M){
      
        combin.resize(M+1, vector<long long>(M+1, 0));
        for(int i=0; i<=M; ++i){ 
            combin[i][0] = combin[i][i] = 1;
        }
        for(int i=2; i<=M; ++i){
            for(int j=1; j<M; ++j){
              
                combin[i][j] = (combin[i-1][j] + combin[i-1][j-1]) % MOD;
            }
        }
    }
   
    int dp[50][31][31][16];
    int runDP(int cur, int m, int k, int carry_mask, vector<int>& nums){
        if(m == 0){ 
            bitset<5> bit = carry_mask;
            if(bit.count() == k) return 1;
            else return 0;
        }
        if(k == 0 || cur == nums.size()) return 0; 
        if(dp[cur][m][k][carry_mask] != -1) return dp[cur][m][k][carry_mask];
 
        long long res = 0;
        long long prod = 1;
        for(int add = 0; add <= m; ++add){
            int curMask = carry_mask + add;
            int nextK = k - (curMask & 1);
            int nextM = m - add;
            if(add) prod = (prod * nums[cur]) % MOD;
            long long temp = (combin[m][add] * prod) % MOD;
            res = (res + temp * runDP(cur+1, nextM, nextK, curMask >> 1, nums)) % MOD;
        }
        return dp[cur][m][k][carry_mask] = res;
    }
public:
    int magicalSum(int M, int K, vector<int>& nums) {
        int n = nums.size();

        constructPascal(M);
       
        memset(dp, -1, sizeof(dp));
        return runDP(0, M, K, 0, nums);;
    }
};