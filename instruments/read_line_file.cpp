#include "read_line_file.h"

char* read_line_file(std::ifstream& file) {
    char c;
    int size = 0;

    int bufferSize = 1;
    char* buffer = new char[bufferSize];

    while (file.get(c) && c != '\n') {
        if (size == bufferSize - 1) {
            bufferSize *= 2;
            char* newBuffer = new char[bufferSize];
            for (int i = 0; i < size; ++i) {
                newBuffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = newBuffer;
        }

        buffer[size] = c;
        ++size;
    }

    char* trimmedBuffer = new char[size + 1];
    for (int i = 0; i < size; ++i) {
        trimmedBuffer[i] = buffer[i];
    }
    trimmedBuffer[size] = '\0';

    delete[] buffer;

    return trimmedBuffer;
}