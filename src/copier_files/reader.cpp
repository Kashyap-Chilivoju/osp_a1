#include "reader.h"

reader::reader(const std::string& name, writer& myWriter) : in(name), thewriter(myWriter) {}

void reader::run() {
    std::string line;
    while (std::getline(in, line)) {
        thewriter.append(line);
    }
    thewriter.run();
}
