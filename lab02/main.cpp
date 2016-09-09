#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>
#include <set>
#include <chrono>

using namespace std;

void   RandomStringsGenerator(string file_name, long number_of_strings, long string_length_upper_bound);
string StringsSorter(string file_name);
void Test(long string_length_upper_bound, long number_of_strings);

int main()
{
    long string_length_upper_bound = 3;
    //long number_of_strings = 1000000;
    for(long i = 1000000; i < 20000000; i += 1000000)
    {
        Test(string_length_upper_bound,i);
    }
    return 0;
}

void RandomStringsGenerator(string file_name, long number_of_strings, long string_length_upper_bound)
{
    string strings = "";
    string a_string;
    for(long x = 0;x < number_of_strings;x++)
    {
        a_string     = "";
        long length = 1 + rand() % string_length_upper_bound;

        for(long i = 0;i < length;i++)
        {
            a_string += (char) (97 + rand() % 26);
        }
        strings += a_string + "\n";
    }

    ofstream fout(file_name.c_str());
    fout << strings;
    fout.close();
}

string StringsSorter(string file_name)
{
    ifstream fin(file_name.c_str());
    multiset <string> strings;
    string   content = "";

    if(fin.is_open())
    {
        string a_string = "";

        while(!fin.eof())
        {
            fin >> a_string;
            strings.insert(a_string);
        }
        for (multiset<string>::const_iterator i(strings.begin()), end(strings.end());i != end;++i)
        {
            content += *i + "\n";
        }
        fin.close();
    }
    else
    {
        cout << "File " << file_name << " could not be opened" << endl;
    }
    return content;
}

void Test(long string_length_upper_bound, long number_of_strings)
{
    const short  StringCollections = 3;
    //long         string_length_upper_bound  = 3;
    //long         number_of_strings         = 12000000;
    string       file_name           = "stringCollection";
    string       content[StringCollections];
    string       full_file_name;
    string       file_number;
    stringstream out;

    srand((unsigned)time(NULL));
    cout << "0/" << StringCollections << " completed" << endl;

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    for(short i = 0;i < StringCollections;i++)
    {
        out << i;
        full_file_name = file_name + out.str() + ".txt";
        out.str("");
        RandomStringsGenerator(full_file_name, number_of_strings, string_length_upper_bound);
        content[i]   = StringsSorter(full_file_name);
        //system("CLS");
        cout << i + 1 << "/" << StringCollections << " completed" << endl;
    }
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration<double>(t2 - t1);
    cout << "number of strings: " << number_of_strings;
    cout << " time: " << time_span.count() << endl;
}
