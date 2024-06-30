class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int n=size(matrix), m=size(matrix[0]);
        int ans = 0;
        long long preFix[n+1][m+1];
        for(int i=0; i<=n; i++) preFix[i][0] = 0;
        for(int i=0; i<=m; i++) preFix[0][i] = 0;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                preFix[i+1][j+1] = matrix[i][j] + preFix[i+1][j] + preFix[i][j+1] - preFix[i][j];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                for(int a=i; a<=n; a++){
                    for(int b=j; b<=m; b++){
                        int sum = preFix[a][b]-preFix[a][j-1]-preFix[i-1][b]+preFix[i-1][j-1];
                        if(sum==target) ans++;
                    }
                }
            }
        }
        return ans;
    }
};