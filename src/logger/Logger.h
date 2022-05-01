#ifndef __LOGGER_H
#define __LOGGER_H

#include <sstream>

class ErrorLogMessage : public std::basic_ostringstream<char> {
    public:
    ~ErrorLogMessage() {
        fprintf(stderr, "Fatal error: %s\n", str().c_str());
        exit(EXIT_FAILURE);
    }
};

#define DIE ErrorLogMessage()

#define log(value) std::cout << #value << " = " << (value) << "\n"

#endif