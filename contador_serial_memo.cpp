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
    map<string, int>** bow = new map<string, int>*[num_lecturas];
    map<string, int> mp2(mp1);


    //insertar palabras al diccionario de cada lectura
   for (int i = 0; i<num_palabras;i++){
    my_dictionary_0.insert({palabras[i],0});
   }
   
   map<string, int> my_dictionary_1(my_dictionary_0);
   map<string, int> my_dictionary_2(my_dictionary_0);
   map<string, int> my_dictionary_3(my_dictionary_0);
   map<string, int> my_dictionary_4(my_dictionary_0);
   map<string, int> my_dictionary_5(my_dictionary_0);

    //aumentar conteo de las palabras si existen en la lectura
   for (int j = 0; j<tam_0; j++){
    my_dictionary_0[lectura_0[j]]+=1;
   }

   for (int j = 0; j<tam_1; j++){
    my_dictionary_1[lectura_1[j]]+=1;
   }


   for (auto iterator = my_dictionary_1.begin(); iterator != my_dictionary_1.end(); ++iterator) {
   cout << iterator->first << " " << iterator->second << "\n";
   }
    cout << "nuevo diccionario \n";
   for (auto iterator = my_dictionary_1.begin(); iterator != my_dictionary_1.end(); ++iterator) {
   cout << iterator->first << " " << iterator->second << "\n";
   }
return 0;
}