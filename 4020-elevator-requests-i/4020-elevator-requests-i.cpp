class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time=0;
        int current=0;
        for(int floor : requests){
            time += abs(floor-current);
            current=floor;
                
        }
        return time;
    }
};