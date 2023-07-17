#include <iostream>
#include <string>

class Test {
 public:
    Test(const std::string& name)
        :name_(name) {
    }

    std::string get_name();
 private:
    std::string name_;
};
