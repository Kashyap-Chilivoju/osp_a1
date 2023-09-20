#include "writer.h"

writer::writer(const std::string& name) : out(name) {}

void writer::run() {
    while (!queue.empty()) {
        out << queue.front();
        queue.pop_front();
        if(!queue.empty())
            out<<std::endl;
    }
    out.close();
}

void writer::append(const std::string& line) {
    queue.push_back(line);
}
