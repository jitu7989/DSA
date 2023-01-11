import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NQueens {

    public static void main(String[] args) {
        solveNQueens( 1 );
        solveNQueens( 2 );
        solveNQueens( 3 );
        solveNQueens( 4 );
        solveNQueens( 5 );
        solveNQueens( 6 );
        solveNQueens( 7 );
        solveNQueens( 8 );
        solveNQueens( 9 );
    }
    public static int solveNQueens(int n) {

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
