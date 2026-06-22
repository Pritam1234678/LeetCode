class Solution {

    public String reverse(String s, int idx) {
        char[] arr = s.toCharArray();

        int left = 0;
        int right = idx;

        while (left < right) {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }

        return new String(arr);
    }

    public String reversePrefix(String word, char ch) {
        int idx = word.indexOf(ch);

        if (idx == -1) {
            return word;
        }

        return reverse(word, idx);
    }
}
