#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// Structure to represent a point (location)
struct Point {
    int x, y;
};

// Function to calculate Euclidean distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Nearest neighbor algorithm to solve TSP
vector<int> nearestNeighborTSP(const vector<Point>& points) {
    int n = points.size();
    vector<bool> visited(n, false);
    vector<int> path;
    int current = 0; // Start from the first point

    path.push_back(current);
    visited[current] = true;

    for (int i = 0; i < n - 1; ++i) {
        int nearest = -1;
        double minDist = numeric_limits<double>::max();
        
        // Find nearest unvisited neighbor
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && j != current) {
                double dist = distance(points[current], points[j]);
                if (dist < minDist) {
                    minDist = dist;
                    nearest = j;
                }
            }
        }

        // Move to the nearest neighbor
        current = nearest;
        path.push_back(current);
        visited[current] = true;
    }

    // Return the path
    return path;
}

int main() {
    // Example usage of nearest neighbor algorithm for TSP
    vector<Point> points = {{0, 0}, {1, 2}, {3, 1}, {4, 3}, {2, 4}};

    vector<int> path = nearestNeighborTSP(points);

    cout << "Optimal path for TSP:";
    for (int point : path) {
        cout << " " << point;
    }
    cout << endl;

    return 0;
}
