#include <iostream>
#include <stack>
#include <vector>
#define MEMORY_SIZE 30000

struct Operation {
    char type;
    size_t operand;
};

std::vector<Operation> prepros(const std::string& code) {
    std::vector<Operation> operations;
    std::stack<std::pair<size_t, size_t>> loopStack;

    for (int i = 0; i < code.length(); i++){
        const char c = code[i];
        switch (c) {

            case '[': {
                loopStack.emplace(operations.size(), i);
                operations.push_back({c, 0});
                continue;
            }

            case ']': {
                if (loopStack.empty()) {
                    throw std::runtime_error("Syntax Error: Unexpected ']' at position " + std::to_string(i));
                }

                auto startInfo = loopStack.top();
                loopStack.pop();
                operations[startInfo.first].operand = operations.size();
                operations.push_back({c, startInfo.first});
                continue;
            }

            case'+':
            case '-':
            case '.':
            case ',':
            case '<':
            case '>': {
                size_t count = 1;
                while (i + 1 < code.length() && code[i + 1] == c) {
                    count++;
                    i++;
                }
                operations.push_back({c, count});
                break;
            }
            default:
                break;
        }
    }
    if (!loopStack.empty()) {
        throw std::runtime_error("Syntax Error: Unclosed '[' at " + std::to_string(loopStack.top().second));
    }
    return operations;
}

void execute(const std::vector<Operation>& ops) {
    std::vector<unsigned char> memory (MEMORY_SIZE, 0);
    size_t ptr = 0;
    size_t ip = 0;
    while (ip < ops.size()) {
        const Operation& op = ops[ip];

        switch (op.type){
            case '+': {
                memory[ptr] += op.operand;
                break;
            }
            case '-': {
                memory[ptr] -= op.operand;
                break;
            }
            case '>': {
                ptr += op.operand;
                if (ptr >= memory.size()) {
                    ptr %= MEMORY_SIZE;
                }
                break;
            }
            case '<': {
                ptr -= op.operand;
                if (ptr >= memory.size()) {
                    ptr %= MEMORY_SIZE;
                }
                break;
            }
            case '.': {
                for (int i = 0; i < op.operand; i++) std::cout << (memory[ptr]);
                break;
            }
            case ',': {
                for (int i = 0; i < op.operand; i++) {
                    char c;
                    if (std::cin.get(c)) {
                        memory[ptr] = c;
                    }
                }
                break;
            }
            case '[': {
                if (memory[ptr] == 0) ip = op.operand;
                break;
            }
            case ']': {
                if (memory[ptr] != 0) ip = op.operand;
                break;
            }
        }
        ip++;
    }
}

int main(){
    std::string sourceCode(
            (std::istreambuf_iterator<char>(std::cin)),
            (std::istreambuf_iterator<char>())
    );
    if (sourceCode.empty()) return 0;

    try {
        std::vector<Operation> exeCode = prepros(sourceCode);
        execute(exeCode);
    } catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
