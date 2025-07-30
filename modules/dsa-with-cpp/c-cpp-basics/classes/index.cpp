/**
 * Classes:
 * 1. The concept of classes is present only in CPP.
 * 2. Each class has properties and methods.
 * 3. Template classes are generic classes where the type itself comes as an argument. We can use the same class for multiple data types.
 */

#include<iostream>
using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;
    public:
        Rectangle(int l, int b);
        int area();
        int perimeter();
};

template<class T>
class Arithmetic {
    private:
        T a;
        T b;
    public:
        Arithmetic(T a, T b) {
            this->a = a;
            this->b = b;
        }
        T add() {
            return a + b;
        }

        T subtract() {
            return a - b;
        }
};

Rectangle::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}

int Rectangle::area() {
    return length * breadth;
}

int Rectangle::perimeter() {
    return 2 * (length + breadth);
}

int main() {
    Rectangle r(10, 5);
    cout << r.area() << endl;
    cout << r.perimeter() << endl;

    Arithmetic<int> a(10, 2);
    cout << a.add() << endl;
    cout << a.subtract() << endl;

    Arithmetic<float> b(10.2, 2.2);
    cout << b.add() << endl;
    cout << b.subtract() << endl;

    return 0;
}
