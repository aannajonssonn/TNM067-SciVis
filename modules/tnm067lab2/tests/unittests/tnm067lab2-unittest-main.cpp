#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:CONSOLE")
#endif

#include <warn/push>
#include <warn/ignore/all>
#include <gtest/gtest.h>
#include <warn/pop>

#include <iostream>

int main(int argc, char** argv) {
    int ret = -1;
    {
        ::testing::InitGoogleTest(&argc, argv);
        ret = RUN_ALL_TESTS();
    }

    std::cout << "Press any key to exit ..." << std::endl;
    std::cin.get();

    return ret;
}