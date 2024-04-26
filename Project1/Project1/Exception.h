#pragma once
#include <exception>
#include <string>

class Exception : public std::exception {
private:
    std::string errorMessage;
public:
    Exception(const std::string& msg);
    const char* what() const noexcept override;
};