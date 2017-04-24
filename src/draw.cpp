#include "draw.hpp"
#include "map.hpp"
#include <string>
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>

using namespace std;

Draw::Draw(){}

void Draw::drawMap(Map *mapa){
    for(int i = 0; i < 20; i++){
      for(int u = 0; u < 50; u++){
        printw("%c", mapa->getCharacter(i,u));
        if(u >= 49){
          printw("\n");
        }
    }
  }
}

void Draw::drawPlayer(Map *mapa, char sprite, int posx, int posy){
  mapa->setCharacter(sprite, posx, posy);
}

void Draw::drawTrap(Map *mapa, char sprite, int posx, int posy){
  mapa->setCharacter(sprite, posx, posy);
}

void Draw::drawBonus(Map *mapa, char sprite, int posx, int posy){
  mapa->setCharacter(sprite, posx, posy);
}


void Draw::drawStatus(Player *player, int SCORE_COND){
  printw("\n");
  printw("HP: %d ------------ Score: %d", player->getLife(), player->getScore());
  printw("\n");
  // printw("Score: %d",player->getScore());
  // printw("\n");
  int stillPoints = SCORE_COND - player->getScore();

  if(stillPoints>0){
    printw("More %d points to open the 'g8' ", stillPoints);
    printw("\n");
    printw("\n");

  } else {
    printw("GO! You can pass through the gates!", stillPoints);
    printw("\n");
    printw("\n");

  }

}

void Draw::drawPresentation(int SCORE_COND){
  printw("\n");
  printw("Get %d bonus points or more to pass through the 'g8'.", SCORE_COND);
  printw("\n");
  printw("\n");
  printw("Press any key to start...");
  printw("\n");
}

void Draw::drawRank(){
  string aux;
  ifstream rankList;
  rankList.open("doc/rank_list.txt");

  while (TRUE)
  {
    getline(rankList,aux);
    if(rankList.eof() ) break;
    cout << aux << endl;
  }

  rankList.close();
}

void Draw::drawInitialMenu(){

    int option;

    system("clear");
    cout << "    ---------------------------------------------------------" << endl;
    cout << "    -            WELCOME TO THE MAZE OF THE GODS            -" << endl;
    cout << "    - This maze is like your life. When everything is going -" <<endl;
    cout << "    - ok, something bad randomically will occurs with you!  -" << endl;
    cout << "    ---------------------------------------------------------" << endl << endl;
    cout << "    -                 1) Check rank                         -" << endl;
    cout << "    -                 2) Go to the Maze of gods             -" << endl<<endl;
    cout << "    ---------------------------------------------------------" << endl<<endl;
    cout << "                     Your option: " ;
    cin >> option;

      while(option != 1 && option != 2 ){
        cout << "              Please insert a valid option: ";
        cin >> option;
        getchar();
        while(!(cin >> option)){
          cin.clear();
          cin.ignore(999,'\n');
          cout << "              Please insert a valid option: ";
        }
      }

      switch (option) {
        case 1:
          system("clear");
          cout << "The game will start in 5 sec..." << endl<< endl;

          cout << "------- PLAYERS AND THEIR POINTS -------"<< endl << endl;
          drawRank();
          sleep(5);

        case 2:
          getchar();
      }
}

void Draw::drawFinalMenu(Player *player){

      system("clear");
      cout << "-------- You Win! --------" << endl;
      cout << "Your Score: " << player->getScore() << endl;
      cout << "You deserve a place among the gods" << endl;
      cout << "What's your name? : ";
      string name;
      getline(cin,name);
      // getchar();

      fstream rankFile;
      rankFile.open ("doc/rank_list.txt", fstream::app);
      rankFile << name << " ---- " << player->getScore()<< "\r\n";;
      rankFile.close();

    system("clear");
    // getchar();
    cout << "--------- WHAT WOULD YOU LIKE TO DO NOW WARRIOR? -------" << endl<<endl;
    cout << "               1) Check Rank " << endl;
    cout << "               2) Quit  game." << endl << endl;
    cout << "--------------------------------------------------------" << endl<<endl;

    int option;
    cout << "                     Your Option: ";
    cin >> option;

    while(option != 1 && option != 2 ){
      cout << "              Please insert a valid option: ";
      cin >> option;
      while(!(cin >> option)){
        cin.clear();
        cin.ignore(999,'\n');
        cout << "              Please insert a valid option: ";
      }
    }

    switch (option) {
      case 1:
        {
          cout << "------- PLAYERS AND THEIR POINTS -------"<< endl << endl;
          drawRank();
          break;
        }
      case 2:
        getchar();
  }
}
