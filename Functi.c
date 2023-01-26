//  On my honor: 
// 
//  - I have not discussed the C language code in my program with 
// anyone other than my instructor or the teaching assistants 
// assigned to this course. 
// 
//  - I have not used C language code obtained from another student, 
// the Internet, or any other unauthorized source, either modified 
// or unmodified. 
// 
//  - If any C language code or documentation used in my program 
// was obtained from an authorized source, such as a text book or 
// course notes, that has been clearly noted with a proper citation 
// in the comments of my program. 
// 
//  - I have not designed this program in such a way as to defeat or 
// interfere with the normal operation of the grading code. 
// 
// Krishna Nair
// krishnanair


#include <stdio.h>
#include "Functi.h"

#define MNEMOS 3

static Functi FunctiLookUp[MNEMOS] = {
	{"100000", "add"}, {"000010", "mul"}, {"100010", "sub"}
};

const Functi* GetFuncti(const char* const word)
{
	for (int i = 0; i < MNEMOS; i++)
	{
		if (strcmp(word, FunctiLookUp[i].mnemo) == 0)
		{
			return &FunctiLookUp[i];
		}
	}
	return NULL;
}

