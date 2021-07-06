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
        printf("1. 파일 읽기\n");
        printf("2. 추가\n");
        printf("3. 출력\n");
        printf("4. 검색\n");
        printf("5. 파일 쓰기\n");
        printf("6. 종료\n");
        printf("============\n");
        printf("정수값을 입력하시오: ");
        scanf("%d", &menu);
        getchar();
        switch (menu) {
        case 1:
            fp = fopen("book_list.txt", "r");
            if (fp == NULL) {
                printf("파일 오픈 실패\n");
                exit(1);
            }
            else {
                printf("파일 오픈 성공!\n");
            }
            break;
        case 2:
            write_title("book_list.txt", "제목");
            write_book("book_list.txt", "저자");
            write_book("book_list.txt", "출판사");
            printf("\n");
            break;
        case 3:
            read_book("book_list.txt");
            break;
        case 4:
            printf("제목을 입력하세요: ");
            gets_s(str, 100);
            search_book("book_list.txt", str);
            break;
        case 5:
            fp = fopen("book_list.txt", "w");
            if (fp == NULL) {
                printf("파일 오픈 실패\n");
                exit(1);
            }
            else {
                printf("파일 오픈 성공!(2)\n");
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
    printf("도서의 이름: ");
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
    char str[100] = "제목: ";
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
            printf("출판사는%s", tmp);
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    printf("없습니다.\n");
    return 0;
}