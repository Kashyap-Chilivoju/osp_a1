#include "reader.h"
#include "writer.h"
#include <iostream>
#include <ctime>
using namespace std;
int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " infile outfile\n";
        return 1;
    }

    cout<<"copier " << argv[1]<<std::endl;
    writer myWriter(argv[2]);
    reader myReader(argv[1], myWriter);

    clock_t start = clock();
    myReader.run();
    clock_t end = clock();

    clock_t duration = end - start;
    int seconds = (int)duration / (double)CLOCKS_PER_SEC;

    std::cout << "Time elapsed: " << seconds << " seconds" << std::endl;

    return EXIT_SUCCESS;
}
