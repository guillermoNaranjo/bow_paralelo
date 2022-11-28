#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string* readDictionary(std::string fileName){

    std::vector<std::string> ret;
    std::ifstream file;
    std::string line;
    long long int i=0;

    file.open(fileName.c_str());

    if (file.is_open()){
        while(!file.eof()){
            getline(file, line);
            line.pop_back();
            ret.push_back(line);
        }
        file.close();

        return ret.data();
    }
}

std::string* readText(std::string fileName){

    std::vector<std::string> ret;
    std::ifstream file;
    std::string line;
    long long int i=0;

    file.open(fileName.c_str());

    if (file.is_open()){
        
        while(!file.eof()){
            std::string temp;
            char letter;
            file>>letter;

            while(letter != ','){
                temp.push_back(letter);
                file>>letter;
            }

           ret.push_back(temp); 
        }
        file.close();

        return ret.data();
    }
}
