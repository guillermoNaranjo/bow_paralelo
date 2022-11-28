#include <map>
#include <string>
#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>

using namespace std;

//Cuenta las palabras de cada obra y las guarda en un diccionario
void count_words(map<string, int>* bow,int* tam_lecturas,int num_lecturas,string** lecturas){
    for (int i = 0; i<num_lecturas;i++){
        for (int j = 0; j<tam_lecturas[i];j++){
            bow[i][lecturas[i][j]]+=1;
        }
    }
}

//Crea un diccionario que contiene todas las palabras de las obras
map<string, int> fill_dictionary(int bow_size, string* bow){
    map<string, int> dict;
    for (int i = 0; i<bow_size;i++){
        dict.insert({bow[i],0});
    }
    return dict;
}

//Imprime diccionario (solo para pruebas)
void print_dictionary(map<string, int>* bow,int num_lecturas){
    for (int i = 0; i<num_lecturas;i++){
        for (auto iterator = bow[i].begin(); iterator != bow[i].end(); ++iterator) {
            cout << iterator->first << " " << iterator->second << ",";
        }
        cout << endl;
    }
}

//Imprimer valores almacenados en diccionario (solo para pruebas)
void print_dictionary_num(map<string, int>* bow,int num_lecturas){
    for (int i = 0; i<num_lecturas;i++){
        for (auto iterator = bow[i].begin(); iterator != bow[i].end(); ++iterator) {
            cout << iterator->second << ",";
        }
        cout << endl;
    }
}

//Transfiere los datos de los diccionarios a una matriz para obtener los resultados
void dict_to_array(map<string, int>* bow,int num_lecturas,int** results,int num_palabras){
    for (int i=0; i < num_lecturas; i++){
        int index = 0;
        for (auto iterator = bow[i].begin(); iterator != bow[i].end(); ++iterator) {
            results[i][index] = iterator->second;
            index++;
        }   
    }
}

void print_array(int** results, int num_palabras, int num_lecturas){
    cout << "printng results ..." << "\n";
    for (int i = 0; i < num_lecturas; i++){
        for (int j = 0; j < num_palabras; j++){
            cout << results[i][j] << " ";
        }
        cout << "\n";
    }
}

void save_to_CSV(string file_name, int** results,int palabras,int num_lecturas) {
    fstream fout;
    fout.open(file_name, ios::out);
    for (int i = 0; i<num_lecturas; i++){
        for (int j = 0; j < palabras; j++){
            fout << results[i][j] << ",";
        }
        fout << "\n";
    }
}

void readDictionary(std::string* arr, std::string fileName, long long int size){

    std::ifstream file;
    std::string line;
    long long int i=0;

    file.open(fileName.c_str());

    if (file.is_open()){
        while(i<size){
            getline(file, line);
            line.pop_back();
            arr[i] = line;
            //std::cout << line << std::endl;
            i++;
        }
        file.close();
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
    return ret.data();
}

int main (int argc, char *argv[]) {
    //variables de la forma _# son correspondientes a cada lectura
    const int num_lecturas = 6;
    const int num_palabras =  15164;
    map<string, int> my_dictionary_0;  
    int tam_0 = 10;
    int tam_1 = 10;
    int tam_2 = 10;
    int tam_3 = 10;
    int tam_4 = 5;
    int tam_5 = 7;
    string libros[num_lecturas] = {"shakespeare_the_merchant_of_venice.txt","shakespeare_romeo_juliet.txt",
                                   "shakespeare_hamlet.txt","dickens_oliver_twist.txt","dickens_a_tale_of_two_cities.txt","dickens_a_christmas_carol.txt"};
    int tam_lecturas[num_lecturas] = {tam_0,tam_1,tam_2,tam_3,tam_4,tam_5}; //arreglo con los tamaños de las lecturas
    string* palabras = new string[num_palabras];
    readDictionary(palabras,"diccionario.txt",num_palabras);
    string** lecturas = new string*[num_lecturas];

    /* lectura de obras completas y guardar en arreglo
    for (int i = 0; i < num_lecturas; i++){
        string* libro = readText(libros[i]);
        lecturas[i] = libro;
    }
    */
    //Leer los libros correspondientes
    string lectura_0[tam_0] = {"astonish","astonish","astonishment","astound","astounded","astounding","astray","asunder","asylum","atheistical"};
    string lectura_1[tam_1] = {"athirst","athwart","atmosphere","atmospheric","atom","atomic","atomie","atonement","atones","atop"};
    string lectura_2[tam_2] = {"atrocious","atrociously","atrocity","attach","attachment","attack","attain","attainable","attainment","attempt"};
    string lectura_3[tam_3] = {"atrocious","atrociously","atrocity","attach","attachment","atrocious","atrociously","atrocity","attach","attachment"};
    string lectura_4[tam_4] = {"athirst","athwart","atmosphere","atmospheric","atom"};
    string lectura_5[tam_5] = {"astonish","astonish"," astonished","astonishment","astonish"," astonished","astonishment"};
    lecturas[0] = lectura_0;
    lecturas[1] = lectura_1;
    lecturas[2] = lectura_2;
    lecturas[3] = lectura_3;
    lecturas[4] = lectura_4;
    lecturas[5] = lectura_5;

    map<string, int>* bow = new map<string, int>[num_lecturas];

    cout << lecturas[2][2];

    int** results = new int*[num_lecturas];
    
    for (int i=0; i<num_lecturas; i++){
        results[i] = new int[num_palabras];
    }

    double start = omp_get_wtime();

    my_dictionary_0 = fill_dictionary(num_palabras,palabras);
   
    map<string, int> my_dictionary_1(my_dictionary_0);
    map<string, int> my_dictionary_2(my_dictionary_0);
    map<string, int> my_dictionary_3(my_dictionary_0);
    map<string, int> my_dictionary_4(my_dictionary_0);
    map<string, int> my_dictionary_5(my_dictionary_0);

    bow[0] = my_dictionary_0;
    bow[1] = my_dictionary_1;
    bow[2] = my_dictionary_2;
    bow[3] = my_dictionary_3;
    bow[4] = my_dictionary_4;
    bow[5] = my_dictionary_5;

    count_words(bow,tam_lecturas,num_lecturas,lecturas);

    //print_dictionary_num(bow,num_lecturas);

    dict_to_array(bow,num_lecturas,results,num_palabras);

    //print_array(results,num_palabras,num_lecturas);

    double end = omp_get_wtime();

    cout << "Time: " << end - start << "\n";

    save_to_CSV("bow_test.csv",results,num_palabras,num_lecturas);

    for (int i=0; i<num_lecturas;i++){
        cout << "deleting matrix ... ";
        delete[] results[i];
    }
    return 0;
}