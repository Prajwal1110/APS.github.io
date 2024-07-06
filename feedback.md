# Customer Feedback System

## Business Case:
Customer feedback systems are essential for ride-sharing platforms like OLA and UBER to maintain service quality and customer satisfaction. These systems collect and analyze feedback to improve driver performance and overall user experience.

## Algorithm: FeedbackSystem Class

### Data Structures Used:
- **Data Structure:** `unordered_map` for storing feedback data efficiently.

### Challenges:
- Managing and processing large volumes of feedback data.
- Ensuring real-time updates and availability of feedback metrics.
- Handling diverse feedback types and sentiments effectively.

### Benefits:
- Improves service quality based on actionable feedback.
- Enhances driver performance and customer satisfaction.
- Facilitates continuous improvement in service offerings.

### Example Code (C++):
```cpp
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
```
### Space Complexity:
- **addFeedback Operation (addFeedback function):**
  - Space Complexity: O(1) average case, O(n) worst case (due to hash collisions).

- **getAverageRatingForDriver Operation (getAverageRatingForDriver function):**
  - Space Complexity: O(1) for the variables, O(n) for storing feedback entries.
    
### Time Complexity:
- **addFeedback Operation (addFeedback function):**
  - Time Complexity: O(1) average case, O(n) worst case (due to hash collisions).

- **getAverageRatingForDriver Operation (getAverageRatingForDriver function):**
  - Time Complexity: O(n), where n is the number of feedback entries.
