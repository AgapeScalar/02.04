#include <fstream>
#include <cstring>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) : numerator(num), denominator(den == 0 ? 1 : den) {
        simplify();
    }

    inline int getNumerator() const { return numerator; }
    inline int getDenominator() const { return denominator; }

    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Denominator can't be 0. Set to 1.\n";
            denominator = 1;
        }
        simplify();
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction add(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction subtract(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction divide(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
};
