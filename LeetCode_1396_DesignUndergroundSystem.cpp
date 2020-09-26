class UndergroundSystem {
public:
    
    map<int, pair<string,int>> map1;
    map<pair<string,string>, vector<double>> map2;
    UndergroundSystem() {
        map1.clear();
        map2.clear(); 
    }
    
    void checkIn(int id, string stationName, int t) {
        map1[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
       map2[{map1[id].first, stationName}].push_back(t - map1[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double size = map2[{startStation, endStation}].size();
        double sum = 0;
        for(auto key : map2[{startStation, endStation}])
            sum += key;
        return sum/size;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */