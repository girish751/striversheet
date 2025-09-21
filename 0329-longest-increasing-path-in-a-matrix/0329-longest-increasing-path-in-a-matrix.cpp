class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp){
        if(dp[x][y] != 0){
            return dp[x][y];
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int maxx = 1;
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && matrix[nx][ny] > matrix[x][y]){
                maxx = max(maxx, 1 + dfs(matrix, nx, ny, dp));
            }
        }
        
        dp[x][y] = maxx;
        return maxx;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int count = 1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count = max(count, dfs(matrix, i, j, dp));
            }
        }
        
        return count;
    }
};