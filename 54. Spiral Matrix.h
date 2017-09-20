class Solution {
public:
    vector<int> resultOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        vector<int> result(m * n);
        while (true){
            for (int col = l; col <= r; col++) result[k++] = matrix[u][col];
            if (++u > d) break;

            for (int row = u; row <= d; row++) result[k++] = matrix[row][r];
            if (--r < l) break;

            for (int col = r; col >= l; col--) result[k++] = matrix[d][col];
            if (--d < u) break;

            for (int row = d; row >= u; row--) result[k++] = matrix[row][l];
            if (++l > r) break;
        }
        return result;
    }
};