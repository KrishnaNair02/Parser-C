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
#include "Register.h"

#define NUMREGIS 8

static Regi RegisterLookUp[NUMREGIS] = {
	{"01000", "$t0", 8}, {"01001", "$t1", 9}, {"01010", "$t2", 10}, 
	{"01011", "$t3", 11}, {"10000", "$s0", 16}, {"10001", "$s1", 17}, 
	{"10010", "$s2", 18}, {"10011", "$s3", 19}
};

const Regi* GetRegi(const char* const word)
{
	for (int i = 0; i < NUMREGIS; i++)
	{
		if (strcmp(word, RegisterLookUp[i].reg) == 0)
		{
			return &RegisterLookUp[i];
		}
	}
	return NULL;
}
	 
		

