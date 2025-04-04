#include "usr/utils.h"
#include "fmt/core.h"
#include "main.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

void utils::save_value(std::string name, float value) {

    std::string fullPath = fmt::format("/usd/{}.txt", name);

    FILE* value_file = fopen(fullPath.c_str(), "w");
    fputs(std::to_string(value).c_str(), value_file);

    fclose(value_file);
}

float utils::load_value(std::string name) {

    std::string fullPath = fmt::format("/usd/{}.txt", name);

    FILE* value_file = fopen(fullPath.c_str(), "r");

    if (value_file == nullptr) {
        return 0;
    }
    char buf[50];
    fread(buf, 1, 50, value_file);
    fclose(value_file);
    
    return std::stof(buf);
}

int utils::getIndex(std::vector<std::string>& v, std::string val) {
    for (int i = 0; i < v.size(); i++) {
      
          // When the element is found
        if (v[i] == val) {
            return i;
        }
    }
      
      // When the element is not found
      return -1;
}