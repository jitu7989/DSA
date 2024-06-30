package java.leetcode;

import java.util.*;

public class MaximumFrequencyStack {

    private HashMap<Integer,Integer> map = new HashMap<>();
    private List<List<Integer>> stack = new ArrayList<>(1000);
    private int maxFreq;

    public void push(int val) {
        Integer freq = map.getOrDefault(val,0)+1;
        this.maxFreq = Math.max(freq,maxFreq);
        map.put(val,freq);
        if(this.maxFreq>stack.size()) stack.add(new ArrayList<>());
        stack.get(freq-1).add(val);
    }

    public int pop() {
        Integer x = stack.get(maxFreq-1).remove(stack.get(maxFreq-1).size()-1);
        if(stack.get(maxFreq-1).isEmpty()) maxFreq--;
        map.put(x,map.getOrDefault(x,0)-1);
        return x;
    }

}
