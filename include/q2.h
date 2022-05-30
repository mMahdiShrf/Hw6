#ifndef Q2_H
#define Q2_H

#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>

namespace q2
{
    struct Patient
    {
        Patient(std::string _name,size_t _age,size_t _smokes,size_t _area_q, size_t _alkhol)
        :name{_name}
        ,age{_age}
        ,somokes{_smokes}
        ,area_q{_area_q}
        ,alkhol{_alkhol}
        {}
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };
}

#endif //Q2_H