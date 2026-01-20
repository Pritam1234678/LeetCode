class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        int n = deck.length;
        Deque<Integer> queue = new ArrayDeque<>();

        for(int i=n-1; i>=0; i--) {
            if(!queue.isEmpty()) {
                int x = queue.removeLast();
                queue.addFirst(x);
            }
            queue.addFirst(deck[i]);
        }

        int[] ans = new int[n];
        int i=0;
        for(int x : queue) {
            ans[i++] = x;
        }

        return ans;
    }
}
