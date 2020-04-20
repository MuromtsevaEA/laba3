#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED
#include <vector>

using namespace std;

void find_minmax(vector<double> numbers, double& min, double& max)
{
    min=numbers[0];
    max=numbers[0];
    for(double number:numbers)
    {
        if(number>max)
            max=number;
        if(number<min)
            min=number;
    }
}


#endif // MINMAX_H_INCLUDED
