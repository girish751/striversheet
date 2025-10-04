class Solution {
private:
    int recur(int r, int c, vector<vector<int>>& grid, int i, int j) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }

        if (grid[i][j] == 1) {
            return 0;
        }

        int left = recur(r, c, grid, i, j - 1);
        int up = recur(r, c, grid, i - 1, j);

        return left + up;
    }

    int memo(int r, int c, vector<vector<int>>& grid, int i, int j,
             vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }

        if (grid[i][j] == 1) {
            dp[i][j] = 0;
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int left = memo(r, c, grid, i, j - 1, dp);
        int up = memo(r, c, grid, i - 1, j, dp);

        return dp[i][j] = left + up;
    }

    int tab(int r, int c, vector<vector<int>>& grid) {
        vector<vector<int>> dp(r, vector<int>(c, -1));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i < 0 || j < 0) {
                    dp[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    int up = 0;
                    int left = 0;
                    if (i > 0) {
                        up = dp[i - 1][j];
                    }
                    if (j > 0) {
                        left = dp[i][j - 1];
                    }

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[r - 1][c - 1];
    }

    int opt(int r, int c, vector<vector<int>>& grid) {
        vector<int> prev(c, 0);

        for (int i = 0; i < r; i++) {
            vector<int> temp(c, 0);
            for (int j = 0; j < c; j++) {
                if (i == 0 && j == 0) {
                    if (grid[0][0] == 0)
                        temp[j] =  1; // start is free, 1 path
                    else
                        temp[j] =  0; // start has obstacle, 0 paths
                }
                else if (grid[i][j] == 1) {
                    temp[j] = 0;
                } else {
                    int up = 0;
                    int left = 0;
                    if (i > 0) {
                        up = prev[j];
                    }
                    if (j > 0) {
                        left = temp[j - 1];
                    }

                    temp[j] = left + up;
                }
            }
            prev = temp;
        }

        return prev[c - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();

       
        return opt(r, c, obstacleGrid);
    }
};