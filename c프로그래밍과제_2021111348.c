#include<stdio.h>
#include<string.h>
void write_title(char filename[], char str1[]);
void write_book(char filename[], char str1[]);
void read_book(char filename[]);
void search_book(char filename[], char bookname[]);

int main(void) {
    FILE* fp = fopen("book_list.txt", "a");
    int menu, ret;
    char str[100];
    fclose(fp);
    while (1) {
        printf("============\n");
        printf("1. ���� �б�\n");
        printf("2. �߰�\n");
        printf("3. ���\n");
        printf("4. �˻�\n");
        printf("5. ���� ����\n");
        printf("6. ����\n");
        printf("============\n");
        printf("�������� �Է��Ͻÿ�: ");
        scanf("%d", &menu);
        getchar();
        switch (menu) {
        case 1:
            fp = fopen("book_list.txt", "r");
            if (fp == NULL) {
                printf("���� ���� ����\n");
                exit(1);
            }
            else {
                printf("���� ���� ����!\n");
            }
            break;
        case 2:
            write_title("book_list.txt", "����");
            write_book("book_list.txt", "����");
            write_book("book_list.txt", "���ǻ�");
            printf("\n");
            break;
        case 3:
            read_book("book_list.txt");
            break;
        case 4:
            printf("������ �Է��ϼ���: ");
            gets_s(str, 100);
            search_book("book_list.txt", str);
            break;
        case 5:
            fp = fopen("book_list.txt", "w");
            if (fp == NULL) {
                printf("���� ���� ����\n");
                exit(1);
            }
            else {
                printf("���� ���� ����!(2)\n");
            }
            break;
        case 6:
            fclose(fp);
            return 0;
        }
    }
    return 0;
}

void write_title(char filename[], char str1[]) {
    char str[100];
    FILE* fp = fopen(filename, "a");
    printf("������ �̸�: ");
    gets_s(str, 100);
    fprintf(fp, "%s: %s\n", str1, str);
    fclose(fp);
}
void write_book(char filename[], char str1[]) {
    char str[100];
    FILE* fp = fopen(filename, "a");
    printf("%s: ", str1);
    gets_s(str, 100);
    fprintf(fp, "%s: %s\n", str1, str);
    fclose(fp);
}
void read_book(char filename[]) {
    char str[100];
    int ret;
    FILE* fp = fopen(filename, "r");
    while (!feof(fp)) {
        ret = fgets(str, 100, fp);
        if (ret == 0) break;
        printf("%s", str);
    }
    fclose(fp);
}

void search_book(char filename[], char bookname[]) {
    char str[100] = "����: ";
    strcat(str, bookname);
    char tmp[100];
    int ret;
    FILE* fp = fopen(filename, "r");
    while (!feof(fp)) {
        fgets(tmp, 100, fp);
        if (strstr(tmp, str)) {
            fgets(tmp, 100, fp);
            fseek(fp, 7L, SEEK_CUR);
            fgets(tmp, 100, fp);
            printf("���ǻ��%s", tmp);
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    printf("�����ϴ�.\n");
    return 0;
}