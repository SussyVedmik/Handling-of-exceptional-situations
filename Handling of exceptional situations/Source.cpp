#include <iostream>
#include "ArrayValueCalculator.h"

using namespace std;

int main() {
    char validArray[4][4] = {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };
    char invalidDataArray[4][4] = {
        {"1", "2", "3", "4"},
        {"5", "six", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    try {
        cout << "Sum of valid array: " << ArrayValueCalculator::doCalc(validArray) << endl;
    }
    catch (const ArraySizeException& e) {
        cout << "ArraySizeException: " << e.what() << endl;
    }
    catch (const ArrayDataException& e) {
        cout << "ArrayDataException: " << e.what() << endl;
    }

    try {
        cout << "Sum of invalid data array: " << ArrayValueCalculator::doCalc(invalidDataArray) << endl;
    }
    catch (const ArraySizeException& e) {
        cout << "ArraySizeException: " << e.what() << endl;
    }
    catch (const ArrayDataException& e) {
        cout << "ArrayDataException: " << e.what() << endl;
    }

    return 0;
}
