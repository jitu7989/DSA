package java.leetcode;

import java.util.Arrays;

public class WildcardMatching {

    boolean[] wildCard = new boolean[0];
    int[][] dp = new int[0][0];
    public boolean isMatch(String str, String ptrn){
        if(str.equals(ptrn)) return true;
        if(ptrn.isEmpty() && !str.isEmpty()) return false;
        onlyWildCard(ptrn);
        if(wildCard[0]) return true;
        dp = new int[str.length()+1][ptrn.length()+1];
        for (int[] ints : dp) Arrays.fill(ints,-1);
        return solve(str,ptrn,0,0)==1;
    }

    private int solve(String str, String ptrn, int i, int j) {

        if(dp[i][j]!=-1) return dp[i][j];
        if(i==str.length() && j==ptrn.length() || (j<ptrn.length() && wildCard[j])){
            return dp[i][j] = 1;
        }
        if(i==str.length()) return dp[i][j] = 0;
        if(j==ptrn.length()) return dp[i][j] = 0;
        char strChar = str.charAt(i);
        char ptrnChar = ptrn.charAt(j);
        if(strChar==ptrnChar || ptrnChar=='?'){
            dp[i][j] = solve(str,ptrn,i+1,j+1);
        }
        else if (ptrnChar=='*') {
            int a = solve(str,ptrn,i+1,j);
            int b = solve(str,ptrn,i,j+1);
            if(1==a || b==1) dp[i][j] = 1;
            else             dp[i][j] = 0;
        }
        else  dp[i][j]=0;

        return dp[i][j];
    }

    public void onlyWildCard(String ptrn){
        wildCard = new boolean[ptrn.length()];
        boolean wildCard = true;
        for (int i = ptrn.length()-1; i >=0; i--) {
            if(ptrn.charAt(i)!='*') wildCard = false;
            this.wildCard[i] = wildCard;
        }
    }

}
