### Surge Pricing Algorithm

#### Benefits and Challenges:
Surge pricing algorithms are essential in ride-sharing applications to dynamically adjust fares based on demand and supply conditions. They help in maximizing earnings during peak times and balancing demand with driver availability.

- **Benefits:**
  - Maximizes earnings during high-demand periods.
  - Encourages more drivers to operate during peak times.
  - Maintains service availability by matching supply with demand.

- **Challenges:**
  - Ensuring fair pricing without causing user dissatisfaction.
  - Handling abrupt demand spikes and ensuring smooth transitions.
  - Balancing surge multipliers to optimize both driver earnings and user affordability.

#### Algorithm:
The Surge Pricing algorithm adjusts the fare based on a base fare and a surge multiplier during peak times.

#### Example Code (C++):
```cpp
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
```
#### Time Complexity:
- **calculateFare Operation (calculateFare function):**
  - Time Complexity: O(1)
  
#### Space Complexity:
- **SurgePricing Class:**
  - Space Complexity: O(1)
 
