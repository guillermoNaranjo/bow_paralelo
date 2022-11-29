#include <map>
#include <string>
#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>
#include <mpi.h>

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

    //Lectura del diccionario de palabras 
    map<string, int> words = read_dictionary("diccionario.txt");

    const int num_palabras =  words.size();

    string* lista_palabras = new string[num_palabras];
    
    //Lista de palabras 
    string* palabras = get_word_list(words);

    /////// 

    //Llenado de matriz con diccionarios
    for (int i = 0; i < num_lecturas; i++){
        map<string, int> text = read_count_words(libros[i],words);
        bow[i] = text;
    }



    char host_name[MPI_MAX_PROCESSOR_NAME];
    int name_length = 0;
    int numero_de_enteros;
    int num_procesos = 7;
    int id;
    double time1,time2,duration, global;
    
    
    MPI_Init(&argc, &argv);
    
    MPI_Comm_size(MPI_COMM_WORLD, &num_procesos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    MPI_Get_processor_name(host_name, &name_length);

    double start;
    start = MPI_Wtime();

    /* Si eres el maestro, i.e., el primero proceso que sea crea, entonces*/
    if (id == 0) {
            int mensaje = 13;
            int partner = 1;
            int etiqueta = 101;
            MPI_Status status;
            //MPI_Send(&mensaje, numero_de_enteros, MPI_INT, 1, etiqueta, MPI_COMM_WORLD);
            //MPI_Recv(&mensaje, numero_de_enteros, MPI_INT, 1, etiqueta, MPI_COMM_WORLD, &status);


    }else if(id == 1) {
            MPI_Status status;
            int mensaje = 14;
            int etiqueta = 101;
            //MPI_Send(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD);
            //MPI_Recv(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD, &status);

            //
            map<string, int> temp_dict = read_count_words(libros[id-1], words);
            //save_csv_list(palabras,"arreglo_0.csv",bow,num_lecturas,num_palabras);


    } else if(id == 2) {
            MPI_Status status;
            int mensaje = 14;
            int etiqueta = 101;
            //MPI_Send(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD);
            //MPI_Recv(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD, &status);

            //
            map<string, int> temp_dict = read_count_words(libros[id-1], words);
            //save_csv_list(palabras,"arreglo_1.csv",bow,num_lecturas,num_palabras);


    } else if(id == 3) {
            MPI_Status status;
            int mensaje = 14;
            int etiqueta = 101;
            //MPI_Send(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD);
            //MPI_Recv(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD, &status);

            //
            map<string, int> temp_dict = read_count_words(libros[id-3], words);
            //save_csv_list(palabras,"arreglo_2.csv",bow,num_lecturas,num_palabras);

    } else if(id == 4) {
            MPI_Status status;
            int mensaje = 14;
            int etiqueta = 101;
            //MPI_Send(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD);
            //MPI_Recv(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD, &status);

            //
            map<string, int> temp_dict = read_count_words(libros[id-1], words);
            //save_csv_list(palabras,"arreglo_3.csv",bow,num_lecturas,num_palabras);

    } else if(id == 5) {
            MPI_Status status;
            int mensaje = 14;
            int etiqueta = 101;
            //MPI_Send(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD);
            //MPI_Recv(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD, &status);

            //
            map<string, int> temp_dict = read_count_words(libros[id-1], words);
            //ave_csv_list(palabras,"arreglo_4.csv",bow,num_lecturas,num_palabras);


    } else if(id == 6) {
            MPI_Status status;
            int mensaje = 14;
            int etiqueta = 101;
            //MPI_Send(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD);
            //MPI_Recv(&mensaje, numero_de_enteros, MPI_INT, 0, etiqueta, MPI_COMM_WORLD, &status);
            //
            map<string, int> temp_dict = read_count_words(libros[id-1], words);
            save_csv_list(palabras,"arreglo_paralelo.csv",bow,num_lecturas,num_palabras);
    }
    MPI_Barrier(MPI_COMM_WORLD);

    double end;

    end = MPI_Wtime();

    duration = end - start;
    MPI_Reduce(&duration,&global,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
    MPI_Finalize();

    if (id == 0) cout << " Time: "<< global;
    ///////
    //Guardar csv
    //save_csv_list(palabras,"prueba_arreglo.csv",bow,num_lecturas,num_palabras);

    return 0;
}