#include <prime_breakdown_core.h>

#include <algorithm>
#include <iostream>

#include "../csv-parser/include/csv.hpp"

using namespace csv;
using namespace std;

map<string, double> compute_total(vector<amazon_item>* items) {
    map<string, double> shipping_totals;

    for (auto const &item : *items) {
        if (shipping_totals.find(item.shipping_name) == shipping_totals.end()) {
            shipping_totals.insert(pair<string, double>(item.shipping_name, 0.0));
        }
        shipping_totals[item.shipping_name] += item.subtotal + item.subtotal_tax;
    }    
    return shipping_totals;
}

vector<amazon_item> csv_to_items(const char* filename) {
    vector<amazon_item> output;
    CSVReader reader(filename);
    for (auto& row : reader) {
        amazon_item entry;
        entry.id = row["Order ID"].get<>();
        entry.shipping_name = row["Shipping Address Name"].get<>();
        entry.subtotal = stod(row["Item Subtotal"].get<>().substr(1));
        entry.subtotal_tax = stod(row["Item Subtotal Tax"].get<>().substr(1));
        output.push_back(entry);
    }
    return output;
}