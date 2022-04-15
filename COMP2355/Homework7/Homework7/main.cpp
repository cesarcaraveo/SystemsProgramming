#include <iostream>
#include <limits>
#include <set>
#include <vector>

#include "Happy.h"
#include "Test.h"
#include "Vampire.h"
#include "SharedQueue.h"
#include "SharedSet.h"

void selfTest();

int main() {
    selfTest();

    std::vector<int> radices = {6, 8, 10, 12, 14, 16, 18, 20, 26, 30, 34};
    for (int radix : radices) {
        for (int digits = 1, low = 1, high = radix;;
             ++digits, low *= radix, high *= radix) {
            // Check overflow, if the range is too high to be represented, break and
            // go to the next radix. Note that here we are trying to detect if
            // (high - 1) * (high - 1) would exceed the representation of the type
            // int. In particular, the potentially overflowing multiplication is never
            // performed since the resulting value cannot be relied upon to indicate
            // if an overflow has occurred.
            if (std::numeric_limits<int>::max() / (high - 1) < high - 1)
                break;

            // We use sets to track the vampires because they might have multiple
            // fangs and we don't want to double count
            std::set<int> happy;
            std::set<int> sad;

            // Construct vampire numbers by going through all the fang combinations
            for (int i = low; i < high; ++i) {
                for (int j = i; j < high; ++j) {
                    if (isVampire(i, j, radix)) {
                        if (isHappy(i * j, radix)) {
                            happy.insert(i * j);
                        } else {
                            sad.insert(i * j);
                        }
                    }
                }
            }

            // If we have at least one vampire, report the results
            if (happy.size() + sad.size() > 0) {
                std::cout << "With radix " << radix << " and " << digits
                << " digits, there " << happy.size() << " happy vampires and "
                << sad.size() << " sad vampires, or "
                << ((static_cast<double>(happy.size()) /
                     (happy.size() + sad.size())) *
                    100)
                << "% happy\n";
            }
        }
    }

    return 0;
}

void selfTest() {
    testSumOfSquaredDigits();
    testHappy();

    testIntegerToString();
    testEndsWithZero();
    testVampire();
}

