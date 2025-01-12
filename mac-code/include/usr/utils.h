#include <string>
#include <vector>
namespace utils { // namespaces for utils
    void save_value(std::string name, float value); // saves float to file on sd card
    float load_value (std::string name); // loads float from file on sd card
    int getIndex(std::vector<std::string>& vec, std::string element);
}