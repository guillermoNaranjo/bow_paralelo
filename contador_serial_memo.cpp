#include <map>
#include <string>
#include <iostream>
using namespace std;
int main (int argc, char *argv[]) {
    //variables de la forma _# son correspondientes a cada lectura
    const int num_lecturas = 6;
    const int num_palabras = 10;
    map<string, int> my_dictionary_0;
    /*
    map<string, int> my_dictionary_1;
    map<string, int> my_dictionary_2;
    map<string, int> my_dictionary_3;
    map<string, int> my_dictionary_4;
    map<string, int> my_dictionary_5;
    */
   
    int tam_0 = 5;
    int tam_1 = 4;
    int tam_2 = 5;
    int tam_3 = 4;
    int tam_4 = 5;
    int tam_5 = 4;
    int tam_lecturas[num_lecturas] = {tam_0,tam_1,tam_2,tam_3,tam_4,tam_5}; //arreglo con los tamaños de las lecturas
    string palabras[num_palabras]={"abyss","abyssinia","acause","dimension","diminish","diminished","passive","password","past","paste"};
    string** lecturas = new string*[num_lecturas];
    string lectura_0[5] = {"patience","patient","patientlie","abyss","abyssinia"};
    string lectura_1[4] = {"dimension","diminish","test","sherlock"};
    string lectura_2[5] = {"patience","patient","patientlie","abyss","abyssinia"};
    string lectura_3[4] = {"dimension","diminish","test","sherlock"};
    string lectura_4[5] = {"patience","patient","patientlie","abyss","abyssinia"};
    string lectura_5[4] = {"dimension","diminish","test","sherlock"};
    map<string, int>* bow = new map<string, int>[num_lecturas];
    lecturas[0] = lectura_0;
    lecturas[1] = lectura_1;
    lecturas[2] = lectura_2;
    lecturas[3] = lectura_3;
    lecturas[4] = lectura_4;
    lecturas[5] = lectura_5;
    //insertar palabras al diccionario de cada lectura
   for (int i = 0; i<num_palabras;i++){
    my_dictionary_0.insert({palabras[i],0});
   }
   
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
    //map<string, int>* BOW[num_lecturas] = {}

    for (int i = 0; i<num_lecturas;i++){
        for (int j = 0; j<tam_lecturas[i];j++){
            bow[i][lecturas[i][j]]+=1;
        }
    }

    //aumentar conteo de las palabras si existen en la lectura

   for (auto iterator = my_dictionary_0.begin(); iterator != my_dictionary_0.end(); ++iterator) {
   cout << iterator->first << " " << iterator->second << "\n";
   }
   cout << "nuevo diccionario \n";
   for (auto iterator = my_dictionary_1.begin(); iterator != my_dictionary_1.end(); ++iterator) {
   cout << iterator->first << " " << iterator->second << "\n";
   }
return 0;
}