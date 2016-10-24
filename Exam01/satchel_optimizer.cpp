#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Mushroom{
    public:
        string common_name_;
        string scientific_name_;
        int quantity_;
        int total_value_;
        double individual_value_;
        void Print();

};
class Satchel{
    public:
        int size_;
        int number_of_maitake_;
        int number_of_shiitake_;
        int number_of_oyster_;
        int number_of_shaggy_mane_;
};
void Mushroom::Print(){
    cout << common_name_ << " " <<
            scientific_name_ << " " <<
            quantity_ << " " <<
            total_value_ << " " <<
            individual_value_ << " " << endl;
}
void getMushrooms(string filename, int satchel_size);
int main()
{
    getMushrooms("mushrooms_1.csv",28);
    getMushrooms("mushrooms_2.csv",60);
    getMushrooms("mushrooms_3.csv",500);
    return 0;
}
void getMushrooms(string filename, int satchel_size) {
    string line;
    ifstream file (filename.c_str());
    Mushroom mushrooms[4];
    int iter = 0;
    getline(file, line);
    int individual_values[4];
    int index[4] = {0,1,2,3};
    while (getline(file, mushrooms[iter].common_name_, ',')) {
        getline(file, mushrooms[iter].scientific_name_, ',') ;
        getline(file, line, ',') ;
        mushrooms[iter].quantity_ = atoi(line.c_str());
        getline(file, line);
        mushrooms[iter].total_value_ = atoi(line.c_str());
        mushrooms[iter].individual_value_ = (double)mushrooms[iter].total_value_ / mushrooms[iter].quantity_;
        individual_values[iter] = mushrooms[iter].individual_value_;
        iter++;
    }
    int temp;
    int temp2;
    for(int iter1 = 0;iter1 < 4;iter1++){
        for(int iter2 = 0;iter2 < 4;iter2++) {
            if(individual_values[iter1] > individual_values[iter2]) {
                temp = individual_values[iter1];
                temp2 = index[iter1];
                individual_values[iter1] = individual_values[iter2];
                index[iter1] = index[iter2];
                individual_values[iter2] = temp;
                index[iter2] = temp2;
            }
        }
    }
    Satchel satchel;
    satchel.size_ = satchel_size;
    satchel.number_of_maitake_ = 0;
    satchel.number_of_oyster_ = 0;
    satchel.number_of_shaggy_mane_ = 0;
    satchel.number_of_shiitake_ = 0;
    int iter1 = 0;
    while(iter1 < 4 || satchel.size_ > 0) {
        while(mushrooms[index[iter1]].quantity_ > 0 && satchel.size_ > 0){
            if(mushrooms[index[iter1]].common_name_ == "\tmaitake") {
                satchel.number_of_maitake_++;
            } else if(mushrooms[index[iter1]].common_name_ == "\toyster") {
                satchel.number_of_oyster_++;
            } else if(mushrooms[index[iter1]].common_name_ == "\tshaggy mane") {
                satchel.number_of_shaggy_mane_++;
            } else {
                satchel.number_of_shiitake_++;
            }
            satchel.size_--;
            mushrooms[index[iter1]].quantity_--;
        }
        iter1++;
    }
    cout << satchel.number_of_maitake_ << " ounces of Maitake (Grifola frondosa) mushrooms"<< endl;
    cout << satchel.number_of_oyster_ << " ounces of Oyster (Pleuratus ostreatus) mushrooms" << endl;
    cout << satchel.number_of_shaggy_mane_ << " ounces of Shaggy Mane (Coprinus comatus) mushrooms" << endl;
    cout << satchel.number_of_shiitake_ << " ounces of Shiitake (Lentinula edodes) mushrooms" << endl << endl;
}
