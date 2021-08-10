#include <prime_breakdown_core.h>

#include <algorithm>
#include <iostream>

#include <csv.hpp>

using namespace csv;
using namespace std;

map<string, double> compute_total(vector<order>* orders) {
    map<string, double> shipping_totals;

    for (auto const &order : *orders) {
        if (shipping_totals.find(order.shipping_name) == shipping_totals.end()) {
            shipping_totals.insert(pair<string, double>(order.shipping_name, 0.0));
        }
        shipping_totals[order.shipping_name] += order.item_total;
    }    
    return shipping_totals;
}

vector<order> csv_to_orders(const char* filename) {
    vector<order> output;
    CSVReader reader(filename);
    for (auto& row : reader) {
        order entry;
        entry.shipping_name = row["Shipping Address Name"].get<>();
        entry.item_total = stod(row["Item Total"].get<>().substr(1));
        output.push_back(entry);
    }
    return output;
}