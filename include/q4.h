#ifndef Q4_H
#define Q4_H

#include<iostream>
#include<vector>
#include<queue>
#include<numeric>

namespace q4
{
    struct Vector2D
    {
        Vector2D(double _x, double _y)
        :x{_x}
        ,y{_y}{}
        double x{};
        double y{}; 
    };

    struct Sensor
    {
        Sensor(Vector2D _pos, double _accuracy)
        :pos{_pos}
        ,accuracy{_accuracy}{}
        Vector2D pos;
        double accuracy;    
    };
    Vector2D kalman_filter(std::vector<Sensor> sensors)
    {
        double sum_x{};
        double sum_y{};
        double weights{};
        sum_x  = std::accumulate(sensors.begin(),sensors.end(),sum_x,[](double sum_result,Sensor s){return sum_result+s.pos.x*s.accuracy;});
        sum_y = std::accumulate(sensors.begin(),sensors.end(),sum_y,[](double sum_result,Sensor s){return sum_result+s.pos.y*s.accuracy;});
        weights=  std::accumulate(sensors.begin(),sensors.end(),weights,[](double sum_result,Sensor s){return sum_result+s.accuracy;});
        return Vector2D{sum_x/weights,sum_y/weights};
    }

}

#endif //Q4_H