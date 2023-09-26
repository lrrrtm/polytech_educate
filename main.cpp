#include <iostream>
#include <cmath>

using namespace std;

class Calculate {
public:
    int mantissa;
    int exponent;
    int sign = 0;

    Calculate(double num){
        int _exponent = 0;

        if (num > 0) {
            sign = 1;
        } else if (num < 0) {
            sign = -1;
            num = -num;
        }

        if (sign != 0) {
            if (num > 1) {
                while (num > 1){
                    num /= 2;
                    _exponent++;
                }
            } else {
                while (num < 0.1){
                    num *= 2;
                    _exponent--;
                }
            }

            exponent = _exponent;
            num *= 1000;
            mantissa = (int) round(num);
        }
    }

    void add(){

    }

    void subtract(){

    }

    void multiply(){

    }

    void DisplayInput() {
        if (sign != 0) {
            cout << "Sign: " << sign << ", Mantissa: " << mantissa << ", Exponent: " << exponent << endl;
        } else {
            cout << "Zero has no mantissa or exponent" << endl;
        }
    }

};

int main(){
    setlocale(LC_ALL, "RU");

    Calculate posCalculate(0.0152);
    Calculate negCalculate(-0.0152);
    Calculate zeroCalculate(0.0);

    posCalculate.DisplayInput();
    negCalculate.DisplayInput();
    zeroCalculate.DisplayInput();

    return 0;
}
