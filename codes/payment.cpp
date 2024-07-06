#include <iostream>
#include <unordered_map>

using namespace std;

struct Payment {
    int driverId;
    double amount;
};

class PaymentSystem {
private:
    unordered_map<int, double> driverPayments;

public:
    void processPayment(const Payment& payment) {
        driverPayments[payment.driverId] += payment.amount;
    }

    double getTotalPaymentForDriver(int driverId) {
        if (driverPayments.find(driverId) != driverPayments.end()) {
            return driverPayments[driverId];
        }
        return 0.0; // Default if no payments found
    }
};

int main() {
    PaymentSystem ps;
    ps.processPayment({1, 50.0});
    ps.processPayment({2, 65.0});

    double totalPayment = ps.getTotalPaymentForDriver(1);
    cout << "Total Payment for Driver 1: $" << totalPayment << endl;

    return 0;
}
