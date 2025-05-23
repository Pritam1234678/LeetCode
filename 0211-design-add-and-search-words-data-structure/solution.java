import java.util.*;

class WordDictionary {
    private Map<Integer, List<String>> map;

    public WordDictionary() {
        map = new HashMap<>();
    }

    public void addWord(String word) {
        int len = word.length();
        map.computeIfAbsent(len, k -> new ArrayList<>()).add(word);
    }

    public boolean search(String word) {
        int len = word.length();
        if (!map.containsKey(len)) return false;

        for (String candidate : map.get(len)) {
            if (isMatch(candidate, word)) return true;
        }
        return false;
    }

    private boolean isMatch(String word, String pattern) {
        for (int i = 0; i < word.length(); i++) {
            char wc = pattern.charAt(i);
            if (wc != '.' && word.charAt(i) != wc) return false;
        }
        return true;
    }
}

