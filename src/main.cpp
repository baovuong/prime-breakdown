#include <iostream>
#include <prime_breakdown_core.h>
#include <vector>

using namespace std;


int main(int argc, char** argv) {
    if (argc <= 1) {
        return 1;
    }

    vector<order> orders = csv_to_orders(argv[1]);
    map<string, double> result = compute_total(&orders);

    for (map<string, double>::iterator it = result.begin(); it != result.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}