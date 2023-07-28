class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& block, int col, vector<int>& left, vector<int>& Upleft, vector<int>& downleft, int n) {
    if (col == n) {
        ans.push_back(block);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (left[row] == 0 && Upleft[n - 1 + col - row] == 0 && downleft[row + col] == 0) {
            block[row][col] = 'Q';
            left[row] = 1;
            Upleft[n - 1 + col - row] = 1;
            downleft[row + col] = 1;
            solve(ans, block, col + 1, left, Upleft, downleft, n);
            block[row][col] = '.';
            left[row] = 0;
            Upleft[n - 1 + col - row] = 0;
            downleft[row + col] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> block(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        block[i] = s;
    }
    vector<int> left(n, 0);
    vector<int> Upleft(2 * n - 1, 0);
    vector<int> downleft(2 * n - 1, 0);
    solve(ans, block, 0, left, Upleft, downleft, n);
    return ans;
}

};