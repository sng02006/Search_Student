#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Search_Student.h"

int main()
{
    FILE *fp, *fpr; //fp : student.txt file �о���� �뵵�� ���� ������ ����, fpr : input.txt file �о���� �뵵�� ���� ������ ����
    int i_size = 0; //input.txt�κ��� �Է¹��� �л��� ��
    int i = 0;
    char std_num_temp[11], name_temp[9]; //student.txt�κ��� �о�� �л����� �̸��� �ӽ÷� �����ص� ����
    char temp[11]; //input.txt�κ��� �о�� �л����� �������� �ӽ÷� �����ص� ����
    char *f_name; //���� �̸� ����

    S_INFO *s_info;

    //student.txt ����
    f_name = "student.txt";
    fp = fopen(f_name, "r");
    confirm_file(fp, f_name); //���� ������ name�� ���� file�� ������ err msg�� ������ִ� �Լ�

    //student.txt�� ����� �л����� �� ���ϱ�
    while (fscanf(fp, "%s %s", std_num_temp, name_temp) != EOF) //fscanf �Լ��� ������ ���� �����ϰų� ������ �߻��ϸ� EOF�� ��ȯ�Ѵ�
        size++;

    //size��ŭ ����ü ����
    s_info = createstds(size);

    printf("%s ������ �ҷ��Խ��ϴ�.\n\n", f_name);

    //student.txt �ݱ�
    fclose(fp);

    //input.txt ����
    f_name = "input.txt";
    fpr = fopen(f_name, "r");
    confirm_file(fpr, f_name);

    //input.txt�� ����� ������ ��
    while (fscanf(fpr, "%s", temp) != EOF)
        i_size++;

    rewind(fpr); //���� �����Ϳ� ����� ������ ���� �б�/���� ��ġ�� ������ ���� �������� �̵��Ѵ�.

    //input.txt�� ����� ������ ���õ� ������ �˻�
    for (i = 0; i < i_size; i++) {
        fscanf(fpr, "%s", temp);
        printf("search : %s\n", temp);
        searching(s_info, temp);
    }

    //linked list�� ����� ��� ���� cmd�� ���
    print_s_info(s_info);

    //input.txt �ݱ�
    fclose(fpr);

    //heap�� �Ҵ���� ���� �Ҵ� ����
    for(i = 0; i < size; i++){
        free(s_info->std_num);
        free(s_info->name);
    }

    free(s_info);

    return 0;
}
