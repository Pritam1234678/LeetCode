class RideSharingSystem {
    Queue<Integer> drivers = new LinkedList<>();
    Queue<Integer> riders = new LinkedList<>();
    int [] validRiders = new int[1001];
    int validRiderCount = 0;

    public RideSharingSystem() {
        
    }
    
    public void addRider(int riderId) {
        riders.add(riderId);
        validRiders[riderId] = 1;
        validRiderCount++;
    }
    
    public void addDriver(int driverId) {
        drivers.add(driverId);
    }
    
    public int[] matchDriverWithRider() {
        if (drivers.isEmpty() || validRiderCount == 0) {
            return new int [] {-1, -1};
        }

        while (!riders.isEmpty() && validRiders[riders.peek()] == 0) {
            riders.poll();
        }

        int driverId = drivers.poll();
        int riderId = riders.poll();
        validRiders[riderId] = 0;
        validRiderCount--;


        return new int [] {driverId, riderId};
    }
    
    public void cancelRider(int riderId) {
        if (validRiders[riderId] == 1) {
            validRiders[riderId] = 0;
            validRiderCount--;
        }
    }
}

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem obj = new RideSharingSystem();
 * obj.addRider(riderId);
 * obj.addDriver(driverId);
 * int[] param_3 = obj.matchDriverWithRider();
 * obj.cancelRider(riderId);
 */
