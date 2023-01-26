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
#include "ASMParser.h"

/***  Add include directives for here as needed.  ***/

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Functi.h"
#include "Register.h"
#include "Opc.h"
#include "ConvertByte.h"

ParseResult* parseASM(const char* const pASM) {
	
    char* curr = pASM;
    char* mainPtr;
    ParseResult* toReturn = (ParseResult*) calloc(500, sizeof(ParseResult));
    toReturn->ASMInstruction = (char*) calloc(500, sizeof(char*));
    strcpy(toReturn->ASMInstruction, pASM);
    mainPtr = strtok(curr, " ,\t()");
    toReturn->Mnemonic = (char*) calloc(500, sizeof(char*));
    strcpy(toReturn->Mnemonic, mainPtr);
    if (strcmp(toReturn->Mnemonic, "add") == 0 || strcmp(toReturn->Mnemonic, "mul") == 0 || strcmp(toReturn->Mnemonic, "sub") == 0) 
    {
		toReturn->Funct = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->Funct, GetFuncti(toReturn->Mnemonic)->functi);
		toReturn->Opcode = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->Opcode, GetOpc(toReturn->Mnemonic)->opcode);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rdName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rdName, mainPtr);
		toReturn->rd = GetRegi(toReturn->rdName)->regiField;
		toReturn->RD = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RD, GetRegi(toReturn->rdName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rsName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rsName, mainPtr);
		toReturn->rs = GetRegi(toReturn->rsName)->regiField;
		toReturn->RS = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RS, GetRegi(toReturn->rsName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rtName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rtName, mainPtr);
		toReturn->rt = GetRegi(toReturn->rtName)->regiField;
		toReturn->RT = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RT, GetRegi(toReturn->rtName)->regiBit);
		toReturn->IMM = NULL;
		toReturn->Imm = 0;
	}
	else if (strcmp(toReturn->Mnemonic, "addi") == 0) 
	{
		toReturn->Funct = NULL;
		toReturn->Opcode = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->Opcode, GetOpc(toReturn->Mnemonic)->opcode);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rdName = NULL;
		toReturn->rd = 255;
		toReturn->RD = NULL;
		toReturn->rtName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rtName, mainPtr);
		toReturn->rt = GetRegi(toReturn->rtName)->regiField;
		toReturn->RT = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RT, GetRegi(toReturn->rtName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rsName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rsName, mainPtr);
		toReturn->rs = GetRegi(toReturn->rsName)->regiField;
		toReturn->RS = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RS, GetRegi(toReturn->rsName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->IMM = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->IMM, ConvertByte(atoi(mainPtr)));
		toReturn->Imm = atoi(mainPtr);
	}
	else if (strcmp(toReturn->Mnemonic, "beq") == 0)
	{
		toReturn->Funct = NULL;
		toReturn->Opcode = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->Opcode, GetOpc(toReturn->Mnemonic)->opcode);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rdName = NULL;
		toReturn->rd = 255;
		toReturn->RD = NULL;
		toReturn->rsName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rsName, mainPtr);
		toReturn->rs = GetRegi(toReturn->rsName)->regiField;
		toReturn->RS = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RS, GetRegi(toReturn->rsName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rtName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rtName, mainPtr);
		toReturn->rt = GetRegi(toReturn->rtName)->regiField;
		toReturn->RT = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RT, GetRegi(toReturn->rtName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->IMM = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->IMM, ConvertByte(atoi(mainPtr)));
		toReturn->Imm = atoi(mainPtr);
	}
	else if (strcmp(toReturn->Mnemonic, "lui") == 0) 
	{
		toReturn->Funct = NULL;
		toReturn->Opcode = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->Opcode, GetOpc(toReturn->Mnemonic)->opcode);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rdName = NULL;
		toReturn->rd = 255;
		toReturn->RD = NULL;
		toReturn->rsName = NULL;
		toReturn->rs = 0;
		toReturn->RS = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RS, "00000");
		toReturn->rtName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rtName, mainPtr);
		toReturn->rt = GetRegi(toReturn->rtName)->regiField;
		toReturn->RT = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RT, GetRegi(toReturn->rtName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->IMM = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->IMM, ConvertByte(atoi(mainPtr)));
		toReturn->Imm = atoi(mainPtr);
	}
	else
	{
		toReturn->Funct = NULL;
		toReturn->Opcode = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->Opcode, GetOpc(toReturn->Mnemonic)->opcode);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rdName = NULL;
		toReturn->rd = 255;
		toReturn->RD = NULL;
		toReturn->rtName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rtName, mainPtr);
		toReturn->rt = GetRegi(toReturn->rtName)->regiField;
		toReturn->RT = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RT, GetRegi(toReturn->rtName)->regiBit);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->IMM = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->IMM, ConvertByte(atoi(mainPtr)));
		toReturn->Imm = atoi(mainPtr);
		mainPtr = strtok(NULL, " ,\t()");
		toReturn->rsName = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->rsName, mainPtr);
		toReturn->rs = GetRegi(toReturn->rsName)->regiField;
		toReturn->RS = (char*) calloc(500, sizeof(char*));
		strcpy(toReturn->RS, GetRegi(toReturn->rsName)->regiBit);
	}
	return toReturn;
}
