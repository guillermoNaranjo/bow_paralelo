#include <map>
#include <string>
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    map<string, int> my_dictionary;
    my_dictionary.insert({"computo", 100});
    my_dictionary.insert({"paralelo", 200});
    my_dictionary.insert({"curso", 300});
    //my_dictionary.at("paralelo") = 3;
    my_dictionary["paralelo"] = 4;
    cout << my_dictionary.at("paralelo") << "\n";
    cout << my_dictionary.at("computo") << "\n";
    cout << my_dictionary["paralelo"] << "\n";
    cout << my_dictionary.count("inexistente") << "\n";
    cout << my_dictionary.count("paralelo") << "\n";
    my_dictionary.erase("curso");
    for (auto iterator = my_dictionary.begin(); iterator != my_dictionary.end(); ++iterator) {
        cout << iterator->first << " " << iterator->second << "\n";
    }
    return 0;
}