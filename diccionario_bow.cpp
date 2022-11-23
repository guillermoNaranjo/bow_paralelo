#include <map>
#include <string>
#include <iostream>
using namespace std;
int main (int argc, char *argv[]) {
    map<string, int> my_dictionary_1;
    map<string, int> my_dictionary_2;
    int num_lecturas = 2;
    const int num_palabras = 10;
    int tam_1 = 5;
    int tam_2 = 4;
    string palabras[num_palabras]={"abyss","abyssinia","acause","dimension","diminish","diminished","passive","password","past","paste"};
    string lectura_1[5] = {"patience","patient","patientlie","abyss","abyssinia"};
    string lectura_2[4] = {"dimension","diminish","test","sherlock"};
    string** lecturas = new string*[num_lecturas];
    int tam_lecturas[2] = {tam_1,tam_2};

    //insertar palabras al diccionario de cada lectura
   for (int i = 0; i<num_palabras;i++){
    my_dictionary_1.insert({palabras[i],0});
   }

    //aumentar conteo de las palabras si existen en la lectura
   for (int j = 0; j<tam_1; j++){
    my_dictionary_1[lectura_1[j]]+=1;
   }
   for (auto iterator = my_dictionary_1.begin(); iterator != my_dictionary_1.end(); ++iterator) {
   cout << iterator->first << " " << iterator->second << "\n";
   }
return 0;
}