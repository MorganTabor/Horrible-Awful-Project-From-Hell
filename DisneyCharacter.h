/*Filename:		DisneyCharacter.h												*/
/*Project Name:	The Disney Character Class										*/
/*Programmer:	Morgan Tabor													*/
/*Date:			02-05-2024														*/
/*Description:	Header File for the Character class of Data Members, as well	*/
/*as prototypes for all functions, and constants for magic numbers				*/

#pragma once
#pragma warning(disable:4996)
#include <stdio.h	>
#include <string.h	>
#include <stdbool.h	>

/*Magic numbers for size of strings*/
const int kCharacterNameLength = 50;
const int kDateLength = 20;



/*NAME:		Character*/
/*PURPOSE:	Seeks to properly emulate the properties of a disney character.*/
class Character
{
private:

	char name[kCharacterNameLength];	/*Name of Disney Character		*/
	char creationDate[kDateLength];		/*String for date of creation	*/
	char whichPark;						/*Char for name of park			*/
	int	 numMovies;						/*Int for number of movies		*/

public:
	Character(char* newName, char* newCreationDate, char newWhichPark, int newNumMovies);	/*Constructor			*/
	Character(char* newName, char* newCreationDate);										/*Secondary Constructor	*/
	~Character();																			/*Destructor			*/

	/*Accessor methods for all data members*/
	char* GetName(void);
	char* GetDate(void);
	char  GetPark(void);
	int	  GetNumMovies(void);

	/*Mutator methods*/
	bool ChangeNumMovies(int newNumMovies);
	bool ChangeWhichPark(char newPark);

	void ShowInfo(void);											/*Method to print Character information						*/
	void SameMovies(Character character1, Character character2);	/*Method to synch number of movies between two Characters	*/
	void PlaceCharacter(char newPark);								/*Method to move character to another park					*/
};

