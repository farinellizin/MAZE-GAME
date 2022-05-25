#include "Queue.hpp"
using namespace std;

void run() {
    char option;

    do {
        cout << endl << "----------------------------------------------------------------------------------------------";
        cout << endl << endl << "\t\t\t\t~ Welcome to the main menu ~" << endl;
        cout << endl << "\t\t\t- Select your option: " << endl;
        cout << endl << "\t\t\t\tA. Manhattan Heuristic;" << endl << "\t\t\t\tB. Euclidean Heuristic;" << endl;
        cout << "\t\t\t\tC. Quit.";
        cout << endl << endl << "\t\t\t- Your choice: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t      ~ You chose the Manhattan Heuristic ~" << endl << endl;
            solve();
        } else if (option == 'B') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t\t  ~ You chose the Euclidian Heuristic ~" << endl << endl;
            
        } else if (option == 'C') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t\t   ~ You chose to quit ~" << endl << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl << endl;
        }
    } while (option != 'C');
}

int main () {
    run();

    // Fila teste;
    // // Block *i, *j;
    // FFVazia(&teste);

    // Item aux;
    // aux.euclidean_distance = 8.9;
    // Enfileira(&teste, aux);

    // aux.euclidean_distance = 2.002;
    // Enfileira(&teste, aux);

    // aux.euclidean_distance = 14.23;
    // Enfileira(&teste, aux);

    // aux.euclidean_distance = 2.2;
    // Enfileira(&teste, aux);

    // aux.euclidean_distance = 8;
    // Enfileira(&teste, aux);

    // aux.euclidean_distance = 54.23;
    // Enfileira(&teste, aux);

    // euclidean_print(&teste);

    // // i = teste.first -> prox;
    // // // j = i -> prox;
    // // // cout << "valor de i: " << i -> data.distance << endl;
    // // // cout << "valor de J: " << j -> data.distance << endl;

    // // while (i != NULL) {
    // //     j = i -> prox;
    // //     while (j != NULL) {
    // //         if (j -> data.distance < i -> data.distance) {
    // //             swap(i, j);
    // //         }
    // //         j = j -> prox;
    // //     }
    // //     i = i -> prox;
    // // }

    // euclidean_sort(&teste);
    // cout << endl << endl << "ORGANIZANDO" << endl << endl;
    // euclidean_print(&teste);
}