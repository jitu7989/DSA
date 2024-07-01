package java.leetcode;

import java.util.Arrays;

public class N_Queens_2 {

    public int totalNQueens(int n) {
        int d = 0;
        char[][] board = new char[n][n];

        for (char[] i:board) Arrays.fill( i , '.' );

        return formNQueenBoard( board , 0  );
    }

    public static int formNQueenBoard( char[][] board , int row ){

        if( row >= board.length )
            return 1;

        int x = 0;
        for (int i = 0; i < board[0].length ; i++) {

            if( isSafe( board , row , i ) ){
                board[row][i] = 'Q';
                x+=formNQueenBoard( board, row+1);
                board[row][i] = '.';
            }
        }
        return x;
    }

    private static boolean isSafe(char[][] board, int row, int col) {

        int n = board.length;
        for( int i=0; i<n; i++ ){
            if( row != i && board[i][col] == 'Q' ) return false;
            if( col != i && board[row][i] == 'Q' ) return false;
        }

        int i = row-1,j=col-1;
        while( i>=0 && j>=0 ) if( board[i--][j--] == 'Q' ) return false;

        i = row+1; j = col+1;
        while( i<n && j<n ) if( board[i++][j++] == 'Q' ) return false;

        i=row+1; j=col-1;
        while( i<n && j>=0 ) if( board[i++][j--] == 'Q' ) return false;

        i=row-1; j=col+1;
        while( i>=0 && j<n ) if( board[i--][j++] == 'Q' ) return false;

        return true;

    }

}
