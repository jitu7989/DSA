
interface stringFunctions{
  public String print(String a,String b);
  public int countVowels(String a,String b);
  public int countConsonants(String a,String b);
  public int valueOfString(String a,String b);
}

// Please note that the string contains both uppercase and lowercase characters
class strClassOne implements stringFunctions{
    // implement all the function inherited by this class
    public  String print(String a,String b){
        // This function prints both the strings on the same line separated by space
        return a+" "+b;
    }
    public int countVowels(String a,String b){
        // This function returns the length of the string having lesser number of vowels.
        //In case both the strings, have the same number of vowels return the length of the bigger string
        int count1=0,count2=0;

        count1 = getVowel(a, count1);
        count2 = getVowel(b, count2);

        if(count1==count2) return Math.max(a.length(), b.length());

        return count1<count2?a.length():b.length();

    }

    private int getVowel(String b, int count2) {
        for(int i=0;i<b.length();i++){
            if(  b.charAt(i)=='a'||
                 b.charAt(i)=='e'||
                 b.charAt(i)=='i'||
                 b.charAt(i)=='o'||
                 b.charAt(i)=='u'||
                 b.charAt(i)=='A'||
                 b.charAt(i)=='E'||
                 b.charAt(i)=='I'||
                 b.charAt(i)=='O'||
                 b.charAt(i)=='U')
             count2++;

        }
        return count2;
    }
    int getConsonant( String b  ){
        int count=0;
        for(int i=0;i<b.length();i++){
            if(  (  b.charAt(i)>='a' && b.charAt(i)<='z' ||
                    b.charAt(i)>='A' && b.charAt(i)<='Z' ) &&
                    b.charAt(i)=='a'||
                    b.charAt(i)=='e'||
                    b.charAt(i)=='i'||
                    b.charAt(i)=='o'||
                    b.charAt(i)=='u'||
                    b.charAt(i)=='A'||
                    b.charAt(i)=='E'||
                    b.charAt(i)=='I'||
                    b.charAt(i)=='O'||
                    b.charAt(i)=='U')
                count++;

        }
        return count;
    }
    public int countConsonants(String a,String b){
        // This function returns the length of the string having lesser number of consonants
        // In case both the strings have the same number of consonants, return the length of the bigger string

        int count1=0,count2=0;

        count1 = getConsonant(a);
        count2 = getConsonant(b);

        if(count1==count2) return Math.max(a.length(), b.length());
        return count1<count2 ? a.length() : b.length();

    }

    @Override
    public int valueOfString(String a, String b) {
        return 0;
    }
}
class strClassTwo implements stringFunctions{
    // implement all the function inherited by this class
    public String print(String a,String b){
        // This functions prints string a and string b on two different lines
        return a+"\n+"+b;
    }
    public int countVowels(String a,String b){
        // This function returns the length of the string having more number of vowels.
        //In case both the strings, have the same number of vowels return the length of the smaller string
        int count1=0,count2=0;

        count1 = getVowel(a);
        count2 = getVowel(b);
        if( count1==count2 ) return Math.min(a.length(), b.length());
        return count1>count2 ? a.length():b.length();
    }
    public int countConsonants(String a,String b){
        // This function returns the length of the string having more number of consonants
        // In case both the strings have the same number of consonants, return the length of the smaller string

        int count1=0,count2=0;

        count1 = getConsonant(a);
        count2 = getConsonant(b);
        if( count1==count2 ) return Math.min(a.length(), b.length());
        return count1>count2 ? a.length():b.length();

    }

    @Override
    public int valueOfString(String a, String b) {

        return 0;
    }

    private int getVowel(String b ) {
        int count =0;
        for(int i=0;i<b.length();i++){
            if(  b.charAt(i)=='a'||
                    b.charAt(i)=='e'||
                    b.charAt(i)=='i'||
                    b.charAt(i)=='o'||
                    b.charAt(i)=='u'||
                    b.charAt(i)=='A'||
                    b.charAt(i)=='E'||
                    b.charAt(i)=='I'||
                    b.charAt(i)=='O'||
                    b.charAt(i)=='U')
                count++;

        }
        return count;
    }
    int getConsonant( String b  ){
        int count=0;
        for(int i=0;i<b.length();i++){
            if(  (  b.charAt(i)>='a' && b.charAt(i)<='z' ||
                    b.charAt(i)>='A' && b.charAt(i)<='Z' ) &&
                    b.charAt(i)=='a'||
                    b.charAt(i)=='e'||
                    b.charAt(i)=='i'||
                    b.charAt(i)=='o'||
                    b.charAt(i)=='u'||
                    b.charAt(i)=='A'||
                    b.charAt(i)=='E'||
                    b.charAt(i)=='I'||
                    b.charAt(i)=='O'||
                    b.charAt(i)=='U')
                count++;

        }
        return count;
    }






}
