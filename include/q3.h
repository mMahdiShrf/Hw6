#ifndef Q3_H
#define Q3_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
#include<vector>
#include<queue>


namespace q3
{   
    struct Flight
    {
    Flight(std::string _flight_number, size_t _duration, size_t _connections, size_t _connection_times, size_t _price)
    :flight_number{_flight_number}
    ,duration{_duration}
    ,connections{_connections}
    ,connection_times{_connection_times}
    ,price{_price}
    {}
	std::string flight_number;
	size_t duration;
	size_t connections;
	size_t connection_times;
	size_t price;
    };

    // function to turn /d/dh/d/dm format to time duration
    size_t time2minute(std::string time)
    {
        if(time.empty())
            return 0;
        std::regex pattern(R"((\d+)h(\d+)?m?)"); // pattern to extract 
        std::smatch match;
        size_t minute{};
        std::regex_search(time, match,pattern);
        minute += static_cast<size_t>(std::stoi(match[1]))*60;
        std::string sth {match[2]}; 
        if(sth.empty())
            return minute;
        else
            return minute + static_cast<size_t>(std::stoi(match[2]));
    }

    // callback function to sort priority queue 
    auto comparison {[](Flight f1, Flight f2){
        return (f1.duration+f1.connection_times+ 3*f1.price) >
        (f2.duration+f2.connection_times+ 3*f2.price);
    }};

    auto gather_flights(std::string filename)
    {   
        std::priority_queue<Flight,std::vector<Flight>,decltype(comparison)> flights{comparison};
        // reading from file:
        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string txt = buffer.str();

        // finding infromation using regex:
        std::regex pattern(R"(\d+\-\ flight_number:(\w+)\ \-\ duration:(\w+)\ \-\ connections:(\d+)\ \-\ connection_times:(\w+\,?)(\w+\,?)?(\w+\,?)?\ \-\ price:(\d+))");
        std::smatch match;
        while(std::regex_search(txt, match, pattern))
        {   
            std::string flight_number{match[1]};
            size_t duration{time2minute(match[2])};
            size_t connections{static_cast<size_t>(std::stoi(match[3]))};
            size_t connections_times{};
            connections_times +=  time2minute(match[4]);
            connections_times +=  time2minute(match[5]);
            connections_times +=  time2minute(match[6]);
            size_t price{static_cast<size_t>(std::stoi(match[7]))};
            flights.push(Flight{flight_number,duration,connections,connections_times,price});
            txt = match.suffix().str();
        }
        return flights;
    }
};

    

#endif //Q3_H