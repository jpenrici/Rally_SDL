/*
 *   Compile:
 *      g++ counter.cpp -o Test_counter
 *
 *   Run:
 *      ./Test_counter
*/
#include "counter.h"

int main()
{
    Counter counter(5, 0, 9, 0);

    for (int i = 1; i <= 99999; ++i) {
        counter.add();
        cout << counter.view() << '\n';
    }

    return 0;
}