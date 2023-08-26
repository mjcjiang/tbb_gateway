#include <pstl/execution_impl.h>
#include <tbb/tbb.h>

#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    tbb::parallel_invoke([]() { std::cout << "Hello " << std::endl; },
                         []() { std::cout << "TBB!" << std::endl; });
    return 0;
}
