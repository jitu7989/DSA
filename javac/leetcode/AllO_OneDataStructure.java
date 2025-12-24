package java.leetcode;

import java.util.*;

public class AllO_OneDataStructure {

    TreeMap<Integer, Set<String>> treeMap = new TreeMap<>();
    HashMap<String, Integer> freqMap = new HashMap<>();

    public void inc(String key) {
        Integer freq = freqMap.getOrDefault(key, 0);
        Set<String> set = treeMap.get(freq);
        if (set != null) {
            set.remove(key);
            if (set.isEmpty()) treeMap.remove(freq);
        }
        freqMap.put(key, freq + 1);
        Set<String> stringSet = treeMap.get(freq + 1);
        if (stringSet == null) stringSet = new HashSet<>();
        stringSet.add(key);
        treeMap.put(freq + 1, stringSet);
    }

    public void dec(String key) {
        Integer freq = freqMap.get(key);
        Set<String> set = treeMap.get(freq);
        set.remove(key);
        if (set.isEmpty()) treeMap.remove(freq);
        if (freq == 1) freqMap.remove(key);
        else {
            freqMap.put(key, freq - 1);
            Set<String> stringSet = treeMap.get(freq - 1);
            if (stringSet == null) stringSet = new HashSet<>();
            stringSet.add(key);
            treeMap.put(freq - 1, stringSet);
        }
    }

    public String getMaxKey() {
        if (treeMap.lastEntry() == null) return "";
        return treeMap.lastEntry().getValue().stream().findAny().orElse("");
    }

    public String getMinKey() {
        if (treeMap.firstEntry() == null) return "";
        return treeMap.firstEntry().getValue().stream().findAny().orElse("");
    }
}

