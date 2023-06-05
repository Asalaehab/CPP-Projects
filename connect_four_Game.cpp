/*         NAMES:                                
 *    Asala Ehab Mohamed Ahmed                 
 * */
#include <iostream>

using namespace std;
 const int row=6;
  const int col=7;
  //check if it true(if there is spaces in column) or false(if there is no space in the column)
bool Insert(char board[row][col],char tile ,int num)

{

    for(int j=row;j>0;)
     if(board[j][num]==' ')
     {
         board[j][num]=tile;
        return true;


     }else
        {
           j--;
        }
        return false;

 }
//to print the board
 void print(char board[row][col])
{
    for(int j=1;j<=row;j++)
{
    for (int i=1;i<=col;i++)
    {cout<<"| ";
       cout<< board[j][i];
    }cout<<"\n";
    cout<<"====================\n";

}
}
//to determine the winner
char Iswinning(char board[row][col])
{



char win;

	for( int i = row; i >0; i-- )
	{

		for( int j = col; j>0;j-- )
		{

			if( (board[i][j] == 'x' )    &&(board[i-1][j-1] == 'x') &&(board[i-2][j-2] == 'x')&&(board[i-3][j-3] == 'x' ))
			{
				win='x';
			}

			 if( (board[i][j] == 'o' )    &&(board[i-1][j-1] == 'o') &&(board[i-2][j-2] == 'o')&&(board[i-3][j-3] == 'o' ))
			{
				win= 'o';
			}


			if( board[i][j] == 'x'   &&(board[i][j-1] == 'x') &&(board[i][j-2] == 'x') &&(board[i][j-3] == 'x' ))
			{
				win='x';
			}
			if( board[i][j] == 'o'   &&(board[i][j-1] == 'o') &&(board[i][j-2] == 'o') &&(board[i][j-3] == 'o' ))
			{
				win='o';
			}

			if( board[i][j] == 'x'   &&
				board[i-1][j] == 'x' &&
				board[i-2][j] == 'x' &&
				board[i-3][j] == 'x' )
			{
				win = 'x';
			}

if( board[i][j] == 'o'   &&
				board[i-1][j] == 'o' &&
				board[i-2][j] == 'o' &&
				board[i-3][j] == 'o' )
			{
				win = 'o';
			}
			if( board[i][j] == 'x'     &&
				board[i-1][j+1] == 'x' &&
				board[i-2][j+2] == 'x' &&
				board[i-3][j+3] == 'x' )
			{
				win = 'x';
			}
			if( board[i][j] == 'o'     &&
				board[i-1][j+1] == 'o' &&
				board[i-2][j+2] == 'o' &&
				board[i-3][j+3] == 'o' )
			{
				win = 'o';
			}

			if ( board[i][j] == 'x'   &&
				 board[i][j+1] == 'x' &&
				 board[i][j+2] == 'x' &&
				 board[i][j+3] == 'x' )
			{
				win = 'x';
			}
			if ( board[i][j] == 'o'   &&
				 board[i][j+1] == 'o' &&
				 board[i][j+2] == 'o' &&
				 board[i][j+3] == 'o' )
			{
				win = 'o';
			}
		}

	}

return win;
}




int main()
{
//the background for game
cout<<"*CONNECT4GAME*"<<endl;
char board[row][col];
for(int j=1;j<=row;j++)
{
    for (int i=1;i<=col;i++)
    {cout<<"| ";
        board[j][i]=' ';
    }cout<<"\n";
    cout<<"=============\n";
}
char found;
while(found!='x'&&found!='o'){
char tile;
int play;
cout<<"player 1 oR 2 !:";
cin>>play;
int num;
if(play==1)
{
    cout<<"player 1 : choose number from (1----7)\n";
    cin>>num;
    tile='x';

}
else
{
    cout<<"player 2 : choose number from (1----7)\n";
    cin>>num;
    tile='o';
}
if(Insert(board,tile,num))
{
    print (board);
    found=Iswinning(board);


}
else
{
    cout<<"Enter the column number again "<<endl;
    cin>>num;
    while((Insert(board,tile,num)==false))
          {
              cout<<"please enter correct column number:";
              cin>>num;
          }

    print(board);



}

}

if (found=='x')
{
    cout<<"player 1 is winning\n";
}
else if(found=='o')
{
    cout<<"player 2 is winning \n";
}
return 0;}

