class Solution {
    public boolean canMeasureWater(int x, int y, int target) {
        if(x+y<target){
            return false;
        }
        int[] dir ={x,-x,y,-y};
        Queue<Integer> q =new ArrayDeque<>();
        Set<Integer> s= new HashSet<>();
        q.offer(0);
        s.add(0);
        while(!q.isEmpty()){
            int curr=q.poll();
            if(curr==target){
                return true;
            }
            for(int d : dir){
                int total = curr+d;
                if(total==target){
                    return true;
                }
                if(total<0 || total >x+y){
                    continue;
                }
                if(!s.contains(total)){
                    s.add(total);
                    q.offer(total);
                }

            }

        }
        return false;
    }
}
