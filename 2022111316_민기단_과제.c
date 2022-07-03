#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BOOKS 10

int main(void)
{
	FILE* fp;
	int i, input, count = 0;
	char name[30], author[30], pub[30], search[30];

	char menu[6][10] = { "���� �б�", "�߰�","���","�˻�","���� ����","����" };
	char lib[BOOKS][3][30];

	while (1)  //�Է� ���� ���� ���� 6(����)�� �ƴ� �̻� ���ѷ���
	{
		printf("===============\n");  //�ʱ�޴�ȭ��
		for (i = 0;i < 6;i++)
		{
			printf("%d. %s\n", i + 1, menu[i]);
		}
		printf("===============\n");
		printf("�������� �Է��Ͻÿ�: ");
		scanf("%d", &input);

		if (input == 1)  //���� �б�
		{
			if ((fp = fopen("book.txt", "r")) == NULL)
			{
				fprintf(stderr, "å ������ �� �� �����ϴ�.\n");
				exit(1);
			}
			else
				printf("���� ���� ����!\n");

		}

		if (input == 2)  //�߰�
		{
			printf("\n������ �̸�: ");
			scanf("%s", &name);
			printf("����: ");
			scanf("%s", author);
			printf("���ǻ�: ");
			scanf("%s", &pub);
			printf("\n");

			for (i = 0;i < BOOKS;i++)
			{
				strcpy(lib[count][0], name);
				strcpy(lib[count][1], author);
				strcpy(lib[count][2], pub);
			}
			count++;
		}

		if (input == 3)  //���
		{
			if ((fp = fopen("book.txt", "r")) == NULL)
			{
				fprintf(stderr, "å ������ �� �� �����ϴ�.\n");
				exit(1);
			}
			while (!feof(fp))
			{
				fscanf(fp, "%s %s %s", name, author, pub);
				printf("����: %s\n����: %s\n���ǻ�: %s\n", name, author, pub);
			}
			fclose(fp);
		}

		if (input == 4)  //�˻�
		{
			printf("����: ");
			scanf("%s", search);

			if ((fp = fopen("book.txt", "r")) == NULL)
			{
				fprintf(stderr, "å ������ �� �� �����ϴ�.\n");
				exit(1);
			}
			while (!feof(fp))
			{
				fscanf(fp, "%s %s %s", name, author, pub);
				if (strcmp(name, search) == 0)
				{
					printf("���ǻ�� %s\n", pub);
				}
			}
			fclose(fp);
		}

		if (input == 5)  //���� ����
		{
			i = 0;
			fp = fopen("book.txt", "a");
			if (fp == NULL)
			{
				printf("å ����� �� �� �����ϴ�.\n");
				exit(0);
			}

			while (1)
			{
				if (i == count)
					break;
				fprintf(fp, " %s %s %s", lib[i][0], lib[i][1], lib[i][2]);  //book.txt ���Ͽ� ���
				i++;
			}
			fclose(fp);
			printf("���� ���� ����!(%d)\n",count);
		}

		if (input == 6)  //����
			break;
	}
	return 0;
}