#ifndef Q1_H
#define Q1_H

#include<iostream>
#include<cmath>
#include <limits>


namespace q1
{
    template<typename T, typename Func>
    T derivate(T point,Func func)
    {
        return (func(point+ 0.001) - func(point - 0.001))/0.002;
    }

    template<typename T, typename Func>
    T gradient_descent(T inital_value,T step_size, Func func=Func{})
    {   
        T second_value{};
        T first_value { inital_value };
        bool flag{true};
        do 
        {   
            second_value = first_value - step_size*derivate(first_value,func);
            if (std::abs(second_value - first_value) > 1e-50)
                first_value = second_value;
            else
                flag = false;
        }
        while(flag);
        return second_value;
    }
}


#endif //Q1_H