# Ride Matching Algorithm using Priority Queues

## Data Structures
- **Priority Queues:** Utilized as min-heaps for efficient retrieval of the nearest available driver or rider.

## Challenges
- **Efficiency:** Matching users with drivers in real-time to minimize wait times.
- **Scalability:** Handling a large number of simultaneous requests.

## Benefits
- **Reduced Wait Times:** Users are matched with drivers efficiently.
- **Improved User Satisfaction:** Faster response times enhance user experience.

## Algorithm
- **Heap Implementation:** Using priority_queue in C++ for min-heap operations.
- **Matching Strategy:** Match the closest available driver to a rider based on priority.

## Example Code (C++)
[RideMatching.cpp](https://github.com/Prajwal1110/APS.github.io/blob/dd814ca6441ab74d7a07228edf141e5bc4d9fe49/codes/ridematching.cpp)

### Time Complexity:
- **addDriver Operation (`addDriver` function):**
  - **Time Complexity:** O(log D), where D is the number of drivers in the priority queue.
  - Explanation: Adding a driver to the priority queue (`drivers`) involves inserting the driver into the heap, which has a time complexity of O(log D).

- **addRider Operation (`addRider` function):**
  - **Time Complexity:** O(log R), where R is the number of riders in the priority queue.
  - Explanation: Adding a rider to the priority queue (`riders`) involves inserting the rider into the heap, which has a time complexity of O(log R).

- **matchRide Operation (`matchRide` function):**
  - **Time Complexity:** O(log D + log R)
  - Explanation: Finding a match between the top driver and top rider involves retrieving and removing elements from the priority queues (`drivers` and `riders`). Both operations have a time complexity of O(log D) and O(log R) respectively, resulting in a combined time complexity of O(log D + log R) for `matchRide`.

### Space Complexity:
- **Space Complexity:** O(D + R)
  - Explanation: The space complexity is O(D + R), where D is the number of drivers and R is the number of riders currently in their respective priority queues (`drivers` and `riders`). Each driver and rider object takes up space in its priority queue.

