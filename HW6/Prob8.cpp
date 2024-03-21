#include <iostream>
using namespace std;

class Line {
    int length;
public:
    Line(int n = 1) : length(n) {}

    // Overload the >> operator
    friend istream& operator>>(istream& input, Line& line) {
        cout << "Enter length: ";
        input >> line.length;
        return input;
    }

    // Overload the << operator
    friend ostream& operator<<(ostream& output, const Line& line) {
        for (int i = 0; i < line.length; ++i) {
            output << '*';
        }
        output << endl;  // Add a newline character after printing the line
        return output;
    }
};

int main() {
    Line a, b(10), c;
    cin >> a >> b;
    cout << a;
    cout << b;
    cout << c;
    return 0;
}