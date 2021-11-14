//
// Created by elena on 13/11/2021.
//

#ifndef PROYECTO2_SAVEST_H
#define PROYECTO2_SAVEST_H
#include <string>

using namespace std;

class Savest {
private:
    string nameFund;
    float valueFund;

public:
    //Constructores
    Savest();
    Savest(string _name, float _value);

    //Funciones
    void show();
    float getAmount();
    Savest dataSavings(int i);
    Savest dataInvestments(int i);
};


#endif //PROYECTO2_SAVEST_H
