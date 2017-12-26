//Mequelle Thomas
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void counter(char, char);
char findWinner(char, char);	//	FUNC DECLARATIONS AND STUFF
bool validData( char, char);
bool eof(char,char);
void get_data(char&, char& );
int showscore(int &, int &, int &);

//******************* VOID FUNC DECLARATIONS
void showOptions ();
void playround (char, char , int & ,int &,int &);

int main()             //MAIN FUNCTION WHERE THE MAGIC HAPPENS
{
	char a, b, w ;
	char p1, p2;
	int i = 0;
	int x = 0;
	int y = 0;
	int z = 0;

showOptions ();
get_data(p1, p2);

while(!eof(p1,p2) && validData( p1, p2 ))
{
        playround (p1, p2 , x ,y,z );
		showOptions ();
		get_data(p1,p2);
		findWinner(p1,p2);
}
showscore(x,y,z);
return 0;

}



 void playround (char p1, char p2 , int &x , int &y , int &z )
{

	char w = findWinner(p1,p2);

	showOptions();

	showscore(x,y,z);

    if (w == 't')
	{

			system("CLS");
			cout<< "\ndraw round "<<endl;
			z++;


	}

	else if(w == '1')
	{
			system("CLS");
			cout<< "\nplayer 1 wins round "<<endl;
			++y;


	}

	else //if ( w == '2')  Not needed
	{       system("CLS");
			cout<<"\nplayer 2 wins round "<<endl;
			x++;


	}

}




bool eof( char p1, char p2)  //SOME EOF
{
	if(p1=='Q'|| p2=='Q')
		return true;
	else return false;
}



char findWinner(char p1 ,char p2) //THIS FINDS THE WINNER
{
	if(p1 == p2 )
	{
		cout<<"t";
		return 't';
	}


	else if (p1 == 'R' && p2 == 'S'|| p1 == 'P' && p2 == 'R'||p1 == 'S' && p2 == 'P')
	{



		return '1';
	}

	else
	{

		return '2';
	}


}

void get_data(char& p1, char& p2)   //gets The data
{
    cout<<" \n Player 1, choose a play. \n" ;
    cin>>p1;
    p1=char(toupper(p1));

 	if(p1 !='Q')

    cout<<" \n Player 2, choose a defense. \n" ;
    cin>>p2;
	p2=char(toupper(p2));

}


bool validData (char p1 , char p2)
{

	if(p1 =='R'|| p1 =='P' || p1 == 'S' || p2 =='R' || p2 =='P' || p2 =='S' )
		return true;
	else
		return false;



}




//************************* 	MENU OPTIONS
void showOptions ()
{

	cout<<"\nWelcome to Rock,Paper,Scissors program\n"
		<<"r - Rock\n"
		<<"p - Paper\n"
		<<"s - scissors\n"
		<<"q - Quit and Show score \n"
		<<"Enter Your Choice\n"
		<<"*******************\n"

		<<"*******************\n"
		<<"By Mequelle Thomas\n";


}

//**************************

int showscore(int &x , int &y, int &z)
{

cout<<"\nThe number of Draws is "<<z;
cout<<"\nPlayer one has won "<<y<< " times ";
cout<<"\nPlayer two has won "<<x<< " times \n";
if(y >x)
 cout<<"\n Player one is winner overall";
else if (x>y)
cout<<"\n player two is winner overall";
else
cout<<"\n none are winners, both of you are terrible\n";



}




