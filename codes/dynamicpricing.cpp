#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Define a structure for DynamicPricing
class DynamicPricing {
private:
    priority_queue<pair<int, string>> priceHeap;

public:
    void updatePrice(const string& location, int price) {
        priceHeap.push(make_pair(price, location));
    }

    string getHighestPriceLocation() {
        if (!priceHeap.empty()) {
            string location = priceHeap.top().second;
            priceHeap.pop();
            return location;
        }
        return ""; // Return empty string if heap is empty
    }
};

int main() {
    DynamicPricing pricing;

    // Example usage
    pricing.updatePrice("LocationA", 50);
    pricing.updatePrice("LocationB", 70);

    cout << "Highest priced location: " << pricing.getHighestPriceLocation() << endl;

    return 0;
}
