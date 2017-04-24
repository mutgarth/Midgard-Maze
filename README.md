# Midgard Maze

  This is Midgard Maze Game, the game where you will find a lot of random traps trying to hurt you.

## Synopsis

  This game was made in C++ as a project of OOP class. The goal is to implement the main ideas of OOP such class, object and polymorphism.

  The goal of the game is to scape from a maze, where random traps will appears every time the player moves. When the player encounter a trap,
  he will loose some health points. Besides the traps, the player can find Bonus Points, which will increase the player's health points and add
  score points.

  Not only find the exit of the maze is enough to win the game, the player must have X score points, where X is defined in SCORE_COND in main.cpp.


## Installation

  This game was built using ncurses library. You need to install it to play.

### Installing ncurses on Mac OS

  Please refer to this link: https://gist.github.com/cnruby/960344

### Installing ncurses on Debian based systems

  sudo apt-get install libncurses5-dev libncursesw5-dev

### Windows Users

  This game was not tested on windows systems yet.

## Changing Game Parameters

  The follow parameters can be find in main.cpp.

* NUM_BON : Number of bonus in game.
* NUM_TRAP : Numbers of traps in game.
* BON_TO_SCORE : How many score points the player will gain when find a bonus.
* BON_LIFE : How many health points the player will gain when find a bonus.
* TRAP_DAMAGE : How many health points the player will loose when find a trap.
* SCORE_COND : How many points are needed to unlock the gate.

  All parameters can be changed. In case of any change, go to main directory and run make in terminal.

## How to Play

  To run the game just execute midgard_maze located at bin/midgard_maze (On Unix like systems type ./midgard_maze).

  At the start of the game, a menu will be opened in your terminal. Choose 1 to open the rank or 2 to start the game.

  The player is showed as '@', traps as 'O' and bonus as '&'. To move the player use W,A,S and D keys from the keyboard.
  The player can not transpose walls which are identified as '='.

  When the player dies, nothing can be done, he will just quit from the game. When the player win, he can save his name on a rank list.
  A final menu will be opened on the terminal, where the player can choose 1 to see the actual rank or 2 to quit the game.

  If there is any need to exit the game just press cmd + c.

## doc Folder

  The map and rank are located in doc folder. To clean the rank just delete the names insid the file.

  To change the map just replace the map.txt with your own map. The map must be a 20x50 char matrix where the character '-' is the path and
  '=' is the wall.
