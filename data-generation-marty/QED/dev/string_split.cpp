#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& i_str, const string& i_delim)
{
    vector<string> result;
    
    size_t found = i_str.find(i_delim);
    size_t startIndex = 0;

    while(found != string::npos)
    {
        result.push_back(string(i_str.begin()+startIndex, i_str.begin()+found));
        startIndex = found + i_delim.size();
        found = i_str.find(i_delim, startIndex);
    }
    if(startIndex != i_str.size())
        result.push_back(string(i_str.begin()+startIndex, i_str.end()));
    return result;      
}

int main(){
    auto s = "a_b c d_e";
    auto string_split = split(s, "_");
    for (auto &ss : string_split){
        cout << ss << endl;
    }
    return 0;
}

