#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int main(){
const char* DBname = "DB.txt";

int size = file_elem(DBname);

country* countries = malloc(size * sizeof(country));
FileToMassive(DBname, countries, size);

int choise;
printf("Редактор БД 'Страны'\n");
printf("Выберите желаемое действие:\n");
printf("1 - Все элементы\n");
printf("2 - Поиск\n");
printf("3 - Добавить элемент\n");
printf("4 - Удалить элемент\n");
printf("5 - Редактировать элемент\n");

scanf("%i", &choise);

switch(choise){
case 1:
printf("Формат вывода: НАЗВАНИЕ, СТОЛИЦА, ПРЕЗИДЕНТ\n");
for (int i = 0; i<size; i++){
printf("%s, %s, %s.\n", countries[i].country, countries[i].capital, countries[i].president);
}
break;



case 2:
search(countries, size);
break;


case 3:
add_elem(&countries, &size);
MassiveToFile(DBname, countries, size);
break;


case 4:
char name_to_delete[20];
printf("Введите название страны, которую необходимо удалить из базы данных: ");
scanf("%s", name_to_delete);
delete_elem(countries, &size, name_to_delete);
MassiveToFile(DBname, countries, size);
break;


case 5:
char name_to_edit[20];
printf("Введите название страны, данные о которой необходимо изменить: ");
scanf("%s", name_to_edit);
edit_elem(countries, size, name_to_edit);
MassiveToFile(DBname, countries, size);
break;


default:
printf("Ошибка. Принимаемые значения: 1-5.");
break;
}

free(countries);
return 0;
}
