#include <iostream>

#include "PrimeBreakdownConfig.h"

using namespace std;

int main(int argc, char** argv) {   
    if (argc < 2) {
        cout << argv[0] << " Version " << PrimeBreakdown_VERSION_MAJOR << "."
             << PrimeBreakdown_VERSION_MINOR << endl;
        return 1;
    }

    return 0;
}