#include <map>
#include <string>
#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>

using namespace std;

//Cuenta las palabras de cada obra y las guarda en un diccionario

map<string, int> read_count_words(string file_name,map<string, int> dict){
    std::ifstream file;
    file.open(file_name);
    while (!file.eof()){
        string word;
        getline(file,word,',');
        //cout << word << "\n";
        dict[word]+=1;
    }
    file.close();
    return dict;
}

map<string, int> read_dictionary(string file_name){
    map<string, int> dict;
    std::ifstream file;
    file.open(file_name);
    while (!file.eof()){
        string word;
        getline(file,word,',');
        //cout << word << "\n";
        dict.insert({word,0});
    }
    file.close();
    return dict;
}

void save_to_CSV_dict(string file_name,map<string, int>* bow,int num_lecturas) {
    fstream fout;
    fout.open(file_name, ios::out);
    for (int i = 0; i<num_lecturas; i++){
        for (auto iterator = bow[i].begin(); iterator != bow[i].end(); ++iterator) {
            fout << iterator->second << ",";
        }
        fout << "\n";
    }
}

void save_to_CSV_arr(string file_name,map<string, int>* bow,int num_lecturas) {
    fstream fout;
    fout.open(file_name, ios::out);
    for (auto iterator = bow[1].begin(); iterator != bow[1].end(); ++iterator) {
            fout << iterator->first << ",";
        }
    for (int i = 0; i<num_lecturas; i++){
        fout << "\n";
        for (auto iterator = bow[i].begin(); iterator != bow[i].end(); ++iterator) {
            fout << int(iterator->second) << ",";
        }
    }
}

string* get_word_list(map<string, int> words){
    int index = 0;
    string* palabras = new string[words.size()];
    for (auto iterator = words.begin(); iterator != words.end(); ++iterator) {
        palabras[index] = iterator->first;
        index++;
    }
    return palabras;
}

void save_csv_list(string* words,string file_name,map<string, int>* bow,int num_lecturas,int num_palabras){
    fstream fout;
    fout.open(file_name, ios::out);
    for (int i = 0; i < num_lecturas; i++){
        for (int j = 0; j < num_palabras; j++){
            //cout << bow[i][words[j]];
            fout << bow[i][words[j]] << ",";
        }
        fout << "\n";
    }
}



int main (int argc, char *argv[]) {
    //variables de la forma _# son correspondientes a cada lectura
    const int num_lecturas = 6;
    const int num_palabras =  15165;
    string libros[num_lecturas] = {"shakespeare_the_merchant_of_venice.txt", 
                                   "shakespeare_romeo_juliet.txt", 
                                   "shakespeare_hamlet.txt", 
                                   "dickens_a_christmas_carol.txt", 
                                   "dickens_oliver_twist.txt",
                                   "dickens_a_tale_of_two_cities.txt"};
    map<string, int>* bow = new map<string, int>[num_lecturas];

    int** results = new int*[num_lecturas];

    map<string, int> words = read_dictionary("diccionario.txt");

    string* palabras = get_word_list(words);

    cout << "palabras: " << palabras[0] << " " << palabras[1] << palabras[2] << " " << palabras[3] << palabras[100] << " " << palabras[300] << palabras[500] << " " << palabras[900];

    cout << "Tamaño diccionario: " << words.size() << "\n";

    for (int i = 0; i < num_lecturas; i++){
        map<string, int> text = read_count_words(libros[i],words);
        cout << text["youth"] << "\n";
        bow[i] = text;
        cout << bow[i]["youth"] << "\n";
        cout << "Book: " << i << " done \n";
    }

    cout << bow[0]["youth"] << "\n";
    cout << bow[1]["youth"] << "\n";
    cout << bow[2]["youth"] << "\n";
    cout << bow[3]["youth"] << "\n";
    cout << bow[4]["youth"] << "\n";
    cout << bow[5]["youth"] << "\n";
    
    for (int i = 250; i < 300; i++){
        if("abruptly" == palabras[i]){
            cout << "abrupt es igual";
        }
        cout << bow[3][palabras[i]] << "," << palabras[i] << "\n";
    }

    //save_to_CSV_arr("a_test.csv",bow,num_lecturas);

    //save_to_CSV_dict("b_test.csv",bow,num_lecturas);

    save_csv_list(palabras,"prueba_arreglo.csv",bow,num_lecturas,num_palabras);

    return 0;
}