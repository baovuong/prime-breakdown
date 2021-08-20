#include <iostream>
#include <string>
#include <sstream>

#include <getopt.h>
#include <unistd.h>

#include <cli.h>
#include <prime_breakdown_processor.h>

using namespace std;

string dollar_format(double d) {
    stringstream stream;
    stream.setf(ios::fixed);
    stream.precision(2);
    stream << "$" << d;
    return stream.str();
}

void print_usage() {
    cout << "Usage: prime-breakdown -i items-file-path -r returns-file-path" << endl;
}

CommandLineInterface::CommandLineInterface(int argc, char** argv) {
    this->_argc = argc;
    this->_argv = argv;
}

CommandLineInterface::~CommandLineInterface() {

}

void CommandLineInterface::execute() {

    struct option long_options[] = {
        {"items-file", required_argument, 0, 'i'},
        {"returns-file", optional_argument, 0, 'r'},
        {0, 0, 0, 0}
    };

    int opt;
    int long_index;
    string items_file;
    string returns_file;

    PrimeBreakdownProcessor processor;
    
    while ((opt = getopt_long(this->_argc, this->_argv, "i:r:", long_options, &long_index)) != -1) {
        switch (opt) {
            case 'i': 
                items_file = optarg;
                break;
            case 'r':
                returns_file = optarg;
                break;
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }
    cout << "items file: " << items_file << endl;
    cout << "returns file: " << returns_file << endl;

    processor.addItems(items_file.c_str());

    if (returns_file.size() > 0) {
        processor.addRefunds(returns_file.c_str());
    }
    map<string, double> report = processor.processReport();

    for (map<string, double>::iterator it = report.begin(); it != report.end(); it++) {
        cout << it->first << ": " << dollar_format(it->second) << endl;
    }
}