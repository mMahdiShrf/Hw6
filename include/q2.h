#ifndef Q2_H
#define Q2_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
#include<vector>

namespace q2
{
    struct Patient 
    {
        Patient(std::string _name,size_t _age,size_t _smokes,size_t _area_q, size_t _alkhol)
        :name{_name}
        ,age{_age}
        ,smokes{_smokes}
        ,area_q{_area_q}
        ,alkhol{_alkhol}
        {};
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };
    

    std::vector<Patient> read_file(std::string filename) 
    {
        // reading from file :
        std::vector<Patient> patients{};
        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf(); 
        std::string txt = buffer.str();

        // finding patients information using:
        std::regex pattern(R"((\w+)\ ?,(\w+)\ ?,(\d+)\,(\d+)\,(\d+)\,(\d+))"); //pattern for getting info
        std::smatch match;
        while(std::regex_search(txt, match, pattern))
        {   

            std::string first_name{match[1]};
            std::string last_name{match[2]};
            std::string name{first_name+" "+last_name};
            size_t age {static_cast<size_t>(std::stoi(match[3]))};
            size_t smokes {static_cast<size_t>(std::stoi(match[4]))};
            size_t area_q {static_cast<size_t>(std::stoi(match[5]))};
            size_t alkhol{static_cast<size_t>(std::stoi(match[6]))};
            patients.push_back(Patient{name,age,smokes,area_q,alkhol});
            txt = match.suffix().str();
        }
        return patients;
    }

    void sort(std::vector<Patient>& patients)
    {
        // using STL function sort with call back lambda function :
        std::sort(patients.begin(),patients.end(),[](Patient& p1, Patient& p2) 
        {
            size_t p1_prob{3*p1.age + 5*p1.smokes + 2*p1.area_q + 4*p1.alkhol};
            size_t p2_prob{3*p2.age + 5*p2.smokes + 2*p2.area_q + 4*p2.alkhol};
            return p1_prob > p2_prob;
        });
    }

}

#endif //Q2_H