#include <iostream>
#include <sstream>

#include <prime_breakdown_core.h>

using namespace std;

string dollar_format(double d) {
    stringstream stream;
    stream.setf(ios::fixed);
    stream.precision(2);
    stream << "$" << d;
    return stream.str();
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        return 1;
    }

    vector<amazon_item> items = csv_to_items(argv[1]);
    map<string, double> result = compute_total(&items);

    for (map<string, double>::iterator it = result.begin(); it != result.end(); it++) {
        cout << it->first << ": " << dollar_format(it->second) << endl;
    }

    return 0;
}