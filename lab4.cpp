#include <iostream>
#include <vector>
#include <iomanip>
#include "MinMax.h"
#include "SVG.h"
using namespace std;


Input
read_input(istream& in, bool prompt) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr<<"Enter number of buckets";
    size_t bin_count;
    cin>>bin_count;
    data.bin_count=bin_count;

    return data;
}
int main()
{
   const auto input=read_input(cin, true);
   const auto bins=make_histogram(input);
   show_histogram_svg(bins);

    return 0;
}

