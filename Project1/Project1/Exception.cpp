#include "Exception.h"

Exception::Exception(const std::string& msg) : errorMessage(msg) {}

const char* Exception::what() const noexcept {
    return errorMessage.c_str();
}