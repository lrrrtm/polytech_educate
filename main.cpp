#include "iostream"
#include "cmath"

using namespace std;

class Calculate {
public:
    int mantissa;
    int exponent;

    Calculate(double num){
        int _exponent = 0;

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

    void Display() {
        cout << mantissa << " " << exponent << endl;
    }
};

int main(){
    setlocale(LC_ALL, "RU");
    Calculate _calculate(0.0152);
    _calculate.Display();

    return 0;
}


