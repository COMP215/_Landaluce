#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void find_all_subsequences(string str, vector<string>& subsequences);
void print_vector(vector<string>& vect);

int main()
{
    string str = "abcd";
    vector<string> subsequences;
    find_all_subsequences(str,subsequences);
    print_vector(subsequences);


    return 0;
}

void find_all_subsequences(string str, vector<string>& subsequences) {
    subsequences.push_back("");
    int current_size = subsequences.size();
    for(int i = 0;i < str.size();i++) {
        for(int j = 0;j < current_size;j++) {
            subsequences.push_back(subsequences[j] + str.substr(i,1));
        }
        current_size = subsequences.size();
    }
}

void print_vector(vector<string>& vect){
    cout << "[";
    for (vector<string>::const_iterator i = vect.begin(); i != vect.end(); ++i) {
        cout << *i << "] [";
    }
    cout << "Count: " << vect.size();
}
