#include <map>
#include <string>
#include <vector>

struct amazon_item {
    std::string id;
    std::string name;
    std::string shipping_name;
    double subtotal_tax;
    double subtotal;
    double total;
};

struct amazon_return {
    std::string id;
};

std::vector<amazon_item> csv_to_items(const char* filename);
std::vector<amazon_return> csv_to_returns(const char* filename);
std::map<std::string, double> compute_total(std::vector<amazon_item>* items);
