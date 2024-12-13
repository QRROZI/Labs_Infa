#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
/*Ф-я для считывания количества элементов в файле*/
int file_elem (const char* DBname){
FILE* f = fopen(DBname, "r");
int count = 0;
char buffer[256];
while (fgets(buffer, sizeof(buffer), f)){
count = count + 1;
}
fclose(f);
return count / 3;
}



/*Ф-я для добавления нового элемента*/
int add_elem(country **countries, int *size){
*countries = realloc(*countries, (*size + 1)*sizeof(country));
country new_country;
printf("Введите название страны, которую хотите добавить: ");
scanf("%s", new_country.country);
printf("Введите название столицы данной страны: ");
scanf("%s", new_country.capital);
printf("Введите имя Президента данной страны: ");
scanf("%s", new_country.president);
(*countries)[*size] = new_country;
(*size)++;
return 0;
}



/*Ф-я для удаления элемента*/
int delete_elem(country *countries, int *size, const char *name_to_delete){
for (int i = 0; i<*size; i++){
if (strcmp(countries[i].country, name_to_delete) == 0){
for (int j = i; j<*size -1; j++){
countries[j] = countries[j+1];
}
(*size)--;
break;
}
}
return 0;
}



/*Ф-я для редактирования элемента*/
int edit_elem(country *countries, int size, const char *name){
for (int i = 0; i<size; i++){
if (strcmp(countries[i].country, name)==0){
printf("Введите новую столицу страны %s: ", name);
scanf("%s", countries[i].capital);
printf("Введите нового президента страны %s: ", name);
scanf("%s", countries[i].president);
return 0;
}
}
printf("Страна не найдена в базе данных");
return 0;
}



/*Ф-я поиска*/
int search(country *countries, int size){
int choise2;
printf("Выберите, по какому критерию осуществлять поиск:\n");
printf("1 - Название страны\n");
printf("2 - Столица страны\n");
scanf("%i", &choise2);
char what_to_search[20];
if (choise2 != 1 && choise2 != 2){
printf("Ошибка. Принимаемые значения: 1-2.\n");
return 0;
}
if (choise2 == 1){
printf("Введите название страны для поиска: ");
scanf("%s", what_to_search);
for (int i = 0; i<size; i++){
if (strcmp(countries[i].country, what_to_search) == 0){
printf("Найден следующий элемент с названием страны '%s'\n", what_to_search);
printf("Страна: %s\n", what_to_search);
printf("Столица: %s\n", countries[i].capital);
printf("Президент: %s\n", countries[i].president);
}
}
}
if (choise2 == 2){
printf("Введите название столицы для поиска: ");
scanf("%s", what_to_search);
for (int i = 0; i<size; i++){
if (strcmp(countries[i].capital, what_to_search) == 0){
printf("Найден следующий элемент с названием столицы '%s'\n", what_to_search);
printf("Страна: %s\n", countries[i].country);
printf("Столица: %s\n", what_to_search);
printf("Президент: %s\n", countries[i].president);
}
}
}
return 0;
}



/*Ф-я выгрузки файл -> массив*/
int FileToMassive(const char* DBname, country *countries, int size){
FILE* f = fopen(DBname, "r");
for (int i = 0; i<size; i++){
fgets(countries[i].country, sizeof(countries[i].country), f);
countries[i].country[strcspn(countries[i].country, "\n")] = 0;
fgets(countries[i].capital, sizeof(countries[i].capital), f);
countries[i].capital[strcspn(countries[i].capital, "\n")] = 0;
fgets(countries[i].president, sizeof(countries[i].president), f);
countries[i].president[strcspn(countries[i].president, "\n")] = 0;
}
fclose(f);
return 0;
}



/*Ф-я выгрузки массив -> файл*/
int MassiveToFile(const char *DBname, country *countries, int size){
FILE *f = fopen(DBname, "w");
for (int i = 0; i<size; i++){
fprintf(f, "%s\n%s\n%s\n", countries[i].country, countries[i].capital, countries[i].president);
}
fclose(f);
return 0;
}
