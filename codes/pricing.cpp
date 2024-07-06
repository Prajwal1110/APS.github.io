#include <iostream>

using namespace std;

class SurgePricing {
private:
    double baseFare;
    double surgeMultiplier;

public:
    SurgePricing(double base, double multiplier)
        : baseFare(base), surgeMultiplier(multiplier) {}

    double calculateFare(int distance, bool isPeakTime) {
        double fare = baseFare * distance;
        if (isPeakTime) {
            fare *= surgeMultiplier;
        }
        return fare;
    }
};

int main() {
    SurgePricing pricing(1.5, 2.0); // Base fare $1.5, Surge multiplier 2.0x

    double fareNormal = pricing.calculateFare(10, false);
    double fareSurge = pricing.calculateFare(10, true);

    cout << "Normal Fare: $" << fareNormal << endl;
    cout << "Surge Fare: $" << fareSurge << endl;

    return 0;
}
