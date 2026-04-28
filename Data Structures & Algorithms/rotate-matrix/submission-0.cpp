class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        cout << n << endl;
        int d = n;

        cout << n << " : " << d << endl;
        n--;
        for (int i = 0; i < d/2 + d%2; i++)
            for (int j = 0; j < d/2; j++)
            {
                // i , j
                int a = matrix[i][j]; // 0 , 1
                int b = matrix[n-j][i]; // 1 , 0
                int c = matrix[n-i][n-j]; // 2 , 1
                int d = matrix[j][n-i]; // 1 , 2

                matrix[i][j] = b;
                matrix[n-j][i] = c;
                matrix[n-i][n-j] = d;
                matrix[j][n-i] = a;
            }
    }
};
