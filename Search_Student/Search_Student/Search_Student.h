#ifndef Search_Student_H_INCLUDED
#define Search_Student_H_INCLUDED

//linked list�� ���� next pointer�� ������ ����ü�� ����
typedef struct student_infomation {
    char *std_num;
    char *name;
    struct student_infomation *next;
}S_INFO;

void confirm_file(FILE *file, char *file_name);
void print_s_info(S_INFO *print);
void searching(S_INFO *list, char temp[11]);
void add_list(char *info, S_INFO *list);
S_INFO *createstds(int k);
S_INFO *createstd(char std_num_temp[11], char name_temp[9]);

char ch = 'y';
int size = 0; //student.txt�κ��� �Է¹��� �л��� ��

//���� ������ file_name�� �������� ������ ����Ǵ� �Լ�
void confirm_file(FILE *file, char *file_name) {
    if (file == NULL) {
        printf("%s ������ ���� ������ �������� �ʽ��ϴ�.", file_name);
        exit(1);
    }

    return;
}

//k����ŭ linked list ����� �Լ�
S_INFO *createstds(int k) {
	FILE *fp;
	char std_num_temp[11], name_temp[9];
	char *f_name = "student.txt";
	int i = 0;

	S_INFO *head;
	S_INFO *ptr;
	S_INFO *newptr;

	fp = fopen(f_name, "r");
    confirm_file(fp, f_name);

    fscanf(fp, "%s %s", std_num_temp, name_temp); //fp�� ����� ������ �� ������ �о�´�

    //�Է¹��� ������ ����ü�� �����ϰ� �� �ּҸ� ptr�� head�� ����
	head = ptr = createstd(std_num_temp, name_temp); //�о�� ������ createstd()�� ���� S_INFO�� �ϳ� �����, �� S_INFO�� head�� ptr�� ����Ű���� �Ѵ�.

	//student.txt�� ����� ������ŭ ���� ����� ����ü���� ���� �й��� �̸� �� ���� ����ü�� �ּҸ� ����, S_INFO�� k-1�� �����
	for(i = 1; i < k; i++) {
        fscanf(fp, "%s %s", std_num_temp, name_temp);
        newptr = createstd(std_num_temp, name_temp);
        ptr->next = newptr;
        ptr = newptr;
	}

	fclose(fp);

	return head;
}

//malloc()�� ���� ���� �Ҵ� linked list ����
S_INFO *createstd(char std_num_temp[11], char name_temp[9]) {
	S_INFO *newptr;

    newptr = (S_INFO*)malloc(sizeof(S_INFO)); //sizeof(S_INFO) = 12

    newptr->std_num = (char*)malloc(sizeof(char)*strlen(std_num_temp)+1); //sizeof(char)*strlen(std_num_temp)+1 = 11
    newptr->name = (char*)malloc(sizeof(char)*strlen(name_temp)+1); //sizeof((char)*strlen(name_temp)+1) = 7

    if(newptr == NULL) {
        printf("����\n");
        exit(1);
    }

    strcpy(newptr->std_num, std_num_temp);
    strcpy(newptr->name, name_temp);
    newptr->next = NULL;

	return newptr;
}
//linked list�� ����� ��� ������ ���
void print_s_info(S_INFO *print) {
	S_INFO *ptr;

	ptr = print;

    //next�� ����� �������� �ּҰ� NULL�� �� ������ std_num�� name ����� �ݺ�
    while(ptr->next != NULL){
        printf("%s ", ptr->std_num);
        printf("%s\n", ptr->name);

        ptr = ptr->next;
    }
    //������ �� ����� ���� ����� ���� �ʾұ� ������ �� �� �� ���
    printf("%s ", ptr->std_num);
    printf("%s\n", ptr->name);

    return;
}

//student.txt���� �Է¹��� ������ type�� �Ǵ��ϰ� input.txt�� ���Ͽ� ��ġ�ϴ� ������ ������ ���
//������ add_list()�� ���� linked list�� ������ �߰�
void searching(S_INFO *list, char temp[11]) {
	char *a = NULL;
	char *b = NULL;
	char c[5] = "�й�";
	char d[5] = "�̸�";

    for (int i = 0 ; i < size; i++) {
        if (isdigit(temp[0])) {
            a = list->std_num;
            b = list->name;
        }
        else {
            a = list->name;
            b = list->std_num;
        }

        if(strcmp(temp, a) == 0) {
            ch = 'y';
            printf("result : %s\n\n", b);
            break;
        }
        else {
            ch = 'n';
            if (i == (size - 1))
                break;
            list = list->next;
        }
    }

    if (ch == 'n') {
		if (isdigit(temp[0])) {
			printf("��Ͽ� ���� %s�Դϴ�.\n\n", c);
		}
		else {
			printf("��Ͽ� ���� %s�Դϴ�.\n\n", d);
		}

        printf("%s�� ��Ͽ� �߰��մϴ�.\n", temp);
        add_list(temp, list);
    }

    return;
}

//student.txt�� ���� ������ linked list�� student.txt�� �߰�
void add_list(char *info, S_INFO *list) {
    FILE *fp;
    char *f_name;
    f_name = "student.txt";
    fp = fopen(f_name, "a");
    confirm_file(fp, f_name);

	char *a = NULL;
	char *b = NULL;
	char c[5] = "�й�";
	char d[5] = "�̸�";
    char add[11];
    char *add_std_num, *add_name;
    S_INFO *newptr;

    if (isdigit(info[0])) {
        a = info;
		printf("%s�� �Բ� �߰��� %s�� �Է��ϼ���.", c, d);
    }
    else {
        b = info;
		printf("%s�� �Բ� �߰��� %s�� �Է��ϼ���.", d, c);
    }
    scanf("%s", add);

	if (isdigit(info[0])) {
        b = add;
    }
    else {
        a = add;
    }

    add_std_num = (char*)malloc(sizeof(char)*strlen(a));
    add_name = (char*)malloc(sizeof(char)*strlen(b));

    strcpy(add_std_num, a);
    strcpy(add_name, b);

    printf("\nsearch : %s\nresult : %s\n\n", info, add);
    fprintf(fp, "%s ", add_std_num);
    fprintf(fp, "%s\n", add_name);

    newptr = createstd(add_std_num, add_name);
    list->next = newptr;
    list = newptr;

    size++;

    fclose(fp);

    return;
}

#endif // Search_Student_H_INCLUDED
