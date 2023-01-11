import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class Suduko {

    public static void main(String[] args) {

        char[][] board ={
                            {'5','3','.','.','7','.','.','.','.'},
                            {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','.'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','5'},
                            {'.','.','.','.','8','.','.','7','9'}
                        };
        Solution solution = new Solution();

        solution.solveSudoku( board );

        for( char[] i:board ){

            System.out.println( Arrays.toString(i) );

        }
        System.out.println( "===============================" );
        for( int i=0; i<9; i++ ){
            HashSet<Character>  hs = new HashSet<>();
            for( int j=0; j<9; j++ ){
                hs.add( board[j][i] );
            }
            System.out.println( hs );
        }

        System.out.println( "===============================" );

        for( int i=0; i<9; i++ ){
            HashSet<Character>  hs = new HashSet<>();
            for( int j=0; j<9; j++ ){
                hs.add( board[i][j] );
            }
            System.out.println( hs );
        }
        System.out.println( "===============================" );
        for( int i =0; i<3; i++ ){

            for(int j=0; j<3; j++ ){
                int v = i * 3;
                int h = j * 3;
                HashSet<Character>  hs = new HashSet<>();
                for( int s = v; s<v+3; s++  ){
                    for( int t = h; t<h+3; t++ ){
                        hs.add( board[s][t] );
                    }
                }
                System.out.println( hs );
            }

        }


    }
    static class Solution {

        public void solveSudoku(char[][] board) {
            solve( board , 0 , 0 );
        }

        public boolean solve( char[][] board, int row, int col ){
            if( row==9 ) return true;
            if( col==9 ) return solve( board , row+1, 0 );
            if( board[row][col] != '.'  )  return solve( board , row , col+1 );
            else{
                for( int i = '1'; i<='9'; i++ ){
                    if( isSafe( board , (char) i, row, col ) ){
                        board[row][col] = (char) i;
                        if( solve( board , row , col+1 ) ) return true;
                        board[row][col] = '.';
                    }
                }

            }
            return false;
        }
        public boolean isSafe( char[][] board, char toPlace, int x, int y  ){
            for( int i=0; i<9; i++ ){
                if( board[i][y] == toPlace ) return false;
                if( board[x][i] == toPlace ) return false;
            }
            int v = (x/3) * 3 , h = (y/3) * 3;
            for( int i = v; i<v+3; i++  ){
                for( int j = h; j<h+3; j++ ){
                    if( board[i][j]==toPlace ) return false;
                }
            }
            return true;
        }
    }

}
