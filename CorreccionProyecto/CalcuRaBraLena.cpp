#include <iostream>
#include "Savest.h"
#include <string>
#include <vector>

using namespace std;

float DineroTotal = 0;
char decision = 'Y';
vector<double> envelopes;
int iter = 0;
int numFund = 0;
void Investments(char decision, float &DineroTotal, int numFund);
void Savings(char decision, float &DineroTotal, int numFund);
void LlenarSobre();
int Interconectividad();
void IngresarUsuario();


int main() {
    cout << "Welcome to the RaBraLena finances app" << endl;
    cout << "Please enter the total money you have" << endl;
    cin >> DineroTotal;

    cout << "Do you want to create a new envelope? (Y for yes, N for no)" << endl;
    cout << "You currently have " << envelopes.size() << " envelopes\n";
    cin >> decision;
    if (decision == 'Y'){
        LlenarSobre();
    }
    if (decision == 'N'){
        Investments(decision, DineroTotal, numFund);
    }

    Savings(decision, DineroTotal, numFund);

    Interconectividad();

    return 0;
}

//esta función llena los sobres, que corresponden a los gastos del usuario
void LlenarSobre(){
    vector<string> enve_names;
    char decision;
    string a;
    double b;

    cout << "Enter the name of your envelope\n";
    cin >> a;
    enve_names.push_back(a);
    cout << "Enter the total sum you want to add to this envelope\n";
    cin >> b;
    envelopes.push_back(b);
    DineroTotal -= envelopes[iter];

    cout << "Do you want to create a new envelope? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y' && DineroTotal > envelopes[iter]){
        iter++;
        LlenarSobre();
    }
    else if (DineroTotal < envelopes[iter]){
        cout << "Sorry, for the moment you do not have enough money\n";
    }

    if (decision == 'N'){
        Investments(decision, DineroTotal, numFund);
    }
}

int Interconectividad(){
    cout << "Do you need anything more?\nUser settings (1)\tInvestments(2)\tSavings(3)";
    cin >> decision;
    switch (decision) {
        case 1:
            IngresarUsuario();
            break;
            case 2:
                Investments(decision, DineroTotal, numFund);
                break;
                case 3:
                    Savings(decision, DineroTotal, numFund);
                    break;
                    default:
                        break;
    }
    return 0;
}

void IngresarUsuario(){
    /* Fecha Hoy;
    */

}





