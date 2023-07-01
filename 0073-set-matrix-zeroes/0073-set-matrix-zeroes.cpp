class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n = matrix[0].size();

        // Space Complexity = O(n) 

        // vector<bool> row(m,false);
        // vector<bool> col(n,false);

        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(matrix[i][j]==0)
        //         {
        //             row[i]=true;
        //             col[j]=true;
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(row[i]==true || col[j]==true)
        //              matrix[i][j]=0;
        //     }
        // }

        // Space Complexity = O(1)

        int col_0=1;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
               col_0=0;
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;

            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=1;j--)
            {
               if(matrix[i][0]==0 || matrix[0][j]==0)
                     matrix[i][j]=0;
            }
            if(col_0==0)
               matrix[i][0]=0;
        }
    }
};