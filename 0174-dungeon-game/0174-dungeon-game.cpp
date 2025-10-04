class Solution {
private:
    const int _impossible = 10000;
    vector<vector<int>> dp;
    vector<vector<int>> dungeon;

    int _goIntoDangeon(int row = 0, int col = 0)
    {

        int current = dungeon[row][col];
        if (row + 1 >= dp.size() && col + 1 >= dp[0].size())
        {
            int res = current >= 0 ? 1 : abs(current) + 1;
            dp[row][col] = res;
            return res;
        }

        int right = _impossible, down = _impossible;

        if (row + 1 < dp.size())
        {
            if (dp[row + 1][col] != _impossible)
            {

                down = dp[row + 1][col];

            }
            else down= _goIntoDangeon(row + 1, col);
        }
        if (col + 1 < dp[0].size())
        {
            if (dp[row][col + 1] != _impossible)
            {

                right = dp[row][col + 1];
            }
            else right = _goIntoDangeon(row, col + 1);
        }

        int valueToChoose = min(right, down);
        if (current > valueToChoose && current - valueToChoose >= 1) {
            current = 1;
        }
        else if (current < valueToChoose && valueToChoose - current  >= 1)
        {
            current = (valueToChoose - current);
        }
        else
            current = 1;

        dp[row][col] = current;

        return current;

    }
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int rows = d.size(), cols = d[0].size();
        dungeon = d;

        dp = vector<vector<int>>(rows, vector<int>(cols, _impossible));

        return abs(_goIntoDangeon());
    }
};