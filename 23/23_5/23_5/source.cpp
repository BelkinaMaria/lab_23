#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


char filenameIn[] = "C:\\Users\\casey\\OneDrive\\������� ����\\������\\��������������������������������������\\23\\files\\in5.txt";
char filenameHTML[] = "C:\\Users\\casey\\OneDrive\\������� ����\\������\\��������������������������������������\\23\\files\\out5_txt.html";

void main() {
	printf("BEGIN!!!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������� ���� ��������� (�������)
	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filenameIn);
		return;
	}

	// ������� HTML ���� (�������� ����)  
	FILE* fout = fopen(filenameHTML, "wt");
	if (fout == NULL) {
		// ��������� ����� ������� �������� ������� ���� 
		fclose(fin);
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filenameHTML);
		return;
	}


	// ������� � �������� ���� ��������� HTML ���������
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = 	\"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");

	int ch;
	while ((ch = getc(fin)) != EOF) {
		// � HTML ���� ��������� ������ ��� ����������� 
		// ������ "��� ����"
		fprintf(fout, "%c", ch);
		//printf("%c", ch); //

		// ���� � ������ ��� ������ ����� ������ � 
		// � HTML ��������� ��� <BR> - ����� ������
		if (ch == '\n') {
			fprintf(fout, "<br>");
		//	printf("<br>");
		}
	}

	// ������� � HTML ����������� ���� ��������� HTML
	fprintf(fout, "</body>");
	fprintf(fout, "</html>");

	// ��������� ���� � �������
	fclose(fin);

	// ��������� HTML ���� 
	fclose(fout);
	printf("END!!!\n");

}
