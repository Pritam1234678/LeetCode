class RecentCounter {

    public RecentCounter() {
    
    }
    Queue<Integer> q=new ArrayDeque<>();
        public int ping(int t) {
        q.add(t);
        while(t-3000>q.peek()) q.remove();
        return q.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
