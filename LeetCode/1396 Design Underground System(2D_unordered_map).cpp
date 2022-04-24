class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> lastVisitOfCustomer;
    unordered_map<string, unordered_map<string, pair<int, int>>> visitedPeopleCountAndTime;
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        lastVisitOfCustomer[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string lastVisitedPlace = lastVisitOfCustomer[id].first;
        int startTime = lastVisitOfCustomer[id].second;

        visitedPeopleCountAndTime[lastVisitedPlace][stationName].first += (t - startTime);
        visitedPeopleCountAndTime[lastVisitedPlace][stationName].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        return (double) visitedPeopleCountAndTime[startStation][endStation].first / (double) visitedPeopleCountAndTime[startStation][endStation].second;
    }
};

// implementation: 2
/*
class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> lastVisitOfCustomer;
    unordered_map<string, pair<int, int>> visitedPeopleCountAndTime;
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        lastVisitOfCustomer[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string lastVisitedPlace = lastVisitOfCustomer[id].first;
        int startTime = lastVisitOfCustomer[id].second;

        string combineString = lastVisitedPlace;
        combineString += "->";
        combineString += stationName;

        visitedPeopleCountAndTime[combineString].first += (t - startTime);
        visitedPeopleCountAndTime[combineString].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        string combineString = startStation;
        combineString += "->";
        combineString += endStation;

        return (double) visitedPeopleCountAndTime[combineString].first / (double) visitedPeopleCountAndTime[combineString].second;
    }
};
*/
// implementation: 3
/*
Note:
To use a pair as key in unordered_map, it's required to provide a suitable hash function for the key type.
https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key
*/
/*
class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> lastVisitOfCustomer;
    map<pair<string, string>, int> visitedPeopleCount;
    map<pair<string, string>, int> totalTimeOfTravel;
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        lastVisitOfCustomer[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string lastVisitedPlace = lastVisitOfCustomer[id].first;
        int startTime = lastVisitOfCustomer[id].second;

        visitedPeopleCount[{lastVisitedPlace, stationName}]++;
        totalTimeOfTravel[{lastVisitedPlace, stationName}] += (t - startTime);
    }

    double getAverageTime(string startStation, string endStation) {
        return (double) totalTimeOfTravel[{startStation, endStation}] / (double) visitedPeopleCount[{startStation, endStation}];
    }
};
*/
