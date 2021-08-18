#include <prime_breakdown_processor.h>

#include <algorithm>
#include <iostream>

#include "../csv-parser/include/csv.hpp"

using namespace csv;
using namespace std;

PrimeBreakdownProcessor::PrimeBreakdownProcessor() {

}

PrimeBreakdownProcessor::~PrimeBreakdownProcessor() {

}

void PrimeBreakdownProcessor::addItems(const char* filename) {
    CSVReader reader(filename);
    for (CSVRow& row : reader) {
        amazon_item entry;
        entry.id = row["Order ID"].get<>();
        entry.shipping_name = row["Shipping Address Name"].get<>();
        entry.subtotal = stod(row["Item Subtotal"].get<>().substr(1));
        entry.subtotal_tax = stod(row["Item Subtotal Tax"].get<>().substr(1));
        this->amazon_items.push_back(entry);
    }
}

void PrimeBreakdownProcessor::addItems(vector<amazon_item> items) {
    this->amazon_items.insert(this->amazon_items.end(), items.begin(), items.end());
}

void PrimeBreakdownProcessor::addRefunds(const char* filename) {
    CSVReader reader(filename);
    for (CSVRow &row : reader) {
        amazon_refund entry;
        entry.id = row["Order ID"].get<>();
        this->amazon_refunds.push_back(entry);
    }
}

void PrimeBreakdownProcessor::addRefunds(vector<amazon_refund> returns) {
    this->amazon_refunds.insert(this->amazon_refunds.end(), returns.begin(), returns.end());
}

map<string, double> PrimeBreakdownProcessor::processReport() {

    // ids of items that were returned
    vector<string> ids;
    for (vector<amazon_refund>::iterator it = this->amazon_refunds.begin(); it != this->amazon_refunds.end(); it++) {
        ids.push_back(it->id);
    }
    
    map<string, double> shipping_totals;
    for (auto const &item : this->amazon_items) {
        if (shipping_totals.find(item.shipping_name) == shipping_totals.end()) {
            shipping_totals.insert(pair<string, double>(item.shipping_name, 0));
        }
        if (find(ids.begin(), ids.end(), item.id) == ids.end()) {
            shipping_totals[item.shipping_name] += item.subtotal + item.subtotal_tax;;
        }
    }
    return shipping_totals;
}