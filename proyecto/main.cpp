#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {

    //declaramos nuestras variables
    double saving = 0, invest = 0;
    int i = 0;
    char answer[5] = "yon";
    array < string, 7 > investsFunds = {"fund"};
    array < string, 5 > savingsFunds = {"fund"};

    // esta variable solo se ingresa manualmente para probar este código. Para la app completa esta variable debe conseguirse en base a los condicionales del código principal
    cin >> saving;

    //preguntamos al usuario que quiere hacer
    cout << "Would you like to invest?" << endl;
    cin >> answer;


    //si el usuario desea invertir, entonces:
    if (strcmp(answer,"yes") == 0){
        cin.ignore(10000, '\n'); //esta función es para eliminar el enter y se pueda usar correctamente la función getline()

        //El 50% del dinero destinado primero al ahorro, se destina a la inversión
        invest = saving * 0.5;

        //primero se le pide al usuario ingresar sus fondos de inversión
        cout << "You have $ " << invest << " to invest" << endl;
        cout << "What would you like to invest in? Insert up to 7 investment funds. Type the name of the fund followed it value." << endl;
        cout << "When you finish press 'f'" << endl;
        for (int i = 0; i < 7; i++){
            cout << "fund " << i << ":";
            getline(cin, investsFunds[i]);
            if (investsFunds[i] == "f"){
                break;
            }
        }

        //Luego, se le pide al usuario ingresar sus fondos de ahorro
        cout << "You have $ " << saving - invest << " to saving. Insert up to 5 savings investsFunds. Type the name of the found followed it value." << endl;
        cout << "When you finish press 'f'" << endl;
        for (int i = 0; i < 5; i++){
            cout << "fund " << i << ":";
            getline(cin, savingsFunds[i]);
            if (savingsFunds[i] == "f"){
                break;
            }
        }

        // Se le muestra al usuario tanto sus fondos de inversión como sus fondos de ahorro
        cout << "Your invest funds are:" << endl;
        for (int i = 0; i < 7; i++){
            cout << investsFunds[i] << endl;
        }
        cout << "Your savings funds< are:" << endl;
        for (int i = 0; i < 7; i++){
            cout << savingsFunds[i] << endl;
        }
    }


    //Si al usuario solo le interesa tener fondos de ahorro, entonces:
    if (strcmp(answer, "no") == 0){
        cin.ignore(10000, '\n');

        //se le pide al usuario ingresar sus fondos de ahorro
        cout << "You have $ " << saving << " to saving. Insert up to 5 savings investsFunds. Type the name of the found followed it value." << endl;
        cout << "When you finish press 'f'" << endl;
        for (int i = 0; i < 5; i++){
            cout << "fund " << i << ":";
            getline(cin, savingsFunds[i]);
            if (savingsFunds[i] == "f"){
                break;
            }
        }

        //sele muestraal usuario cuales son sus fondos de ahorro actuales
        cout << "Your savings funds are:" << endl;
        for (int i = 0; i < 5; i++){
            cout << savingsFunds[i] << endl;
        }
    }

    return 0;
}
