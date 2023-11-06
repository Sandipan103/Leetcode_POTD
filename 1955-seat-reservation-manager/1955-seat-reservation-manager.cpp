class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> seatRegis;    
public:
    SeatManager(int n) {
        for(int seat = 1; seat <= n; seat++){
            seatRegis.push(seat);
        }
    }
    
    int reserve() {
        int seat =  seatRegis.top();
        seatRegis.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        seatRegis.push(seatNumber);
    }
};