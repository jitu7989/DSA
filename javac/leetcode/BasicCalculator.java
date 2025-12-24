package java.leetcode;

public class BasicCalculator {
    int i;
    public int calculate(String s) {
        int integer = 0;
        char prev = '!';
        while (i < s.length()) {
            char c = s.charAt(i);
            if (c == '(') {
                i++;
                int n = calculate(s);
                i--;
                if (prev != '!')
                    if (prev == '+') integer += n;
                    else integer -= n;
                else integer = n;
            } else if (c == ')') {
                i++;
                return integer;
            } else if (c == '-') {
                prev = '-';
            } else if (c == '+') {
                prev = '+';
            } else if (c >= '0' && c <= '9') {
                StringBuilder sb = new StringBuilder();
                while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') sb.append(s.charAt(i++));
                i--;
                int n = Integer.parseInt(sb.toString());
                if (prev != '!')
                    if (prev == '+') integer += n;
                    else integer -= n;
                else integer = n;
            }
            i++;
        }
        return integer;
    }
}