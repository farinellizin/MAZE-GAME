#include "Queue.hpp"
using namespace std;

void run() {
    char option;

    do {
        cout << endl << "----------------------------------------------------------------------------------------------";
        cout << endl << endl << "\t\t\t\t~ Welcome to the main menu ~" << endl;
        cout << endl << "\t\t\t- Select your option: " << endl;
        cout << endl << "\t\t\t\tA. BFS | Breadth - first search;" << endl << "\t\t\t\tB. DFS | Depth - first search;" << endl;
        cout << "\t\t\t\tC. Quit.";
        cout << endl << endl << "\t\t\t- Your choice: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            cout << endl << "----------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t      ~ You chose the Manhattan Heuristic ~" << endl << endl;
            heuristic_manhattan();
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
}