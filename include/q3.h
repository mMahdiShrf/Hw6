#ifndef Q3_H
#define Q3_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
#include<vector>


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
}

#endif //Q3_H