#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("������� �����.\n");
	printf("��23. ������ 1.\n");

	// ������� ����
	FILE* fin = fopen("C:\\Users\\casey\\OneDrive\\������� ����\\������\\��������������������������������������\\23\\files\\in2.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("C:\\Users\\casey\\OneDrive\\������� ����\\������\\��������������������������������������\\23\\files\\out2.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}

	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			for (int i = 0; s[i] != '\0'; i++) {
				s[i] = toupper(s[i]);

			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}

	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23. ������ 1. FINISH\n");
}
