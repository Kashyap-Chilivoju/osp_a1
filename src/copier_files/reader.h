#ifndef READER_H
#define READER_H

#include "writer.h"
#include <fstream>
#include <string>

class reader {
public:
    reader(const std::string& name, writer& myWriter);
    void run();

private:
    std::ifstream in;
    writer& thewriter;
};

#endif
