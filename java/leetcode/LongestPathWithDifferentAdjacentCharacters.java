package java.leetcode;

import java.util.*;

public class LongestPathWithDifferentAdjacentCharacters {

    static int maxPathLen = 0;

    public static int longestPath(int[] parent, String s) {
        List<List<Integer>> tree = new ArrayList<>();
        int n = parent.length;
        for (int i = 0; i < n; i++) tree.add(new ArrayList<>());
        for (int i = 1; i < n; i++)
            tree.get(parent[i]).add(i);
        maxPathLen = 0;
        longestPath2(0, tree, s);
        return maxPathLen;
    }

    public static int longestPath2(int currNode, List<List<Integer>> tree, String s) {
        char characterAtCurrNode = s.charAt(currNode);
        List<Integer> childNodes = tree.get(currNode);
        int[] twoLongestPathLen = new int[2];
        for (int i : childNodes) {
            int path = longestPath2(i, tree, s);
            char adjCharacter = s.charAt(i);
            if (adjCharacter != characterAtCurrNode) {
                path += 1;
                if (path > twoLongestPathLen[0]) {
                    twoLongestPathLen[1] = twoLongestPathLen[0];
                    twoLongestPathLen[0] = path;
                } else if (path > twoLongestPathLen[1]) {
                    twoLongestPathLen[1] = path;
                }
            }
        }
        maxPathLen = Math.max(twoLongestPathLen[0] + twoLongestPathLen[1] + 1, maxPathLen);
        return twoLongestPathLen[0];
    }

}