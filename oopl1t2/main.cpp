#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    void setReal(float r) { real = r; }
    void setImag(float i) { imag = i; }
    float getReal() const { return real; }
    float getImag() const { return imag; }

    void print() const {
        if (imag < 0)
            cout << real << " - " << fabs(imag) << "i" << endl;
        else
            cout << real << " + " << imag << "i" << endl;
    }

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex subtract(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
};

int main() {
    cout<<"using class\n";
    Complex c1(7, 2);
    Complex c2(3, 4);

    Complex result;

    result = c1.add(c2);
    result.print();

    result = c1.subtract(c2);
    result.print();

    return 0;
}
