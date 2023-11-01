#include "convert_to_float.h"


float convert_to_float(const char* str) {
    char* end;
    setlocale(LC_NUMERIC, "en_US.utf8"); // Установка локали с плавающей точкой в формате US
    float result = strtof(str, &end);
    return result;
}