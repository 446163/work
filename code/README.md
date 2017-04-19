# Ultimate-Tic-Tac-Toe
An inception version of tic tac toe for terminal 


 . . . | . . . | . . .
 . . . | . . . | . . .
 . . . | . . . | . . .
-------+-------+-------		 . | . | .
 . . . | . . . | . . .	 	---+---+---
 . . . | . . . | . . .	 	 . | . | .
 . . . | . . . | . . .	 	---+---+---
-------+-------+-------		 . | . | .
 . . . | . . . | . . .
 . . . | . . . | . . .
 . . . | . . . | . . .


This is a version of tic-tac-toe that has a game of tic-tac-toe in each square. 

## Quick rules

The way that it works is that when you play in a place in one of the small squares ( like you normally would ) then your piece will be placed there, but you will force your enemy into the game in that place on the board. For example, if you were in square 1 and you wanted to get a good win there then you would play in the middle in place 5, but by doing this you let your enemy take a turn in the middle game, you may think that this is not a problem but it is. The way that you win the game is that when you win a small game in a square, you have then won that square ( shown to the right of the main board ), then the first person to get 3 in a row in that sub board will win the game. So by trying to win a small square you give the enemy an advantage to win the game of that position. 

## How to use

To compile it use gcc as clang does not work:

```
gcc uttt.c -o uttt
```

When you get to the menu you can press 's' to start the game or 'q' to quit. When you start the game you will be asked to force the initial game that you want to start in, then when you input that number that game will be highlight and you will be asked where you want to play and the game will carry on normally from here. 

## Edge cases

If you are forced to play in a game that has no free spaces then ( like at the beginning of the game ), you get to choose what game you want to play in and then take your turn from there. 

## Why?

I made this just to test my basic C, so there are probably many ways that this can be improved that I don't know about ( even if I should ), but hey... it works. 
