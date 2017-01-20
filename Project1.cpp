/* Project1.cpp
 * 
 * Name: Miguel Salinas
 * EE312 Fall 2016
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent 
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */
#define LETTER 		1
#define BSIZE		2048

void toLowerCase(char[]);
void determineWord(char[]);
int isLetter(char);
int compStrings(char[], char[]);
int findWord(char[], char[], int);
int compareWords(char[],char[]);
int findWordDic(char[], char[], int);

void spellCheck(char article[], char dictionary[]) {
	char senBuffer[BSIZE];
	char dicBuffer[BSIZE];
	int index = 0;

	toLowerCase(article);
	toLowerCase(dictionary);

	while(article[index] != '\0'){
		int found = 0;
		int indexDic = 0;	
		index = findWord(article,senBuffer, index);


		while(dictionary[indexDic] != '\0'){
			indexDic = findWordDic(dictionary,dicBuffer, indexDic);
			if(compareWords(senBuffer, dicBuffer) == 1 ){
				found++;
				break;			
			}

		}
		if(found == 0 && senBuffer[0] != '\0' )
			printf("%s\n",senBuffer);
	}

}

int findWord(char array[], char buffer[], int index){
	int b =0;
	while(isLetter(array[index]) == 0)
		index++;

	while(isLetter(array[index])){
		buffer[b] = array[index];
		b++;
		index++;
	}
	if(b == 0)
		return ++index;

	if (b < 2) 
		buffer[0] = '\0';
	else 
		buffer[b] = '\0';

	return ++index;
}

int findWordDic(char array[], char buffer[], int index){
	int b =0;
	while(isLetter(array[index]) == 0)
		index++;

	while(array[index] != '\n'){
		buffer[b] = array[index];
		b++;
		index++;
	}
	if(b == 0)
		return ++index;

	if (b < 2) 
		buffer[0] = '\0';
	else 
		buffer[b] = '\0';

	return ++index;
}
/* isLetter will be used to determine is a character is a "letter" as defined by the project
 * it will count letters punctiation and as true and numbers and space  as false 
 */
int isLetter(char current){
	if(current <= 'z'&& current >= 'a')
		return LETTER;
	return 0;

}


/*This just makes the array lowercase */	
void toLowerCase(char array[]){
	int i = 0;
	while(array[i] != '\0'){
		if(array[i] >= 'A' && array[i] <='Z')
			array[i] = array[i] + ('z'-'Z');
		i++;
	}
}


int compareWords(char first[], char second[]){
	int index = 0;
	while((first[index] != '\0')&& (second[index]) != '\0'){
		if(first[index] != second[index]){
			return 0;}
		index++;
	}
	if((first[index] == '\0') && (second[index] == '\0') && index != 0){	
		return 1;	
	}
	return 0;
}

