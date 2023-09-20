#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <string>
#include <deque>

class writer {
public:
    writer(const std::string& name);
    void run();
    void append(const std::string& line);

private:
    std::ofstream out;
    std::deque<std::string> queue;
};

#endif
