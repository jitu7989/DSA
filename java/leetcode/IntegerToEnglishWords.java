package java.leetcode;

public class IntegerToEnglishWords {
    public static String[] oneToNine = new String[]{"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    public static String[] elevenToNineteen = new String[]{"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    public static String[] tens = new String[]{"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    public static String[] powers = new String[]{"Hundred", "Thousand", "Million", "Billion"};

    public StringBuilder sb = new StringBuilder();

    public String numberToWords(int num) {

        if (num == 0) return "Zero";
        sb = new StringBuilder();
        String number = String.valueOf(num);
        int n = number.length();
        solve(number, 0);
        if (sb.charAt(sb.length() - 1) == ' ') sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    private void solve(String number, int power) {
        int startIdx = number.length() - Math.min(number.length(), (power + 1) * 3);

        int endIdx = number.length() - Math.min(number.length(), (power) * 3);

        if (startIdx != 0)
            solve(number, power + 1);
        String subNum = number.substring(startIdx, endIdx);

        Character first = subNum.length() == 3 ? subNum.charAt(0) : null,
                second = subNum.length() >= 2 ? subNum.charAt(subNum.length() == 3 ? 1 : 0) : null,
                third = subNum.charAt(subNum.length() - 1);

        if (subNum.length() == 3) {
            String s = getRawNum(first);
            if (s.length() != 0) {
                sb.append(s).append(' ');
                sb.append(powers[0]).append(' ');
            }
            String s2 = getRawNum(second, third);
            if (s2.length() != 0) sb.append(getRawNum(second, third)).append(' ');
            if ((s.length() != 0 || s2.length() != 0) && power > 0) sb.append(powers[power]).append(' ');
        } else if (second != null) {
            String s2 = getRawNum(second, third);
            if (s2.length() != 0) {
                sb.append(s2).append(' ');
                if (power > 0) sb.append(powers[power]).append(' ');
            }
        } else {
            String s = getRawNum(third);
            if (s.length() != 0) {
                sb.append(s).append(' ');
                if (power > 0) sb.append(powers[power]).append(' ');
            }
        }
    }

    private String getRawNum(Character second, Character third) {
        if (second == null || second == '0') {
            return third == '0' ? "" : getRawNum(third);
        }
        if (third == '0') {
            return tens[second - '1'];
        } else if (second == '1') {
            return elevenToNineteen[third - '1'];
        } else {
            return tens[second - '1'] + " " + getRawNum(third);
        }
    }

    private String getRawNum(char c) {
        if (c == '0') return "";
        return oneToNine[c - '1'];
    }
}