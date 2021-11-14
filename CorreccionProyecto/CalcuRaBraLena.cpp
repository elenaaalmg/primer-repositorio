#include <iostream>
#include "Savest.h"
#include <string>
#include <vector>

using namespace std;
double DineroTotal = 0;
char decision = 'Y';
vector<double> envelopes;
int iter = 0;
int numFund = 0;
void Savings();
void Investments();
void LlenarSobre();
int finishProgram();

int main() {
    cout << "Welcome to the RaBraLena finances app" << endl;
    cout << "Please enter the total money you have" << endl;
    cin >> DineroTotal;

    cout << "Do you want to create a new envelope? (Y for yes, N for no)" << endl;
    cout << "You currently have " << envelopes.size() << " envelopes \n";
    cin >> decision;
    if (decision == 'Y'){
        LlenarSobre();
    }

    if (decision == 'N'){
        Investments();
    }

    Savings();

    finishProgram();

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
    if (decision == 'N'){
        Investments();
    }
    else {
        cout << "Sorry, for the moment you do not have enough money\n";
    }
}

// Esta función almacena en un arreglo los constructores de inversión
void Investments(){
    Savest I;
    cout << "Do you want to invest? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << DineroTotal << " to invest" << endl;
        cout << "How many funds do you want to have? You can insert up to 7 investment funds." << endl;
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = I.dataInvestments(i);
            DineroTotal -= I.getAmount();
        }

        cout << "Your investments funds are " << endl;
        for(int i = 0; i < numFund; i++){
            funds[i].show();
        }
    }

    if (decision == 'N'){
        Savings();
    }
}

// Esta función almacena en un arreglo los constructores de ahorro
void Savings(){
    Savest S;
    cout << "Do you want to save? (Y for yes, N for no)" << endl;
    cin >> decision;
    if (decision == 'Y'){
        cout << "You have $ " << DineroTotal << " to saving" << endl;
        cout << "How many funds do you want to have? You can insert up to 5 savings funds." << endl;
        cin >> numFund;
        vector < Savest > funds(numFund);
        for (int i = 0; i < numFund; i++){
            funds[i] = S.dataSavings(i);
            DineroTotal -= S.getAmount();
        }

        cout << "Your savings funds are " << endl;
        for(int i = 0; i < numFund; i++){
            funds[i].show();
        }
    }

    if (decision == 'N'){
        finishProgram();
    }
}

int finishProgram(){
    cout << "Do you need anything more? (Y for yes, N for no)" << endl;
    cin >> decision;

    if (decision == 'Y'){
        LlenarSobre();
    }

    if (decision == 'N'){
        cout << "Your total money is " << DineroTotal << endl;
        return 0;
    }
}
