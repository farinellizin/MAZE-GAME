#include "Pile.hpp"
#include "Queue.hpp"
using namespace std;

void run() {
    char option;

    do {
        cout << endl << "--------------------------------------------------------------";
        cout << endl << endl << "\t\t~ Welcome to the main menu ~" << endl;
        cout << endl << "\t- Select your option: " << endl;
        cout << endl << "\t\tA. BFS | Breadth - first search;" << endl << "\t\tB. DFS | Depth - first search;" << endl;
        cout << "\t\tC. Quit.";
        cout << endl << endl << "\t- Your choice: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            cout << endl << "--------------------------------------------------------------" << endl << endl;
            solve();
        } else if (option == 'B') {
            cout << endl << "--------------------------------------------------------------" << endl << endl;
            runMatrix();
        } else if (option == 'C') {
            cout << endl << "--------------------------------------------------------------" << endl << endl;
            cout << "\t\t    You chose to quit." << endl << endl;
            cout << "--------------------------------------------------------------" << endl << endl;
        }
    } while (option != 'C');
}

int main () {
    run();

    // Fila linha, coluna;
    // FFVazia(&linha);
    // FFVazia(&coluna);
    // Item l, c;

    // int i, j;

    // j = 0; i = 0;
    // l.val = i;
    // c.val = j;

    // Enfileira(&linha, l);
    // Enfileira(&coluna, c);

    // cout << "ENFILEIREI [" << l.val << "] [" << c.val << "]" << endl;

    // Desenfileira(&linha, &l);
    // Desenfileira(&coluna, &c);

    // cout << "DESENFILEIREI [" << l.val << "] [" << c.val << "]" << endl << endl;

    // l.val = 1;
    // c.val = 0;

    // Enfileira(&linha, l);
    // Enfileira(&coluna, c);

    // cout << "ENFILEIREI [" << l.val << "] [" << c.val << "]" << endl;

    // l.val = 0;
    // c.val = 1;

    // Enfileira(&linha, l);
    // Enfileira(&coluna, c);

    // cout << "ENFILEIREI [" << l.val << "] [" << c.val << "]" << endl;

    
    // Desenfileira(&linha, &l);
    // Desenfileira(&coluna, &c);

    // cout << "DESENFILEIREI [" << l.val << "] [" << c.val << "]" << endl << endl;





















}