#include "rgr.h"
#include <stdio.h>
#include <stdlib.h>



unsigned int my_strlen(const char* str_)
{
	unsigned int len = 0;
	for (; str_[len] != '\0'; len++);
	return len;
}

result find_occurrences(char* s1, char* s2)
{
	result answer;
	answer.amount = 0;
	unsigned int s1_len = my_strlen(s1);
	unsigned int s2_len = my_strlen(s2);

	answer.where = calloc((s1_len / s2_len) + 1, sizeof(int));
	if (answer.where == NULL) { printf("memmory allocation error(answer.where)"); return answer; }

	int len1 = 0;
	int len2 = 0;
	while (s1[len1] != '0') {
		len1++;
	}
	while (s2[len2] != '0') {
		len2++;
	}
	

	for (int i = 0; i <= len1 - len2; ++i) {
		int found = 1;
		for (int j = 0; j < len2; ++j) {
			if (s1[i + j] != s2[j]) {
				found = 0;
				break;
			}
		}
		if (found == 1) {
			answer.where[answer.amount] = i;
			answer.amount++;
			i += len2 - 1;
		}
		
	}
	for (int i = 1; i < answer.amount; ++i)
	{
		if (answer.where[i] == 0)
		{
			void* kostil = realloc(answer.where, i + 1 * (sizeof(int)));
			break;
		}
	}
	return answer;
}

result* rgr(char* name)
{
	FILE* file = fopen(name, "r");
	if (file == NULL) { printf("cant open file"); return NULL; }
	char lastsimb = getc(file);

	char space;
	int counter = 0;
	while ((space = fgetc(file)) != EOF)												//счётчик кол-ва пробелов
		if (space == ' ') ++counter;

	result* answers = malloc(((counter + 1) / 2) * sizeof(result));						// колво пробелов +1 пополам - колво пар слов
	if (answers == NULL) { printf("memmory allocation error(answers)"); return NULL; }
	

	while (lastsimb != EOF)
	{
		int counter1 = 0;
		int counter2 = 0;
		char simb;
		for (simb = getc(file); simb != ' '; simb = getc(file))							//узнавание длинны 1ого слова 
			counter1++;
		
		
		for (simb = lastsimb = getc(file); simb != ' '; simb = lastsimb = getc(file))   //узнавание длинны 2ого слова
			counter2++;

		char* s1 = malloc(sizeof(char) * counter1);										//выделение памяти для первого слова из пары
			if (s1 == NULL) { printf("s1 memmory allocation error"); return NULL; }

		char* s2 = malloc(sizeof(char) * counter2);										//выделение памяти для 2ого слова из пары
			if (s2 == NULL) { printf("s2 memmory allocation error"); return NULL; }

		
			for (int i = 0; fscanf(file, "%s %s", s1, s2) == 2;++i) {
				answers[i] = find_occurrences(s1, s2);
			}

		
	}
	fclose(file);

	return answers;
}

	












