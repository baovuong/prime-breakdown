#include <cli.h>

int main(int argc, char** argv) {

    CommandLineInterface cli(argc, argv);
    cli.execute();

    return 0;
}