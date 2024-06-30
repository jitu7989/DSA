package java.leetcode;

public class UniquePaths3 {
    boolean[][] visited;
    int n, m;
    int zeros;

    public int uniquePathsIII(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        visited = new boolean[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0) zeros++;
        zeros++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return solve(grid, i, j);
        return 0;
    }

    private int solve(int[][] grid, int i, int j) {
        if (i >= n || j >= m || i < 0 || j < 0 || visited[i][j]) return 0;
        if (grid[i][j] == 2) return zeros == 0 ? 1 : 0;
        if (grid[i][j] == -1) return 0;

        int sum = 0;
        visited[i][j] = true;
        zeros--;
        sum += solve(grid, i + 1, j);
        sum += solve(grid, i - 1, j);
        sum += solve(grid, i, j + 1);
        sum += solve(grid, i, j - 1);
        zeros++;
        visited[i][j] = false;
        return sum;
    }
}
