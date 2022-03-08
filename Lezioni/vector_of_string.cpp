#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    vector<string> vector_of_strings;
    string s;
    while (getline(cin, s) && s != "end")
        vector_of_strings.push_back(s);
    sort(vector_of_strings.begin(), vector_of_strings.end());

    vector<string>::const_iterator pos=
        unique(vector_of_strings.begin(), vector_of_strings.end());

    vector_of_strings.erase(pos, vector_of_strings.end());

    copy(vector_of_strings.begin(), vector_of_strings.end(), ostream_iterator<string> (cout, "\t"));
}