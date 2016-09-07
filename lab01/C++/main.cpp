#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>
#include <set>
#include <chrono>

using namespace std;

void   randomStringsGenerator(string filename, long nOfStrings, long stringLengthBound);
string stringsSorter(string filename);
void program3(long stringLengthBound, long nOfStrings);

int main()
{
    long stringLengthBound = 3;
    //long nOfStrings = 1000000;
    for(long i = 1000000; i < 20000000; i += 1000000)
    {
        program3(stringLengthBound,i);
    }
    return 0;
}

void randomStringsGenerator(string filename, long nOfStrings, long stringLengthBound)
{
    string strings = "";
    string aString;
    for(long x = 0;x < nOfStrings;x++)
    {
        aString     = "";
        long length = 1 + rand() % stringLengthBound;

        for(long i = 0;i < length;i++)
        {
            aString += (char) (97 + rand() % 26);
        }
        strings += aString + "\n";
    }

    ofstream fout(filename.c_str());
    fout << strings;
    fout.close();
}

string stringsSorter(string filename)
{
    ifstream fin(filename.c_str());
    multiset <string> strings;
    string   content = "";

    if(fin.is_open())
    {
        string aString = "";

        while(!fin.eof())
        {
            fin >> aString;
            strings.insert(aString);
        }
        for (multiset<string>::const_iterator i(strings.begin()), end(strings.end());i != end;++i)
        {
            content += *i + "\n";
        }
        fin.close();
    }
    else
    {
        cout << "File " << filename << " could not be opened" << endl;
    }
    return content;
}

void program3(long stringLengthBound, long nOfStrings)
{
    const short  STRING_COLLECTIONS = 3;
    //long         stringLengthBound  = 3;
    //long         nOfStrings         = 12000000;
    string       filename           = "stringCollection";
    string       content[STRING_COLLECTIONS];
    string       fullFilename;
    string       fileNumber;
    stringstream out;

    srand((unsigned)time(NULL));
    cout << "0/" << STRING_COLLECTIONS << " completed" << endl;

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    for(short i = 0;i < STRING_COLLECTIONS;i++)
    {
        out << i;
        fullFilename = filename + out.str() + ".txt";
        out.str("");
        randomStringsGenerator(fullFilename, nOfStrings, stringLengthBound);
        content[i]   = stringsSorter(fullFilename);
        //system("CLS");
        cout << i + 1 << "/" << STRING_COLLECTIONS << " completed" << endl;
    }
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration<double>(t2 - t1);
    cout << "number of strings: " << nOfStrings;
    cout << " time: " << time_span.count() << endl;
}
