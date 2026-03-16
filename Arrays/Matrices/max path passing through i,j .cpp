// Use this to get the maximum sum for all paths through i,j
// ONLY DOWN AND RIGHT MOVES ALLOWED
to[0][0] = grid[0][0];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (i > 0) to[i][j] = max(to[i][j], to[i - 1][j] + grid[i][j]);
        if (j > 0) to[i][j] = max(to[i][j], to[i][j - 1] + grid[i][j]);
    }
}
// Path: (n-1, m-1) -> (0,0) [Backwards]
from[n - 1][m - 1] = grid[n - 1][m - 1];
for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
        if (i + 1 < n) from[i][j] = max(from[i][j], from[i + 1][j] + grid[i][j]);
        if (j + 1 < m) from[i][j] = max(from[i][j], from[i][j + 1] + grid[i][j]);
    }
}