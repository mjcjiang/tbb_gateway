#include "custome_utils.h"

#include <fstream>
#include <nlohmann/json.hpp>

bool create_socks_and_subs_file(const char* file_path) {
    if(std::ifstream(file_path)) {
        return false;
    }

    std::ofstream file(file_path);
    if(!file) {
        return false;
    }

    nlohmann::json data;
    file << data.dump();
    file.close();
    
    return true;
}
