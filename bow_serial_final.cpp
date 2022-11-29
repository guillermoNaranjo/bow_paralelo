#include <map>
#include <string>
#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>

using namespace std;

//Cuenta las palabras de cada obra y las guarda en un diccionario, recibe el diccionario de palabras y el nombre del archivo
map<string, int> read_count_words(string file_name,map<string, int> dict){
    std::ifstream file;
    file.open(file_name);
    while (!file.eof()){
        string word;
        getline(file,word,',');
        dict[word]+=1;
    }
    file.close();
    return dict;
}

//lee el diccionario de palabras dado en un archvio txt
map<string, int> read_dictionary(string file_name){
    map<string, int> dict;
    std::ifstream file;
    file.open(file_name);
    while (!file.eof()){
        string word;
        getline(file,word,',');
        dict.insert({word,0});
    }
    file.close();
    return dict;
}

//recibe el diccionario de palabras y regresa una lista con las palabras del diccionario
string* get_word_list(map<string, int> words){
    int index = 0;
    string* palabras = new string[words.size()];
    for (auto iterator = words.begin(); iterator != words.end(); ++iterator) {
        palabras[index] = iterator->first;
        index++;
    }
    return palabras;
}

//recive la lista de palabras, el arreglo de diccionarios, el numero de lecturas y el numero de palabras. Regresa un csv con la matriz de palabras
void save_csv_list(string* words,string file_name,map<string, int>* bow,int num_lecturas,int num_palabras){
    fstream fout;
    fout.open(file_name, ios::out);
    for (int i = 0; i< num_palabras; i++){
        fout << words[i] << ",";
    }
    fout << "\n";
    for (int i = 0; i < num_lecturas; i++){
        for (int j = 0; j < num_palabras; j++){
            fout << bow[i][words[j]] << ",";
        }
        fout << "\n";
    }
}

int main (int argc, char *argv[]) {
    const int num_lecturas = 6;
    //Nombres de los archivos a leer
    string libros[num_lecturas] = {"shakespeare_the_merchant_of_venice.txt", 
                                   "shakespeare_romeo_juliet.txt", 
                                   "shakespeare_hamlet.txt", 
                                   "dickens_a_christmas_carol.txt", 
                                   "dickens_oliver_twist.txt",
                                   "dickens_a_tale_of_two_cities.txt"};
    //Lista de diccionarios para almacenar resultados
    map<string, int>* bow = new map<string, int>[num_lecturas];
    //Inicializar conteo del tiempo de ejecución
    //Lectura del diccionario de palabras 
    map<string, int> words = read_dictionary("diccionario.txt");

    const int num_palabras =  words.size();

    string* lista_palabras = new string[num_palabras];

    //Lista de palabras 
    string* palabras = get_word_list(words);

    double start = omp_get_wtime();

    //Llenado de matriz con diccionarios
    for (int i = 0; i < num_lecturas; i++){
        map<string, int> text = read_count_words(libros[i],words);
        bow[i] = text;
    }

    //Finalizar conteo del tiempo
    double end = omp_get_wtime();

    cout << " Time: "<< end - start;

    //Guardar csv
    save_csv_list(palabras,"prueba_arreglo.csv",bow,num_lecturas,num_palabras);

    return 0;
}