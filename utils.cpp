#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void readDictionary(std::string* arr, std::string fileName, long long int size){

    arr = new std::string[size];
    std::ifstream file;
    std::string line;
    long long int i=0;

    file.open(fileName.c_str());

    if (file.is_open()){
        while(i<size){
            getline(file, line);
            line.pop_back();
            arr[i] = line;
            std::cout << line << std::endl;
            i++;
        }
        file.close();

    }
}


std::string* readText(std::string fileName, long long int size = 20000){

    std::vector<std::string> ret;
    std::ifstream file;
    std::string line;

    long long int i = 0;
    std::string* arr = new std::string[size];

    file.open(fileName.c_str());

    if (file.is_open()){
        
        while(!file.eof()){
            std::string temp;
            char letter;
            file>>letter;

            while(letter != ',' && !file.eof()){
                temp.push_back(letter);
                file>>letter;
            }

           arr[i] = temp;
           i++;
        }
        file.close();

        return arr;
        
    }
}
