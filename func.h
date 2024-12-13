#ifndef FUNC_H
#define FUNC_H
typedef struct{
char country[20];
char capital[20];
char president[30];
}country;

int FileToMassive(const char *DBname, country *countries, int size);
int MassiveToFile(const char *DBname, country *countries, int size);
int file_elem(const char *DBname);
int add_elem(country **countries, int *size);
int delete_elem(country *countries, int *size, const char *name_to_delete);
int edit_elem(country *countries, int size, const char *name);
int search(country *countries, int size);
#endif
