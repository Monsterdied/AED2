#include <iostream>
#include "Cordenadas.h"
#include "LinhasAereas.h"
#include "Aeroporto.h"

vector<LinhaAerea>ReadAirLinesFile() {
    vector<LinhaAerea> airlines;
    ifstream file("C:\\Users\\Utilizador\\Desktop\\AED\\airlines.csv");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return vector<LinhaAerea>();
    }
    string header;
    getline(file, header);
    string line;
    while (getline(file, line)) {
        vector<string> fields;
        size_t start = 0;
        size_t end = 0;
        while ((end = line.find(',', start)) != string::npos) {
            fields.push_back(line.substr(start, end - start));
            start = end + 1;
        }
        fields.push_back(line.substr(start));

        LinhaAerea airline(fields[0], fields[1], fields[2], fields[3]);
        airlines.push_back(airline);
    }

    return airlines;
}

int main() {

    vector<LinhaAerea> ayo = ReadAirLinesFile();

    for (LinhaAerea a : ayo) {
        cout << a.getNome() << endl;
    }
}