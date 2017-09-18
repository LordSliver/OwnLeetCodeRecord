class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> column(9, vector<int>(9, 0)), 
            row(9, vector<int>(9, 0)), 
            cube(9, vector<int>(9, 0));
        for (auto i = 0; i < board.size(); ++i){
            for (auto j = 0; j < board[i].size(); ++j){
                if (board[i][j] != '.'){
                    int n = board[i][j] - '0' - 1;
                    int indexInCube = i / 3 * 3 + j / 3;
                    if(column[i][n] || row[j][n] || cube[indexInCube][n])
                        return false;
                    column[i][n] = row[j][n] = cube[indexInCube][n] = 1;
                }
            }
        }
        return true;
    }
};