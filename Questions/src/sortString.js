function run ( sizeOfArray , k , array ) {

    let girlsImpressed = 0;
    let maxGirlsImpressed = 0;

    for (let i = 0; i < Math.min( k ,sizeOfArray ); i++) {
        girlsImpressed += array[i];
    }

    maxGirlsImpressed = girlsImpressed;

    for (let i = 0, j=k+1; i < sizeOfArray; i++ ) {
        girlsImpressed = girlsImpressed - array[i] + array[j];
        maxGirlsImpressed = Math.max( maxGirlsImpressed , girlsImpressed );
    }

    return maxGirlsImpressed;

}

console.log( run( 7 , 2 , [2,4,8,1,2,1,8] ) )
