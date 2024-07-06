# Driver Payment Settlement System

## Data Structures Used:
- Unordered map (hash table) for storing driver payments.

## Challenges:
- Handling hash collisions efficiently.
- Ensuring accurate and timely updates to driver payment records.
- Managing a potentially large number of driver entries.

## Benefits:
- Efficient processing and retrieval of payment information.
- Real-time updates to driver payment records.
- Scalable solution for managing payments for a large number of drivers.

## Algorithm:
The system processes payments by updating an unordered map that keeps track of the total payments for each driver. Each payment is added to the driver's total. The total payment for a driver can be retrieved efficiently using the driver's ID as the key.

### Example Code:
[Payment](https://github.com/Prajwal1110/APS.github.io/blob/4fe48b6b49d7cb50246ddfd726f41dd9fa6cd80f/codes/payment.cpp)

#### Time Complexity:
- **processPayment Operation (processPayment function):**
  - Time Complexity: O(1) on average, O(n) in the worst case due to hash collisions.
  - Explanation: Processing a payment involves inserting or updating an entry in the hash map, which has an average time complexity of O(1). In the worst case, due to hash collisions, it could degrade to O(n).

- **getTotalPaymentForDriver Operation (getTotalPaymentForDriver function):**
  - Time Complexity: O(1)
  - Explanation: Retrieving the total payment for a driver involves looking up an entry in the hash map, which has an average time complexity of O(1).

#### Space Complexity:
- **PaymentSystem Class:**
  - Space Complexity: O(n)
  - Explanation: The space complexity is linear in relation to the number of drivers since the hash map stores payment data for each driver.
