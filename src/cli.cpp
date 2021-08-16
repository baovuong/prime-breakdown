#include <iostream>
#include <string>

#include <getopt.h>
#include <unistd.h>

#include <cli.h>

using namespace std;

void print_usage() {
    cout << "Usage: prime-breakdown -i items-file-path -r returns-file-path" << endl;

}

void process_commandline_args(int argc, char** argv) {

    struct option long_options[] = {
        {"items-file", required_argument, 0, 'i'},
        {"returns-file", optional_argument, 0, 'r'},
        {0, 0, 0, 0}
    };

    int opt;
    int long_index;
    string items_file;
    string returns_file;
    
    while ((opt = getopt_long(argc, argv, "i:r:", long_options, &long_index)) != -1) {
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
}