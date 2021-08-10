#include <map>
#include <string>
#include <vector>

struct order {
    std::string shipping_name;
    double item_total;
};


std::vector<order> csv_to_orders(const char* filename);

std::map<std::string, double> compute_total(std::vector<order>* orders);
