# Real-Time Tracking using Quad Trees

## Data Structures
- **Geospatial Data Structures:** Quad trees for efficient storage and retrieval of spatial data.

## Challenges
- **Accuracy:** Ensuring precise vehicle tracking in real-time.
- **Efficiency:** Handling rapid updates and queries for dynamic locations.

## Benefits
- **Enhanced Navigation:** Improved accuracy in vehicle positioning.
- **Route Optimization:** Efficient pathfinding and route planning based on current vehicle locations.

## Algorithm
- **Quad Tree Implementation:** Spatial indexing to divide space into hierarchical quadrants for fast location queries.

## Example Code (C++)
[Real-Time Tracking](https://github.com/Prajwal1110/APS.github.io/blob/740ac29be2dc2a12d4d0245da38fb9664849b415/codes/realtimetracking.cpp)

**Space and Time Complexity**:
### Time Complexity:
- **Insert Operation (`insert` function):**
  - **Average Case:** O(log n) - Each insertion operation involves recursively subdividing the space, reducing the search area logarithmically.
  - **Worst Case:** O(n) - In degenerate cases, such as when points are inserted in a way that requires repeated subdivision without balancing, it could degrade to linear time.

- **Query Operation (`query` function):**
  - **Time Complexity:** O(k + log n) - Where k is the number of points found within the query range. This complexity arises from checking each point and navigating the tree structure.

### Space Complexity:
- **Space Complexity:** O(n) - Where n is the number of points inserted into the QuadTree. Each point is stored once, and the QuadTree nodes also contribute to the space complexity linearly with the number of subdivisions and points.
