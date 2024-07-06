#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Feedback {
    int tripId;
    int rating;
    string comments;
};

class FeedbackSystem {
private:
    unordered_map<int, Feedback> feedbackMap;

public:
    void addFeedback(const Feedback& feedback) {
        feedbackMap[feedback.tripId] = feedback;
    }

    double getAverageRatingForDriver(int driverId) {
        double totalRating = 0.0;
        int count = 0;
        for (const auto& entry : feedbackMap) {
            if (entry.second.tripId == driverId) {
                totalRating += entry.second.rating;
                count++;
            }
        }
        if (count > 0) {
            return totalRating / count;
        }
        return 0.0; // Default if no ratings found
    }
};

int main() {
    FeedbackSystem fs;
    fs.addFeedback({1, 4, "Good service"});
    fs.addFeedback({2, 3, "Average ride"});

    double avgRating = fs.getAverageRatingForDriver(1);
    cout << "Average Rating for Driver 1: " << avgRating << endl;

    return 0;
}
