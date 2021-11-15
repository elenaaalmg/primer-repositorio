//
// Created by elena on 13/11/2021.
//

#include <iostream>
#include "Savest.h"
#include <string>
#include <vector>
using namespace std;

void Savings(char decision, float &DineroTotal, int numFund);
int Interconectividad();

// inicialización de constructores
Savest::Savest() {
    nameFund = " ";
    valueFund = 0;

}
Savest::Savest(string _name, float _value) {
    nameFund = _name;
    valueFund = _value;
}


// esta función muestra los fondos que tiene el usuario
void Savest::show() {
    cout << nameFund << ": $ " << valueFund << endl;
}


// con esta función se obtiene el valor del fondo y sirve para restar éste al dinero total ingresado al inicio
float Savest::getAmount() {
    return valueFund;
}


// esta función regresa a un constrcutor de un fondo de inversión, dicho constructor contiene el nombre del fondo y su respectivo valor
Savest Savest::dataInvestments(int i) {
    cout << "Type the name of the fund " << i << ": ";
    cin >> nameFund;
    cout << "Enter the fund value " << nameFund << ": ";
    cin >> valueFund;
    Savest myInvestmentsFund(nameFund, valueFund);
    return myInvestmentsFund;
}

// Esta función almacena en un arreglo los constructores de inversión
void Investments(char decision, float &DineroTotal, int numFund){
    Savest I;
    cout << "Do you want to invest? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << DineroTotal << " to invest\n";
        cout << "How many funds do you want to have? You can insert up to 7 investment funds.\n";
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = I.dataInvestments(i);
            DineroTotal -= I.getAmount();
        }

        cout << "Your investments funds are\n";
        for(int i = 0; i < numFund; i++){
            funds[i].show();
        }
    }
    if (decision == 'N'){
        Savings(decision, DineroTotal, numFund);
    }
}


// esta función regresa a un constructor de un fondo de ahorro, dicho constructor contiene el nombre del fondo y su respectivo valor
Savest Savest::dataSavings(int i) {
    cout << "Type the name of the fund " << i << ": ";
    cin >> nameFund;
    cout << "Enter the fund value " << nameFund << ": ";
    cin >> valueFund;
    Savest mySavingFund(nameFund, valueFund);
    return mySavingFund;
}

// Esta función almacena en un arreglo los constructores de ahorro
void Savings(char decision, float &DineroTotal, int numFund){
    Savest S;
    cout << "Do you want to save? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << DineroTotal << " to saving\n";
        cout << "How many funds do you want to have? You can insert up to 5 savings funds.\n";
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = S.dataSavings(i);
            DineroTotal -= S.getAmount();
        }

        cout << "Your savings funds are\n";
        for(int i = 0; i < numFund; i++){
            funds[i].show();
        }
    }

    if (decision == 'N'){
        int Interconectividad();
    }
}

