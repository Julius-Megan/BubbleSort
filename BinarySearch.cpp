// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Trabahador.h"



vector<Trabahador*> employees;
int indexCount;
int h;

int binarySearch(int x, int high) {
    int low = 0;
    while (low < high) {
        indexCount++;
        int mid = (low + high) / 2;
        if (x <= employees[mid]->getID()) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return high;
}

//Most inefficient way to sort.
void bubbleSort() {
    //variable to count the number of comparisons
    int counter = 0;

    //start from first to length -2
    for (auto i = 0; i <= (h - 2); i++) {
        //start from length -1 to the current i + 1
        for (int j = h - 1; j >= i + 1; j--) {
            counter++;
            if (employees[j]->getID() < employees[j - 1]->getID()) {
                //a funtion to swap elements in an array
                swap(employees[j], employees[j - 1]);
                //We print the id number and see bubble sorting effect.
                /*for (auto e : employees) {
                    cout << e->getID();
                }
                cout << " " << endl;*/
            }
        }
    }
    cout << "It took " << counter << " comparisons to sort this list." << endl;
}



int main(int argc, char** argv)
{
    //We send a warning if they forget to input the filename
    if (argc == 1) {
        cout << "You forgot the commandline parameter\n";
        exit(0);
    }

    //This is how we read the file. By putting the filename in the commandline argument.
    //An error message is also sent, just in case the file location is incorrect.
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not locate file" << argv[1] << endl;
        exit(0);
    }

    //We create a vector/arraylist of my object
    /*vector<Trabahador*> employees;*/

    //We read the first line and save that to a variable
    string line1;
    getline(ifs, line1);
    int n = stoi(line1);


    //This will loop depending on the number of lines in each file
    for (auto i = 0; i < n; i++) {
        string word[4];
        string y;

        //Loop through all the line and save it to my array of strings.
        for (int x = 0; x < 4; x++) {
            getline(ifs, word[x], '|');
        }
        getline(ifs, y);


        //Get all those element from the array and create a variable
        string name = word[0];
        int id = stoi(word[1]);
        int age = stoi(word[2]);
        string job = word[3];
        int year = stoi(y);

        //Initialize the new object and add it to our vector
        Trabahador* t = new Trabahador(name, id, age, job, year);
        employees.push_back(t);
    }

    h = employees.size();
    bubbleSort();




}


