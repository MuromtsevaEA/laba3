#include <iostream>
#include <vector>
#include <iomanip>
#include "MinMax.h"
#include "SVG.h"
#include <curl/curl.h>
using namespace std;
//

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
int main(int argc, char* argv[])
{
    if(argc>1)
    {
        for(int i=0; i<argc;i++)
        cout<<argv[]<<endl;
        return 0;

    CURL *curl = curl_easy_init();
if(curl) {
  CURLcode res;
  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
}
    curl_global_init(CURL_GLOBAL_ALL);
   const auto input=read_input(cin, true);
   const auto bins=make_histogram(input);
   show_histogram_svg(bins);

    return 0;
}}

