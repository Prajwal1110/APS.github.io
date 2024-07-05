#include <iostream>
#include <vector>

using namespace std;

// Define a structure for Point and Rectangle
struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};

struct Rectangle {
    double x, y, width, height;
    Rectangle(double _x, double _y, double _w, double _h) : x(_x), y(_y), width(_w), height(_h) {}

    bool contains(const Point& point) const {
        return (point.x >= x && point.x <= x + width && point.y >= y && point.y <= y + height);
    }

    bool intersects(const Rectangle& range) const {
        return !(range.x > x + width || range.x + range.width < x ||
                 range.y > y + height || range.y + range.height < y);
    }
};

// QuadTree node structure
class QuadTree {
private:
    Rectangle boundary;
    int capacity;
    vector<Point> points;
    bool divided;
    QuadTree* northeast;
    QuadTree* northwest;
    QuadTree* southeast;
    QuadTree* southwest;

public:
    QuadTree(const Rectangle& _boundary, int _capacity)
        : boundary(_boundary), capacity(_capacity), divided(false),
          northeast(nullptr), northwest(nullptr), southeast(nullptr), southwest(nullptr) {}

    void subdivide() {
        double x = boundary.x;
        double y = boundary.y;
        double hw = boundary.width / 2.0; // Half width
        double hh = boundary.height / 2.0; // Half height

        Rectangle ne(x + hw, y, hw, hh);
        northeast = new QuadTree(ne, capacity);

        Rectangle nw(x, y, hw, hh);
        northwest = new QuadTree(nw, capacity);

        Rectangle se(x + hw, y + hh, hw, hh);
        southeast = new QuadTree(se, capacity);

        Rectangle sw(x, y + hh, hw, hh);
        southwest = new QuadTree(sw, capacity);

        divided = true;
    }

    bool insert(const Point& point) {
        if (!boundary.contains(point))
            return false;

        if (points.size() < capacity) {
            points.push_back(point);
            return true;
        }

        if (!divided)
            subdivide();

        if (northeast->insert(point)) return true;
        if (northwest->insert(point)) return true;
        if (southeast->insert(point)) return true;
        if (southwest->insert(point)) return true;

        // If point cannot be inserted in any quadrant (should not reach here ideally)
        return false;
    }

    vector<Point> query(const Rectangle& range) {
        vector<Point> found_points;
        if (!boundary.intersects(range))
            return found_points;

        for (const auto& p : points) {
            if (range.contains(p))
                found_points.push_back(p);
        }

        if (divided) {
            auto ne_points = northeast->query(range);
            found_points.insert(found_points.end(), ne_points.begin(), ne_points.end());

            auto nw_points = northwest->query(range);
            found_points.insert(found_points.end(), nw_points.begin(), nw_points.end());

            auto se_points = southeast->query(range);
            found_points.insert(found_points.end(), se_points.begin(), se_points.end());

            auto sw_points = southwest->query(range);
            found_points.insert(found_points.end(), sw_points.begin(), sw_points.end());
        }

        return found_points;
    }
};

int main() {
    Rectangle boundary(0, 0, 400, 400);
    QuadTree qt(boundary, 4);

    qt.insert(Point(100, 100));
    qt.insert(Point(200, 200));
    
    Rectangle query_range(150, 150, 50, 50);
    vector<Point> found_points = qt.query(query_range);

    cout << "Points found within the query range:" << endl;
    for (const auto& p : found_points) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}
