#include "Queue.hpp"
using namespace std;

void a_star_menu() {
    char option;

    cout << "----------------------------------------------------------------------------------------------";
    cout << endl << endl << "\t\t\t\t~ Welcome to the A* menu ~" << endl;
    cout << endl << "\t\t\t- Select your option: " << endl;
    cout << endl << "\t\t\t\tA. Manhattan Heuristic;" << endl << "\t\t\t\tB. Euclidean Heuristic;" << endl;
    cout << "\t\t\t\tC. Quit." << endl << endl <<"\t\t\t- Your choice: ";
    cin >> option;
    option = toupper(option);

    if (option == 'A') {
        cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t     ~ You chose the Manhattan Heuristic ~" << endl << endl;
        solve(true);
    } else if (option == 'B') {
        cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t     ~ You chose the Euclidean Heuristic ~" << endl << endl;
        solve(false);
    } else if (option == 'C') {
        cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t   ~ You chose to quit ~" << endl << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl << endl;
    }
}

void run() {
    char option;

    do {
        cout << endl << "----------------------------------------------------------------------------------------------";
        cout << endl << endl << "\t\t\t\t~ Welcome to the main menu ~" << endl;
        cout << endl << "\t\t\t- Select your option: " << endl;
        cout << endl << "\t\t\t\tA. BFS | Breadth - first search;" << endl << "\t\t\t\tB. DFS | Depth - first search;" << endl;
        cout << "\t\t\t\tC. A*  | Heuristic ways to be aplied in BFS;" << endl << "\t\t\t\tD. Quit.";
        cout << endl << endl << "\t\t\t- Your choice: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t\t  ~ You chose the BFS method ~" << endl << endl;
            // solve();
        } else if (option == 'B') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t\t  ~ You chose the DFS method ~" << endl << endl;
            // runMatrix();
        } else if (option == 'C') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t\t ~ You chose the A* method ~" << endl << endl;
            a_star_menu();
        } else if (option == 'D') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t\t   ~ You chose to quit ~" << endl << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl << endl;
        }
    } while (option != 'C');
}

int main () {
    run();
}