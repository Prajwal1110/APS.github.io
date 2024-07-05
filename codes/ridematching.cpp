#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

// Define a structure for driver and rider information
struct Driver {
    int id;
    string name;
    // You can add more attributes as needed
    bool operator<(const Driver& other) const {
        return id > other.id; // Min-heap based on driver id
    }
};

struct Rider {
    int id;
    string name;
    // You can add more attributes as needed
    bool operator<(const Rider& other) const {
        return id > other.id; // Min-heap based on rider id
    }
};

class RideMatching {
private:
    priority_queue<Driver> drivers;
    priority_queue<Rider> riders;

public:
    void addDriver(const Driver& driver) {
        drivers.push(driver);
    }

    void addRider(const Rider& rider) {
        riders.push(rider);
    }

    tuple<Driver, Rider> matchRide() {
        if (!drivers.empty() && !riders.empty()) {
            Driver driver = drivers.top();
            Rider rider = riders.top();
            drivers.pop();
            riders.pop();
            return make_tuple(driver, rider);
        }
        return make_tuple(Driver{-1, ""}, Rider{-1, ""}); // Return default if no match
    }
};

int main() {
    RideMatching rideMatching;

    // Example usage
    rideMatching.addDriver({1, "prakashsir"});
    rideMatching.addRider({1, "prajwal"});

    auto [driver, rider] = rideMatching.matchRide();
    if (driver.id != -1 && rider.id != -1) {
        cout << "Matched Driver: " << driver.name << ", Rider: " << rider.name << endl;
    } else {
        cout << "No match found!" << endl;
    }

    return 0;
}
