int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int i, int j, char** grid, int gridSize, int* gridColSize){
    int k;
    grid[i][j] = '0';
    for (k = 0; k < 4; k++) {
        int m = i + direct[k][0];
        int n = j + direct[k][1];
        if ((m < 0)||(n < 0) || (m >= gridSize) || ( n >= gridColSize[0])){
            continue;
        }
        if (grid[m][n] == '0') {
            continue;
        }
        dfs(m, n, grid, gridSize, gridColSize);
    }
    return;
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j;
    int count = 0;
    for(i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                dfs(i, j, grid, gridSize, gridColSize);
                count++;
            }
        }
    }
    return count;
}