#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    //declaramos nuestras variables
    double saving = 0, invest = 0, totalMoney = 0;
    int i = 0;
    char answer[5] = "yon";
    vector < string > investsFundsN;
    vector < string > savingsFundsN;
    vector < double > investsFundsV;
    vector < double > savingsFundsV;

    // esta variable solo se ingresa manualmente **para probar este código. Para la app completa esta variable debe conseguirse en base a los condicionales del código principal
    cin >> totalMoney;

    //preguntamos al usuario que quiere hacer
    cout << "Would you like to invest?" << endl;
    cin >> answer;


    //si el usuario desea invertir, entonces:
    if (strcmp(answer,"yes") == 0){
        cin.ignore(10000, '\n'); //esta función es para eliminar el enter y se pueda usar correctamente la función getline()


        //primero se le pide al usuario ingresar sus fondos de inversión
        cout << "You have $ " << totalMoney << " to invest" << endl;
        cout << "What would you like to invest in? Type the name of the fund, you can insert up to 7 investment funds." << endl;
        cout << "When you finish press 'f'" << endl;
        for (int i = 0; i < 7; i++){
            cout << "fund " << i << ":";
            getline(cin, investsFundsN[i]);
            if (investsFundsN[i] == "f"){
                break;
            }
        }
        cout << "Now, you enter the corresponding value for each fund. When you finish press '0'" << endl;
        for (int i = 0; i < 7; i++){
            cout << "valueFund " << i << ":";
            cin >> investsFundsV [i];
            totalMoney -= investsFundsV [i];
            if (investsFundsV[i] == 0){
                break;
            }
        }

        //Luego, se le pide al usuario ingresar sus fondos de ahorro
        cout << "You have $ " << totalMoney << " to saving. Type the name of the found, you can insert up to 5 savings funds." << endl;
        cout << "When you finish press 'f'" << endl;
        cin.ignore(10000, '\n');
        for (int i = 0; i < 5; i++){
            cout << "fund " << i << ":";
            getline(cin, savingsFundsN[i]);
            if (savingsFundsN[i] == "f"){
                break;
            }
        }
        cout << "Now, you enter the corresponding value for each fund. When you finish press '0'" << endl;
        for (int i = 0; i < 7; i++){
            cout << "valueFund " << i << ":";
            cin >> savingsFundsV [i];
            totalMoney -= savingsFundsV [i];
            if (savingsFundsV[i] == 0){
                break;
            }
        }

        // Se le muestra al usuario tanto sus fondos de inversión como sus fondos de ahorro
        cout << "Your invest funds are:" << endl;
        for (int i = 0; i < 7; i++){
            cout << investsFundsN[i] << " $" << investsFundsV [i] << endl;
        }
        cout << "Your savings funds are:" << endl;
        for (int i = 0; i < 5; i++){
            cout << savingsFundsN[i] << " $" << savingsFundsV [i] << endl;
        }
    }


    //Si al usuario solo le interesa tener fondos de ahorro, entonces:
    if (strcmp(answer, "no") == 0){
        cin.ignore(10000, '\n');

        //se le pide al usuario ingresar sus fondos de ahorro
        cout << "You have $ " << totalMoney << " to saving. Type the name of the found, you can insert up to 5 savings funds." << endl;
        cout << "When you finish press 'f'" << endl;
        cin.ignore(10000, '\n');
        for (int i = 0; i < 5; i++){
            cout << "fund " << i << ":";
            getline(cin, savingsFundsN[i]);
            if (savingsFundsN[i] == "f"){
                break;
            }
        }
        cout << "Now, you enter the corresponding value for each fund. When you finish press '0'" << endl;
        for (int i = 0; i < 7; i++){
            cout << "valueFund " << i << ":";
            cin >> savingsFundsV [i];
            totalMoney -= savingsFundsV [i];
            if (savingsFundsV[i] == 0){
                break;
            }
        }

        //sele muestraal usuario cuales son sus fondos de ahorro actuales
        cout << "Your savings funds are:" << endl;
        for (int i = 0; i < 5; i++){
            cout << savingsFundsN[i] << " $" << savingsFundsV [i] << endl;
        }
    }
    return 0;
}
