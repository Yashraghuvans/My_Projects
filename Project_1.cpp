//written by Yash Raghuvanshi
//rock paper sizer game with time limit of 10 seconds


#include<bits/stdc++.h>
using namespace std;

class game{
public:
    int random_generator() {
        return rand() % 3;
    }

    int check(int player, int computer) {
        // 0 for rock, 1 for paper, 2 for scissors
        if (player == computer) {
            return 0; // Tie
        } else if ((player == 0 && computer == 2) ||
                   (player == 1 && computer == 0) ||
                   (player == 2 && computer == 1)) {
            return 1; // Player wins
        } else {
            return 2; // Computer wins
        }
    }

    string chos(int ans) {
        switch (ans) {
            case 0:
                return "Rock 🌑";
            case 1:
                return "Paper 📜";
            case 2:
                return "Scissors ✂️";
        }
        return "";
    }
};

int main(){
    int player, computer, result, cnt = 1;
    int playerScore = 0, computerScore = 0;
    game g;

    // Banner
    A:
    for (int i = 0; i < 80; ++i) {
        cout << "-";
    }
    cout << endl;
    cout << "\n\t\t\t Welcome to the game\t\t\n" << endl;
    for (int i = 0; i < 80; ++i) {
        cout << "-";
    }
    cout << endl;

    //time limit
    int timeLimit = 5; 
    time_t startTime = time(0);

    // Game loop
    while (cnt) {
        cout<<"\n\t\t| You have only 10 seconds to answer !! |\n"<<endl;
        for (int i = 0; i < 80; ++i) {
                cout << "-";
            }
            cout << endl;
        
        // Get player's choice
        cout << "Select the option : \n\t\t0 : Rock 🌑\n\t\t1 : Paper 📜\n\t\t2 : Scissors ✂️" << endl;
        cout << "\t\t=";
        cin >> player;
        cout << "\n";

        // Generate computer's choice
        computer = g.random_generator();

        // Determine the winner
        result = g.check(player, computer);

        // Get computer's choice as a string
        string computerChoice = g.chos(computer);
        
        
        //time limit test
        if (difftime(time(0), startTime) >= timeLimit) {
        for (int i = 0; i < 80; ++i) {
                cout << "-";
            }
            cout << endl;
        
        cout << "\n\t\tTime's up!\n" << endl;
        cout<<"\n\t\tYou excide the time limit !!\n"<<endl;
        cout << "\n\t\twant to play again (0 or 1)\n\t\t=";
        cin >> cnt;
        if (cnt == 1) {
            cout << "\033[H\033[J" << flush;
            goto A;
        }
        
        for (int i = 0; i < 80; ++i) {
                cout << "-";
            }
            cout << endl;
        
        return 0;
        }
        
        
        // Display results
        if (result == 0) {
            for (int i = 0; i < 80; ++i) {
                cout << "-";
            }
            cout << endl;
            cout << "\n\t\tIt's a tie!" << endl;
            cout << "\t\tComputer has choosed " << computerChoice << endl;
            cout << "\n";

        } else if (result == 1) {
            for (int i = 0; i < 80; ++i) {
                cout << "-";
            }
            cout << endl;
            cout << "\n\t\tYou won good work !\n" << endl;
            cout << "\t\tComputer has choosed " << computerChoice << endl;
            cout << "\n";
            playerScore++;
        } else {
            for (int i = 0; i < 80; ++i) {
                cout << "-";
            }
            cout << endl;
            cout << "\n\t\tYou loss try again !\n" << endl;
            cout << "\t\tComputer has choosed " << computerChoice << endl;
            cout << "\n";
            computerScore++;
        }
       


        
        
        
        // Display scores
         for (int i = 0; i < 80; ++i) {
            cout << "-";
        }
        cout << endl;
        cout << "\n\t\tYour score: " << playerScore << endl;
        cout << "\n\t\tComputer score: " << computerScore <<"\n"<< endl;



        // Replay
        for (int i = 0; i < 80; ++i) {
            cout << "-";
        }
        cout << endl;

        cout << "\n\t\twant to play again (0 or 1)\n\t\t=";
        cin >> cnt;
        if (cnt == 1) {
            cout << "\033[H\033[J" << flush;
            goto A;
        }
    }
    return 0;
}
