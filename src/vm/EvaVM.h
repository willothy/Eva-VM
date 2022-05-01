/**
 * @file EvaVM.h
 * @author Will Hopkins (willothyh@gmail.com)
 * @brief Eva Virtual machine
 * @version 0.1
 * @date 2022-04-03
 */

#ifndef __EVA_VM_H
#define __EVA_VM_H

#include <string>
#include <vector>

#include "../bytecode/OpCode.h"
#include "../logger/Logger.h"

/** Reads the current byte in bytecode and advnaces ip */
#define READ_BYTE() *ip++

class EvaVM {
public:
    EvaVM() {

    }

    void exec(const std::string str) {
        // Parse the program into AST
        //auto ast = parser->parse(program);

        // Compile program to Eva bytecode
        // code = compiler->compile(ast);

        code = {OP_HALT};

        // Set instructions pointer to the beginning:
        ip = &code[0];

        return eval();
    }

    /**
     * @brief Main eval loop
     * Non-recursive in a bytecode interpreter
     */
    void eval() {
        for (;;) {
            auto opcode = READ_BYTE();
            switch (opcode) {
                case OP_HALT:
                    return;
                default:
                    DIE << "Unknown opcode: " << std::hex << opcode;
            }
        }
    }

    /**
     * @brief Instruction pointer / program counter
     */
    uint8_t* ip;

    /**
     * @brief Bytecode
     */
    std::vector<uint8_t> code;
};

#endif