#include <iostream>
#include <vector>
#include <iomanip>
#include "MinMax.h"
#include "SVG.h"
#include <curl/curl.h>
#include <sstream>
#include <string>
using namespace std;
//

Input
read_input(istream& in, bool prompt)
 {
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

Input download(const string& address)
 {
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if(curl)
        {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        res = curl_easy_perform(curl);
        if (res) {
            cerr << curl_easy_strerror(res) << endl;
            exit(1);
        }}
    curl_easy_cleanup(curl);
    return read_input(buffer, false);
}
int main(int argc, char* argv[]) {
    Input input;
    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = read_input(cin, true);
    } const auto bins = make_histogram(input);
    show_histogram_svg(bins);
    return 0;
}
