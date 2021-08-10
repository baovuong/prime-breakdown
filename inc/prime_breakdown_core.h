#include <map>
#include <string>
#include <vector>

struct order {
    std::string shipping_name;
    double item_total;
};

std::map<std::string, double> compute_total(std::vector<order>* orders);

void test_function();