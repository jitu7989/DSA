package java.leetcode;
import java.util.*;
public class ParsingABooleanExpression {
    public static boolean parseBoolExpr(String expression) {
        char first = expression.charAt(0);
        if(first!='&' && first!='!' && first!='|') return first == 't';
        Stack<Evaluate> stack = new Stack<>();
        boolean last = true;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if(c==',') continue;

            if(c=='t' || c=='f'){
                stack.peek().booleans.add(c=='t');
            }
            else if(c==')'){
                Evaluate evaluate = stack.pop();
                if(evaluate.operation=='&'){
                    boolean b = evaluate.booleans.get(0);
                    for (Boolean aBoolean : evaluate.booleans) {
                        b = b && aBoolean;
                        if(!b) break;
                    }
                    last=b;
                }
                if(evaluate.operation=='!'){
                    last=!evaluate.booleans.get(0);
                }
                if(evaluate.operation=='|'){
                    boolean b = evaluate.booleans.get(0);
                    for (Boolean aBoolean : evaluate.booleans) {
                        b = b || aBoolean;
                        if(b) break;
                    }
                    last=b;
                }
                if(!stack.empty()) stack.peek().booleans.add(last);
            }
            else{
                stack.push(new Evaluate(new ArrayList<>(),c));
                i++;
            }

        }
        return last;
    }
    static class Evaluate{
        private Character operation;
        private ArrayList<Boolean> booleans;

        public Evaluate(ArrayList<Boolean> booleans,char operation) {
            this.booleans = booleans;
            this.operation = operation;
        }
    }
}
