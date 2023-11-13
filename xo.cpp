#include <iostream>
#include <stdlib.h>

char a[10];
short int ct = 1;

//Shows the player the current state of the game
void state(){

   //Announces turn
   std::cout << "Player ";
   (ct % 2 == 1) ? std::cout << "X" : std::cout << "O";
   std::cout <<", it's your turn" << std::endl;
   
   //Builds the Tic Tac Toe grid and prints symbols when necessary 
   for (int i = 0 ; i < 3; i++)
   {
      for (int j = 1; j <= 3; j++)
      {
         if (a[3*i+j] == 'O' || a[3*i+j] == 'X')
         {
            std::cout << " " << a[3*i+j] << " ";
         }
         else std::cout <<"   ";
         if (j != 3) std::cout <<"|";
      }

      if (i != 2)  //dont print these after the last
      std::cout << std::endl << "---|---|---" << std::endl;
      else std::cout << std::endl;
   }
}

/*
Model of the grid:

 X | X | 0
---|---|---
 X | 0 | 0
---|---|---
   |   |  
*/

void makeMove()
{
   std::cout << "Input your coordinates: ";
   int x, y;
   std::cin >> x >> y;
   
   //Check validity of coordinates
   if (x < 1 || x > 3 || y < 1 || y > 3)
   {
      std::cout << "The coordinates you have entered are invalid." << std::endl;
      makeMove();
      return;
   }

   //Check availability of coordinates
   if (a[(x-1)*3 + y] == 'X' || a[(x-1)*3 + y] == 'O')
   {
      std::cout << "That space is already taken" << std::endl;
      makeMove();
      return;
   }

   a[(x-1)*3 + y] = (ct % 2 == 1)  ? 'X' : 'O';
}

//Checks if a player has won
short int won()
{ 
   for (int i = 0; i < 3 ; i++)
   {
      if (a[3*i + 1] == a[3*i + 2] &&  a[3*i + 2] == a[3*i + 3] || a[3*0 + i + 1] == a[3*1 + i + 1] &&  a[3*1 + i + 1] == a[3*2 + i + 1]) 
      {
         return (ct % 2 == 1) ? 1 : 2;
      }
   }
   if (a[1] == a[5] && a[5] == a[9] || a[3] == a[5] && a[5] == a[7])
   {
      return (ct % 2 == 1) ? 1 : 2;
   }
   return 0;
}

int main()
{
   int x;
   for (int i = 0; i < 4; i++)
   {
      
      state();
      makeMove();
      system("cls");
      ct++;
   }
   for (int i = 0; i < 5; i++)
   {
       
      state();
      makeMove();
      system("cls");
      if (x = won()) 
      {
      state();
      std::cout << std::endl <<  "Player " << x << " won!";
      return 0;
      }
      ct++;  
   }
   state();
   std::cout << "It's a tie!";
   return 0;
}
