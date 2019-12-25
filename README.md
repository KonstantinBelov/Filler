# Filler

Filler is a game, where two players / algorithms are fighting on a map. 

A virtual machine organizes the game :
- calls the players alternatively
- gives each a random piece

On each turn, the current player have to put his piece on the map. 
To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin). 

The game appears on the standard input. 

The aim of the game is to put more pieces on the map than the enemy. 

## Algorithm

On the begining of each turn, a Heat Map is created. It represents the Map of the game. 
Values are assigned on each cell of the map. It starts from the position of the enemy and is incremented until it reaches the board edges:

![alt text](https://github.com/mdubus/filler/blob/master/img/heat-map.png)

Then, the algorithm try to put the piece on each position of the map. One case of the piece has to overlap one of players previous. It calculates the score on each position. 
The smaller the score is, the better is a position, because it will get closer of the enemy and bother him to play. 

![alt text](https://github.com/mdubus/filler/blob/master/img/calculate-score.png)

## Example 

![alt text](https://github.com/mdubus/filler/blob/master/img/mdubus-filler-ecole-42.gif)


## Installation

`make`

## Run

`./filler_vm -f [map] -p1 [player1] -p2 [player2]`

Example from the root folder : 
`./resources/filler_vm -f resources/maps/map00 -p1 resources/players/kbelov.filler -p2 resources/players/superjeannot.filler`
