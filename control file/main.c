#include <stdio.h>

int main() {
    FILE* file;
    char name[50];
    int num;
    char ch;
    char str[50];

    // 打开文件进行写入
    if (fopen_s(&file, "file.txt", "w") != 0) {
        printf("无法打开文件进行写入。\n");
        return 1;
    }

    // 写入数据
    fprintf(file, "Hello, World!\n");
    fputc('A', file);
    fputs("This is a test.", file);

    // 关闭写入的文件
    fclose(file);

    // 打开文件进行读取
    if (fopen_s(&file, "file.txt", "r") != 0) {
        printf("无法打开文件进行读取。\n");
        return 1;
    }

    // 读取数据
    fscanf_s(file, "%s", name, sizeof(name));
    printf("Name: %s\n", name);

    fscanf_s(file, " %c", &ch, 1);
    printf("Character: %c\n", ch);

    fgets(str, sizeof(str), file);
    printf("String: %s", str);

    // 关闭读取的文件
    fclose(file);

    return 0;
}

//#include<stdio.h>
//
//int main(void)
//{
//	FILE* file = fopen("test.text", "w");
//	if (file == NULL)
//	{
//		printf("default!!!");
//		return 1;
//	}
//	fprintf(file, "Hello world!");
//	
//	fclose(file);
//
//	FILE* fp = fopen("test.text", "r");
//	char arr[50];
//	fscanf_s(fp, "%s", arr, sizeof(arr));
//	printf("all thing is well\narr = %s", arr);
//	return 0;
//}