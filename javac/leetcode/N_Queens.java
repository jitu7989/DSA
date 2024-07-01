package java.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class N_Queens {

    public static List<List<String>> solveNQueens(int n) {

        List<List<String>> DistinctBoards = new ArrayList<>();

        char[][] board = new char[n][n];

        for (char[] i:board) Arrays.fill( i , '.' );

        formNQueenBoard( board , 0 ,  DistinctBoards );

        return DistinctBoards;

    }

    public static void formNQueenBoard( char[][] board , int row, List<List<String>> boards ){

        if( row >= board.length ){

            List<String>  ChessBoard = new ArrayList<>();

            for ( char[] i:board ) {
                StringBuilder sb = new StringBuilder();
                for( char j:i ) sb.append(j);
                ChessBoard.add( sb.toString() );
            }

            boards.add( ChessBoard );

            return;
        }

        for (int i = 0; i < board[0].length ; i++) {

            if( isSafe( board , row , i ) ){
                board[row][i] = 'Q';
                formNQueenBoard( board, row+1, boards );
                board[row][i] = '.';
            }

        }

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
