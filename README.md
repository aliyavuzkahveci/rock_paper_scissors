# rock_paper_scissors

Rock-Paper-Scissors Game implementation with Object-Oriented Design principles using C++ language

The UML Class diagram is provided under the folder "design"

Options:
* Game Mode:
    0. Argument: -m or --mode
    1. Auto: computer will play with itself. User only watches the game
    2. Vs: computer will play with human player. For each round, user will be asked about his choice

* Round: number of rounds per game [1, 100]
    0. Argument: -r or --round
    1. Default: 100

* Name: name of the player
    0. Argument: -n or --name

* Help: you can simply get detailed explanation about the usage of program by giving one of the following arguments:
    1. --help
    2. -h

* Verbose: You can request the program to provide more detailed output about the game by giving one of the following arguments:
    1. --verbose
    2. -v

How to build: 
./build.sh
*** The project has gtest dependency. So, please make sure that you build it with the Internet connectivity.

Sample Usage:
./rock_paper_scissors --mode AUTO --name IMC -r 100 -v

Probable Outcomes for Each Round:
o: tie
-: lose
+: win
