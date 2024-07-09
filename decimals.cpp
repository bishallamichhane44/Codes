#include <iostream>
#include <vector>
#include <cmath>


int recurringCycleLength(int n) {
    std::vector<int> remainders(n, 0);
    int remainder = 1;
    int position = 0;

    while (remainders[remainder] == 0 && remainder != 0) {
        remainders[remainder] = position;
        remainder = (remainder * 10) % n;
        position++;
    }

    if (remainder == 0) {
        return 0; 
    } else {
        return position - remainders[remainder]; 
    }
}

int main() {
    int maxLength = 0;
    int numberWithMaxCycle = 0;

    for (int i = 2; i < 1000; i++) {
        int length = recurringCycleLength(i);
        if (length > maxLength) {
            maxLength = length;
            numberWithMaxCycle = i;
        }
    }

    std::cout << "Answer is: " << numberWithMaxCycle << std::endl;

    return 0;
}
