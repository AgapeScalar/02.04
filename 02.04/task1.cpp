#include <fstream>
#include <cstring>

using namespace std;

class Point {
private:
    double x, y, z;

public:
    Point() : x(0), y(0), z(0) {}

    Point(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    inline double getX() const { return x; }
    inline double getY() const { return y; }
    inline double getZ() const { return z; }

    void input() {
        cout << "Enter x, y, z coordinates: ";
        cin >> x >> y >> z;
    }

    void display() const {
        cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")\n";
    }

    void saveToFile(const char* filename) const {
        ofstream file(filename);
        if (file) file << x << " " << y << " " << z;
    }

    void loadFromFile(const char* filename) {
        ifstream file(filename);
        if (file) file >> x >> y >> z;
    }
};
