#include <map>
#include <string>
#include <iostream>
#include <omp.h>
using namespace std;

void count_words(map<string, int>* bow,int* tam_lecturas,int num_lecturas,string** lecturas){
    for (int i = 0; i<num_lecturas;i++){
        for (int j = 0; j<tam_lecturas[i];j++){
            bow[i][lecturas[i][j]]+=1;
        }
    }
}

map<string, int> fill_dictionary(int bow_size, string* bow){
    map<string, int> dict;
    for (int i = 0; i<bow_size;i++){
        dict.insert({bow[i],0});
    }
    return dict;
}

void print_dictionary(map<string, int>* bow,int num_lecturas){
    for (int i = 0; i<num_lecturas;i++){
        for (auto iterator = bow[i].begin(); iterator != bow[i].end(); ++iterator) {
            cout << iterator->first << " " << iterator->second << ",";
        }
        cout << endl;
    }
}

void print_dictionary_num(map<string, int>* bow,int num_lecturas){
    for (int i = 0; i<num_lecturas;i++){
        for (auto iterator = bow[i].begin(); iterator != bow[i].end(); ++iterator) {
            cout << iterator->second << ",";
        }
        cout << endl;
    }
}

int main (int argc, char *argv[]) {
    //variables de la forma _# son correspondientes a cada lectura
    const int num_lecturas = 6;
    const int num_palabras = 30;
    map<string, int> my_dictionary_0;  
    int tam_0 = 10;
    int tam_1 = 10;
    int tam_2 = 10;
    int tam_3 = 10;
    int tam_4 = 5;
    int tam_5 = 7;
    int tam_lecturas[num_lecturas] = {tam_0,tam_1,tam_2,tam_3,tam_4,tam_5}; //arreglo con los tamaños de las lecturas
    string palabras[num_palabras]={"astonish"," astonished","astonishment","astound","astounded","astounding","astray","asunder","asylum","atheistical",
                                   "athirst","athwart","atmosphere","atmospheric","atom","atomic","atomie","atonement","atones","atop",
                                   "atrocious","atrociously","atrocity","attach","attachment","attack","attain","attainable","attainment","attempt"};
    string** lecturas = new string*[num_lecturas];
    //Leer los libros correspondientes
    string lectura_0[tam_0] = {"astonish","astonish","astonishment","astound","astounded","astounding","astray","asunder","asylum","atheistical"};
    string lectura_1[tam_1] = {"athirst","athwart","atmosphere","atmospheric","atom","atomic","atomie","atonement","atones","atop"};
    string lectura_2[tam_2] = {"atrocious","atrociously","atrocity","attach","attachment","attack","attain","attainable","attainment","attempt"};
    string lectura_3[tam_3] = {"atrocious","atrociously","atrocity","attach","attachment","atrocious","atrociously","atrocity","attach","attachment"};
    string lectura_4[tam_4] = {"athirst","athwart","atmosphere","atmospheric","atom"};
    string lectura_5[tam_5] = {"astonish","astonish"," astonished","astonishment","astonish"," astonished","astonishment"};
    map<string, int>* bow = new map<string, int>[num_lecturas];
    lecturas[0] = lectura_0;
    lecturas[1] = lectura_1;
    lecturas[2] = lectura_2;
    lecturas[3] = lectura_3;
    lecturas[4] = lectura_4;
    lecturas[5] = lectura_5;

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

    print_dictionary_num(bow,num_lecturas);

    double end = omp_get_wtime();

    cout << "Time: " << end - start << "\n";

    return 0;
}