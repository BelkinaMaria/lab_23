#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80

char s[MAX_LEN];

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Belkina Maria.\n");
	printf("ЛР23 Задача 6.\n");

	FILE* fin;
	fin = fopen("C:\\Users\\casey\\OneDrive\\Рабочий стол\\универ\\основыАлггоритмизацииИПрограммирования\\23\\files\\in7.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден.");
		return;
	}

	FILE* fout;
	fout = fopen("C:\\Users\\casey\\OneDrive\\Рабочий стол\\универ\\основыАлггоритмизацииИПрограммирования\\23\\files\\out7.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден.");
		return;
	}

	char arr[] = "QWRTPSDFGHJKLZXCVBNMqwrtpsdfghjklzxcvbnm";

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				for (int j = 0; j < strlen(arr); j++) {
					if (s[i] == arr[j])
						s[i] = '&';
				}
			}
			fprintf(fout, "%s\n", s);
			printf(">>%s<<", s);
		}
	}

	fclose(fin);
	fclose(fout);

	printf("ЛР23, Задача 1, FINISH.\n");

}