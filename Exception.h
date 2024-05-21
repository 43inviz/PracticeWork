#ifndef STUDY_EXCEPTIONS_H
#define STUDY_EXCEPTIONS_H

#include <exception>

using namespace std;

class Exceptions : public exception{
private:
    char* message;
public:
    explicit Exceptions(char* message) : message(message) {};

    const char* what() const noexcept override {
        return message;
    };
};


#endif //STUDY_EXCEPTIONS_H
