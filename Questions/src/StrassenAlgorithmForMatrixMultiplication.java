import java.util.*;

public class StrassenAlgorithmForMatrixMultiplication {

//    public static void main(String[] args) {
////      5*4
//        int[][] matrice1 = { {  1,  2,  3,  4 },
//                             {  5,  6,  7,  8 },
//                             {  9, 10, 11, 12 },
//                             { 13, 14, 15, 16 },
//                             { 17, 18, 19, 20 }
//                           };
////      4*3
//        int[][] matrice2 = {
//                                {  1,  2,  3 },
//                                {  5,  6,  7 },
//                                {  9, 10, 11 },
//                                {  9, 10, 11 }
//                            };
//
//
//
//        for( int[] i:matrice3 ){
//            for( int j: i )
//                System.out.print( j + " " );
//            System.out.println();
//        }
//
//
//    }
    // Method 1
    // Function to multiply matrices
    public static int[][] multiply(int[][] A, int[][] B)
    {
        // Order of matrix
        int n = A.length;

        // Creating a 2D square matrix with size N
        // n is input from the user
        int[][] R = new int[n][n];                          // -> O(1)

        // Base case
        // If there is only single element
        if (n == 1)                                         // -> O(1)

            // Returning the simple multiplication of
            // two elements in matrices
            R[0][0] = A[0][0] * B[0][0];

            // Matrix
        else {
            // Step 1: Dividing Matrix into parts
            // by storing sub-parts to variables
//          Dividing matrix A into 4 halves

                int[][]                                             // -> O(12) -< O(1)
                    A11 = new int[n / 2][n / 2],
                    A12 = new int[n / 2][n / 2],
                    A21 = new int[n / 2][n / 2],
                    A22 = new int[n / 2][n / 2],
//                  Dividing matrix B into 4 halves
                    B11 = new int[n / 2][n / 2],
                    B12 = new int[n / 2][n / 2],
                    B21 = new int[n / 2][n / 2],
                    B22 = new int[n / 2][n / 2];
//               Divided Matrix int 4 part and fill the matrix in this block

            {
                // Step 2: Dividing matrix A into 4 halves
                split(A, A11, 0, 0);
                split(A, A12, 0, n / 2);
                split(A, A21, n / 2, 0);
                split(A, A22, n / 2, n / 2);

                // Step 2: Dividing matrix B into 4 halves
                split(B, B11, 0, 0);
                split(B, B12, 0, n / 2);
                split(B, B21, n / 2, 0);
                split(B, B22, n / 2, n / 2);
            }                                                       // -> O(n^2)

            // Using Formulas as described in algorithm

//            8 Multiplication
//            int[][] C11 = add( multiply(A11,B11) , multiply(A12,B21) );
//
//            // Q:=M4+M6
//            int[][] C12 = add( multiply(A11,B12) , multiply(A12,B22) );
//
//            // R:=M5+M7
//            int[][] C21 = add( multiply( A21 , B11 ) , multiply( A22 , B21 ) );
//
//            // S:=M1-M3-M4-M5
//            int[][] C22 = add( multiply(A21,B12) , multiply(A22,B22) );

            // 7 Multiplication

             // M1:=(A1+A3)X(B1+B2)
            int[][] M1 = multiply( add( A11 , A22 ) , add( B11 , B22 ) );

            // M2:=(A2-A4)X(B3+B4)
            int[][] M2 = multiply( add( A21 , A22 ) , B11 );

            // M3:=(A1-A4)X(B1+A4)
            int[][] M3 = multiply( A11 , sub( B12 , B22 ) );

            // M4:=A1X(B2-B4)
            int[][] M4 = multiply( A22 , sub( B21 , B11 ) );

            // M5:=(A3+A4)X(B1)
            int[][] M5 = multiply( add( A11 , A12 ) , B22 );

            // M6:=(A1+A2)X(B4)
            int[][] M6 = multiply( sub( A21 , A11 ) , add( B11 , B12 ) );

            // M7:=A4X(B3-B1)
            int[][] M7 = multiply( sub( A12 , A22 ), add( B21 , B22 ) );


            // P:=M2XM3-M6-M7
            int[][] C11 = add(sub(add(M1, M4), M5), M7);

            // Q:=M4+M6
            int[][] C12 = add(M3, M5);

            // R:=M5+M7
            int[][] C21 = add(M2, M4);

            // S:=M1-M3-M4-M5
            int[][] C22 = add(sub(add(M1, M3), M2), M6);




            // Step 3: Join 4 halves into one result matrix
            {
                join(C11, R, 0, 0);
                join(C12, R, 0, n / 2);
                join(C21, R, n / 2, 0);
                join(C22, R, n / 2, n / 2);
            }                                                   // -> O(n^2)
        }

        // Step 4: Return result
        return R;
    }

    // Method 2
    // Function to subtract two matrices
    public static int[][] sub(int[][] A, int[][] B)
    {
        //
        int n = A.length;

        //
        int[][] C = new int[n][n];

        // Iterating over elements of 2D matrix
        // using nested for loops

        // Outer loop for rows
        for (int i = 0; i < n; i++)

            // Inner loop for columns
            for (int j = 0; j < n; j++)

                // Subtracting corresponding elements
                // from matrices
                C[i][j] = A[i][j] - B[i][j];

        // Returning the resultant matrix
        return C;
    }

    // Method 3
    // Function to add two matrices
    public static  int[][] add(int[][] A, int[][] B)
    {

        //
        int n = A.length;

        // Creating a 2D square matrix
        int[][] C = new int[n][n];

        // Iterating over elements of 2D matrix
        // using nested for loops

        // Outer loop for rows
        for (int i = 0; i < n; i++)

            // Inner loop for columns
            for (int j = 0; j < n; j++)

                // Adding corresponding elements
                // of matrices
                C[i][j] = A[i][j] + B[i][j];

        // Returning the resultant matrix
        return C;
    }

    // Method 4
    // Function to split parent matrix
    // into child matrices
    public static void split(int[][] Parent, int[][] Child, int iB, int jB) {
        // Iterating over elements of 2D matrix
        // using nested for loops

        // Outer loop for rows
        // i1 is for child matrix and i2 is for parent matrix
        for (int i1 = 0, i2 = iB; i1 < Child.length; i1++, i2++)

            // Inner loop for columns
            // j1 is for child matrix and j2 is for parent matrix
            for (int j1 = 0, j2 = jB; j1 < Child.length; j1++, j2++)
                Child[i1][j1] = Parent[i2][j2];

    }

    // Method 5
    // Function to join child matrices
    // into (to) parent matrix
    public static void join(int[][] C, int[][] P, int iB, int jB)

    {
        // Iterating over elements of 2D matrix
        // using nested for loops

        // Outer loop for rows
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)

            // Inner loop for columns
            for (int j1 = 0, j2 = jB; j1 < C.length;
                 j1++, j2++)

                P[i2][j2] = C[i1][j1];
    }

    // Method 5
    // Main driver method
    public static void main(String[] args)
    {
        // Display message
        System.out.println( "Strassen Multiplication Algorithm Implementation For Matrix Multiplication :\n" );



        // Size of matrix
        // Considering size as 4 in order to illustrate
        int N = 4;

        // Matrix A
        // Custom input to matrix
        int[][] A = { { 1, 2, 3, 4 },
                { 4, 3, 0, 1 },
                { 5, 6, 1, 1 },
                { 0, 2, 5, 6 } };

        // Matrix B
        // Custom input to matrix
        int[][] B = { { 1, 0, 5, 1 },
                { 1, 2, 0, 2 },
                { 0, 3, 2, 3 },
                { 1, 2, 1, 2 } };

        // Matrix C computations

        // Matrix C calling method to get Result
        int[][] C = multiply(A, B);

        // Display message
        System.out.println(
                "\nProduct of matrices A and B : ");

        // Iterating over elements of 2D matrix
        // using nested for loops

        // Outer loop for rows
        for (int i = 0; i < N; i++) {
            // Inner loop for columns
            for (int j = 0; j < N; j++)

                // Printing elements of resultant matrix
                // with whitespaces in between
                System.out.print(C[i][j] + " ");

            // New line once the all elements
            // are printed for specific row
            System.out.println();
        }
    }

//
//
//    public static int[][] strassenAlgorithmForMatrixMultiplication( int[][] matrice1 , int[][] matrice2 ){
//
//        if( matrice1[0].length != matrice2.length )
//            throw new IllegalArgumentException("Matrices are not compatible for multiplication");
//
//        int n1 = matrice1.length   , n2 = matrice2.length;
//        int m1 = matrice1[0].length, m2 = matrice2[0].length;
//
//        int[][] matrice3 = new int[n1][m2];
//
//        for (int i = 0; i < n1; i++)
//            for( int j = 0; j<m2; j++ )
//                for ( int k = 0; k < m1; k++ )
//                    matrice3[i][j] += matrice1[i][k] * matrice2[k][j];
//
//
//        return matrice3;
//
//    }
//
//
//    public static void printMat(int[][] a, int r, int c){
//        for(int i=0;i<r;i++) {
//            for (int j = 0; j < c; j++)
//                System.out.print(a[i][j] + " ");
//            System.out.println();
//        }
//    }
//    public static void print(String display, int[][] matrix,int start_row, int start_column, int end_row,int end_column) {
//        System.out.println(display + " =>\n");
//        for (int i = start_row; i <= end_row; i++) {
//            for (int j = start_column; j <= end_column; j++) {
//                System.out.print(matrix[i][j]+" ");
//            }
//            System.out.println();
//        }
//    }
//    public static void add_matrix(int[][] matrix_A,int[][] matrix_B,int[][] matrix_C, int split_index) {
//        for (int i = 0; i < split_index; i++){
//            for (int j = 0; j < split_index; j++){
//                matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
//            }
//        }
//    }
//    public static void initWithZeros(int a[][], int r, int c){
//        for(int i=0;i<r;i++)
//            for(int j=0;j<c;j++)
//                a[i][j]=0;
//    }
//    public static int[][] multiply_matrix(int[][] matrix_A,int[][] matrix_B)
//    {
//        int row_1_length = matrix_A.length;    //-> n1
//        int col_1_length = matrix_A[0].length; //-> m1
//
//        int row_2_length = matrix_B.length;    //-> n2
//        int col_2_length = matrix_B[0].length; //-> m2
//
//        if ( col_1_length != row_2_length ) {
//            System.out.println("\nError: The number of columns in Matrix A  must be equal to the number of rows in Matrix B\n");
//            int[][] temp = new int[1][1];
//            temp[0][0]=0;
//            return temp;
//        }
//
//        int[] result_matrix_row = new int[col_2_length];
//
////        Arrays.fill(result_matrix_row,0);
//        int[][] result_matrix = new int[ row_1_length ][ col_2_length ];
//
////        initWithZeros( result_matrix , row_1_length , col_2_length );
//
//        if (col_1_length == 1) {
//            result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
//            return result_matrix;
//        }
//
////        -> divisin point of matrix
//        int split_index = col_1_length / 2;
//
//        int[] row_vector = new int[split_index];
//            Arrays.fill(row_vector,0);
//
////        Result_Matrix -> C11 C12 C21 C22
//        int[][] result_matrix_00 = new int[split_index][split_index];
//        int[][] result_matrix_01 = new int[split_index][split_index];
//        int[][] result_matrix_10 = new int[split_index][split_index];
//        int[][] result_matrix_11 = new int[split_index][split_index];
//
////        Matrix_A -> A11 A12 A21 A22
//        int[][] a00 = new int[split_index][split_index];
//        int[][] a01 = new int[split_index][split_index];
//        int[][] a10 = new int[split_index][split_index];
//        int[][] a11 = new int[split_index][split_index];
//
////        Matrix_B -> B11 B12 B21 B22
//        int[][]
//                b00 = new int[split_index][split_index],
//                b01 = new int[split_index][split_index],
//                b10 = new int[split_index][split_index],
//                b11 = new int[split_index][split_index];
//
////        This nexted for loop is used to fill the Splited Matrices
//            for (int i = 0; i < split_index; i++){
//                for (int j = 0; j < split_index; j++) {
//
//                    a00[i][j] = matrix_A[i][j];
//                    a01[i][j] = matrix_A[i][j + split_index];
//                    a10[i][j] = matrix_A[split_index + i][j];
//                    a11[i][j] = matrix_A[i + split_index][j + split_index];
//                    b00[i][j] = matrix_B[i][j];
//                    b01[i][j] = matrix_B[i][j + split_index];
//                    b10[i][j] = matrix_B[split_index + i][j];
//                    b11[i][j] = matrix_B[i + split_index][j + split_index];
//
//                }
//            }
//
//            add_matrix( multiply_matrix(a00, b00) ,multiply_matrix(a01, b10) , result_matrix_00 , split_index);
//            add_matrix( multiply_matrix(a00, b01) ,multiply_matrix(a01, b11) , result_matrix_01 , split_index);
//            add_matrix( multiply_matrix(a10, b00) ,multiply_matrix(a11, b10) , result_matrix_10 , split_index);
//            add_matrix( multiply_matrix(a10, b01) ,multiply_matrix(a11, b11) , result_matrix_11 , split_index);
//
//            for (int i = 0; i < split_index; i++){
//                for (int j = 0; j < split_index; j++) {
//                    result_matrix[i][j] = result_matrix_00[i][j];
//                    result_matrix[i][j + split_index] = result_matrix_01[i][j];
//                    result_matrix[split_index + i][j] = result_matrix_10[i][j];
//                    result_matrix[i + split_index] [j + split_index] = result_matrix_11[i][j];
//                }
//            }
//
//        return result_matrix;
//    }
}
