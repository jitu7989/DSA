package java.leetcode;

import java.util.HashSet;

public class MaximumScoreWordsFormedbyLetters {
    int n;
    boolean[] visited;
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        n = words.length;
        int[] resources = new int[26];
        Pair[] wordsFrequencyHashed = new Pair[words.length];

        for (int i = 0; i < n; i++) {
            wordsFrequencyHashed[i] = new Pair();
            wordsFrequencyHashed[i].add(words[i]);
        }
        for (char letter : letters) resources[letter-'a']++;

        visited = new boolean[n];
        return solve(wordsFrequencyHashed,resources,score,0);
    }
    private class Pair {
        int[] frequency;
        HashSet<Character> characters;
        public Pair() {
            frequency = new int[26];
            characters = new HashSet<>();
        }
        public void add(String word){
            for (char c : word.toCharArray()) {
                frequency[c-'a']++;
                characters.add(c);
            }
        }
    }

    private int solve(Pair[] words, int[] resources, int[] score, int i) {
        if(i==words.length) return 0;
        int maxSocre = 0;
        if(canCreate(words[i],resources)){
            for (Character character : words[i].characters)
                maxSocre+=(words[i].frequency[character - 'a']*score[character - 'a']);
            backTrack(words[i],resources,false);
            maxSocre+=solve(words,resources,score, i+1);
            backTrack(words[i],resources,true);
        }
        maxSocre = Math.max(solve(words,resources,score, i+1),maxSocre);
        return maxSocre;
    }

    private void backTrack(Pair toBacktrack, int[] resources, boolean b) {
        for (Character character : toBacktrack.characters) {
            if(b)resources[character - 'a'] += toBacktrack.frequency[character - 'a'];
            else resources[character - 'a'] -= toBacktrack.frequency[character - 'a'];
        }
    }

    private boolean canCreate(Pair word, int[] resources) {
        for (Character character : word.characters)
            if(word.frequency[character-'a']>resources[character-'a'])return false;

        return true;
    }
}
