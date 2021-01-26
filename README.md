# rock_paper_scissors

Rock-Paper-Scissors Game implementation with Object-Oriented Design principles using C++ language

The UML Class diagram is provided under the folder "design"

Options:
* Game Mode:
    * Argument: -m or --mode
    * Auto: computer will play with itself. User only watches the game
    * Vs: computer will play with human player. For each round, user will be asked about his choice

* Round: number of rounds per game [1, 100]
    * Argument: -r or --round
    * Default: 100

* Name: name of the player
    * Argument: -n or --name

* Help: you can simply get detailed explanation about the usage of program by giving one of the following arguments:
    * Argument: -h or --help

* Verbose: You can request the program to provide more detailed output about the game by giving one of the following arguments:
    1. Argument: -v or --verbose

How to build: 
./build.sh

* The project has gtest dependency. So, please make sure that you build it with the Internet connectivity.

Sample Usage:
./rock_paper_scissors --mode AUTO --name YourName -r 100 -v

Probable Outcomes for Each Round:
* o: tie
* -: lose
* +: win
