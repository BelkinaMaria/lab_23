#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80

char s[MAX_LEN];

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Belkina Maria.\n");
	printf("ЛР23 Задача 3.\n");

	FILE* fin;
	fin = fopen("C:\\Users\\casey\\OneDrive\\Рабочий стол\\универ\\основыАлггоритмизацииИПрограммирования\\23\\files\\in3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден.");
		return;
	}

	FILE* fout;
	fout = fopen("C:\\Users\\casey\\OneDrive\\Рабочий стол\\универ\\основыАлггоритмизацииИПрограммирования\\23\\files\\out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден.");
		return;
	}

	bool flag;
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			flag = FALSE;
			for (int i = 0; s[i] != '\0'; i++) {
				if (isalpha(s[i])) {
					flag = TRUE;
				}
				if (flag and s[i + 1] == '\0') {
					s[i] = '#';
					//s[i + 1] = '\n';
					//s[i + 2] += '\0';
				}
			}
			fprintf(fout, "%s\n", s);
			printf(">>%s<<\n", s);
		}
	}

	fclose(fin);
	fclose(fout);

	printf("ЛР23, Задача 1, FINISH.\n");

}