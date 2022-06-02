
#include <gtest/gtest.h>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
     
       //auto flights{q3::gather_flight("flights.txt")};
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}