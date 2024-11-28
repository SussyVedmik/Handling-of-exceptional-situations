#include "ArrayValueCalculator.h"
#include <cstring>
#include <stdlib.h>

bool isValidInteger(const char* str) {
    if (str == nullptr || *str == '\0') {
        return false;
    }
    int i = 0;
    if (str[0] == '-') {
        i = 1;
        if (str[1] == '\0') {
            return false;
        }
    }
    for (; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }

    return true;
}

int ArrayValueCalculator::doCalc(const char array[4][4]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cchar* value = array[i][j];
            if (!isValidInteger(value)) {
                char cellInfo[20];
                strcpy(cellInfo, "[");
                char buffer[5];
                sprintf(buffer, "%d", i);
                strcat(cellInfo, buffer);
                strcat(cellInfo, "][");
                sprintf(buffer, "%d", j);
                strcat(cellInfo, buffer);
                strcat(cellInfo, "]");
                throw ArrayDataException(cellInfo);
            }
            sum += atoi(value);
        }
    }

    return sum;
}