#include <stdio.h>

int main() {
    FILE* file;
    char name[50];
    int num;
    char ch;
    char str[50];

    // ���ļ�����д��
    if (fopen_s(&file, "file.txt", "w") != 0) {
        printf("�޷����ļ�����д�롣\n");
        return 1;
    }

    // д������
    fprintf(file, "Hello, World!\n");
    fputc('A', file);
    fputs("This is a test.", file);

    // �ر�д����ļ�
    fclose(file);

    // ���ļ����ж�ȡ
    if (fopen_s(&file, "file.txt", "r") != 0) {
        printf("�޷����ļ����ж�ȡ��\n");
        return 1;
    }

    // ��ȡ����
    fscanf_s(file, "%s", name, sizeof(name));
    printf("Name: %s\n", name);

    fscanf_s(file, " %c", &ch, sizeof(ch));
    printf("Character: %c\n", ch);

    fgets(str, sizeof(str), file);
    printf("String: %s", str);

    // �رն�ȡ���ļ�
    fclose(file);

    return 0;
}