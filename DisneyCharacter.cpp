/*Filename:		DisneyCharacter.cpp			*/
/*Project Name:	The Disney Character Class	*/
/*Programmer:	Morgan Tabor				*/
/*Date:			02-05-2024					*/
/*Description:								*/

#include "DisneyCharacter.h"

/*NAME:		PlaceCharacter																								*/
/*PURPOSE:	Calls ChangeWhichPark to change whichPark of current Character class, and return an error or success message*/
/*INPUTS:	char whichPark: A character variable to be passed into the mutator											*/
/*OUTPUTS:	Error message if mutator fails, outputs what new park is													*/
/*RETURNS:	NONE																										*/
void Character::PlaceCharacter(char newPark)
{
	if (ChangeWhichPark(whichPark) == false)
	{
		printf("ERROR: Input Park was Invalid.\n");
	}
	printf("Character park value is %c", whichPark);
}

/*NAME:		ChangeNumMovies																*/
/*PURPOSE:	Validates newNumMovies is >= 0, and returns boolean based on its validity	*/
/*INPUTS:	int newNumMovies: integer to replace numMovies								*/
/*OUTPUTS:	NONE																		*/
/*RETURNS:	true if newNumMovies is >= 0, false if newNumMovies <=0						*/
bool Character::ChangeNumMovies(int newNumMovies)
{
	if (newNumMovies >= 0) /*makes sure newNumMovies isn't a negative*/
	{
		numMovies = newNumMovies;
		return true;
	}
	else
	{
		return false; /*if newNumMovies is a negative it isn't passed.*/
	}
}



/*NAME:		SameMovies*/
/*PURPOSE:	Sets the value of character1's numMovies to character2's numMovies					*/
/*INPUTS:	Character character1: Character class whose numMovies will be changed				*/
/*			Character character2 : Character class whose numMovies will overwrite character1's	*/
/*OUTPUTS:	Outputs error message if Mutator fails												*/
/*RETURNS:	NONE																				*/
void Character::SameMovies(Character character1, Character character2)
{
	int temp = 0; /*temp value storage*/

	temp = character2.numMovies; /*stores character 2's number of movies*/
	
	/*if temp is valid, set's character1's numMovies as it*/
	if (temp >= 0)
	{
		character1.numMovies = temp;
	}
	else
	{
		printf("%s's number of movies was invalid.\n", character2.name);
	}
	printf("%s's number of movies was set to %d\n", character1.name, character1.numMovies);
}



/*NAME:		ShowInfo										*/
/*PURPOSE:	Prints all valid data members of Character class*/
/*INPUTS:	NONE											*/
/*OUTPUTS:	Prints all valid data members of Character class*/
/*RETURNS:	NONE											*/
void Character::ShowInfo(void)
{
	printf("Character name is:\t%s\n", name);
	if (strcmp(creationDate, " ") != 0) /*if the creation date isn't valid or is empty, it won't be printed*/
	{
		printf("Character was created on:\t%s\n", creationDate);
	}
	printf("Character has been in %d movies\n", numMovies);
	if (whichPark == 78)
	{
		printf("Character is currently in the Magic Kingdom\n");
	}
	else if (whichPark == 83)
	{
		printf("Character is currently in Disney Studios\n");
	}
	else if (whichPark == 65)
	{
		printf("Character is currently in Animal Kingdom\n");
	}
	else if (whichPark == 69)
	{
		printf("Character is Currently in Epcot\n");
	}
	else if (whichPark == 67)
	{
		printf("Character is Currently in California Adventure\n");
	}
	else if (whichPark == 78)
	{
		printf("Character currently is not placed in any park\n");
	}
	return;
}

/*NAME:		ChangeWhichPark																*/
/*PURPOSE:	Validates that argument passed is valid and replaces whichPark with newPark	*/
/*INPUTS:	char newPark: a character representing a park location to replace whichPark	*/
/*OUTPUTS:	NONE																		*/
/*RETURNS:	true if newPark is M,S,A,E,C, or N, false if else							*/
bool Character::ChangeWhichPark(char newPark)
{
	/*If whichPark isn't one of the 'allowed' characters, returns false*/
	if (newPark != 77 && newPark != 83 && newPark != 65 && newPark != 69 && newPark != 67 && newPark != 78)
	{
		return false;
	}
	else /*else sets whichPark to the newPark*/
	{
		whichPark = newPark;
		return true;
	}
}



/*NAME:		GetName							*/
/*PURPOSE:	Returns private name data member*/
/*INPUTS:	NONE							*/
/*OUTPUTS:	NONE							*/
/*RETURNS:	name data member				*/
char* Character::GetName(void)
{
	return name;
}



/*NAME:		GetDate									*/
/*PURPOSE:	Returns creationDate private data member*/
/*INPUTS:	NONE									*/
/*OUTPUTS:	NONE									*/
/*RETURNS:	creationDate data member				*/
char* Character::GetDate(void)
{
	return creationDate;
}



/*NAME:		GetPark									*/
/*PURPOSE:	Returns whichPark private data member	*/
/*INPUTS:	NONE									*/
/*OUTPUTS:	NONE									*/
/*RETURNS:	whichPark data member					*/
char Character::GetPark(void)
{
	return whichPark;
}



/*NAME:		GetNumMovies							*/
/*PURPOSE:	Returns numMovies private data member	*/
/*INPUTS:	NONE									*/
/*OUTPUTS:	NONE									*/
/*RETURNS:	numMovies data member					*/
int Character::GetNumMovies(void)
{
	return numMovies;
}



/*NAME:		Character -- CONSTRUCTOR														*/
/*PURPOSE:	Validates and assigns values to data members of Character class					*/
/*INPUTS:	char* newName: Character Name, Char* newCreationDate: Date Character was created*/
/*			char newWhichPark : Character representing park Character is in					*/
/*			int newNumMovies: Integer value of movies Character has appeared in				*/
/*OUTPUTS:	NONE																			*/
/*RETURNS:	NONE																			*/
Character::Character(char* newName, char* newCreationDate, char newWhichPark, int newNumMovies) : whichPark(newWhichPark), numMovies(newNumMovies)
{
	char* leftDash	= NULL;
	char* rightDash = NULL;
	
	/*If the newName string is longer than 50*/
	if (strlen(newName) >= kCharacterNameLength)
	{
		newName[46] = '\0';		/*Truncates newName at 46 characters		*/
		strcat(newName, "...");	/*Appends the last 3 characters as elipses	*/
	}
	
	/*If whichPark isn't one of the 'allowed' characters, it sets it to N*/
	if (whichPark != 77 && whichPark != 83 && whichPark != 65 && whichPark != 69 && whichPark != 67 && whichPark != 78)
	{
		whichPark = 78;
	}

	/*If the nimber of movies is lower than zero, it's changed to the valid value 0 */
	if (numMovies < 0)
	{
		numMovies = 0;
	}

	leftDash  = strchr(newCreationDate, '-');	/*points to where the first dash is	*/
	rightDash = strrchr(newCreationDate, '-');	/*points to where the last dash is	*/

	/*If both dashes aren't in the right places*/
	if (leftDash != &newCreationDate[4] || rightDash != &newCreationDate[7])
	{
		strcpy(newCreationDate, " "); /*Makes newCreationDate blank*/
	}

	strcpy(name, newName);					/*Copies newName over name					*/
	strcpy(creationDate, newCreationDate);	/*Copies newCreationDate over creationDate	*/
}



/*NAME:		Character -- CONSTRUCTOR															*/
/*PURPOSE:	Overloaded Character Constructor that only takes name and date parameters,			*/
/*assigns defaults to others																	*/
/*INPUTS:	char* newName: Name of Character, char* newCreationDate: Date character was created	*/
/*OUTPUTS:	NONE																				*/
/*RETURNS:	NONE																				*/
Character::Character(char* newName, char* newCreationDate)
{
	char* leftDash	= NULL;
	char* rightDash = NULL;

	/*default values*/
	numMovies = 0; 
	whichPark = 78;

	/*If the newName string is longer than 50*/
	if (strlen(newName) >= kCharacterNameLength)
	{
		newName[kCharacterNameLength] = '\0';	/*Makes sure that newName is only 50 characters	*/
		strcat(newName - 4, "...");				/*Appends the last 3 characters as elipses		*/
	}

	leftDash = strchr(newCreationDate, '-');	/*points to where the first dash is	*/
	rightDash = strrchr(newCreationDate, '-');	/*points to where the last dash is	*/

	/*If both dashes aren't in the right places, or aren't present*/
	if (leftDash != &newCreationDate[4] || rightDash != &newCreationDate[7]) 
	{
		strcpy(newCreationDate, " "); /*Makes newCreationDate blank*/ 
	}

	strcpy(name, newName);					/*Copies newName over name					*/
	strcpy(creationDate, newCreationDate);	/*Copies newCreationDate over creationDate	*/
}



/*NAME:		Character -- DESTRUCTOR														*/
/*PURPOSE:	Destroys a character object, and prints the name of the object destroyed	*/
/*INPUTS:	NONE																		*/
/*OUTPUTS:	Prints "<character name> Destroyed"											*/
/*RETURNS:	NONE																		*/
Character::~Character()
{
	printf("%s Destroyed\n", name);
}
