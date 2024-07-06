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
[Feedback](https://github.com/Prajwal1110/APS.github.io/blob/9206368f60a7b4d12f83a5bc04531f1ed1993bd2/codes/feedback.cpp)

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
