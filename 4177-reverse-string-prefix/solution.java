class Solution {
  public String reverse(int k,String s ) {
    char[] arr = s.toCharArray();

    int left = 0;
    int right = k-1;

    while (left < right) {
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    return new String(arr);
}
    public String reversePrefix(String s, int k) {
        return reverse(k,s);
        
    }
}
