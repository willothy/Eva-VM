#include <iostream>
#include "src/vm/EvaVM.h"

int main (int argc, const char* argv[]) {
    EvaVM vm;

    vm.exec(R"(

        42

    )");

    std::cout << "Done" << std::endl;

    return 0;
}