#ifndef Search_Student_H_INCLUDED
#define Search_Student_H_INCLUDED

//linked list를 위해 next pointer를 포함한 구조체를 선언
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
int size = 0; //student.txt로부터 입력받은 학생의 수

//같은 폴더에 file_name가 존재하지 않으면 실행되는 함수
void confirm_file(FILE *file, char *file_name) {
    if (file == NULL) {
        printf("%s 파일이 같은 폴더에 존재하지 않습니다.", file_name);
        exit(1);
    }

    return;
}

//k개만큼 linked list 만드는 함수
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

    fscanf(fp, "%s %s", std_num_temp, name_temp); //fp에 연결된 파일의 맨 윗줄을 읽어온다

    //입력받은 정보를 구조체에 저장하고 그 주소를 ptr과 head에 저장
	head = ptr = createstd(std_num_temp, name_temp); //읽어온 정보로 createstd()를 통해 S_INFO를 하나 만들고, 그 S_INFO를 head와 ptr이 가리키도록 한다.

	//student.txt에 저장된 정보만큼 새로 만드는 구조체마다 각각 학번과 이름 및 다음 구조체의 주소를 저장, S_INFO를 k-1개 만든다
	for(i = 1; i < k; i++) {
        fscanf(fp, "%s %s", std_num_temp, name_temp);
        newptr = createstd(std_num_temp, name_temp);
        ptr->next = newptr;
        ptr = newptr;
	}

	fclose(fp);

	return head;
}

//malloc()을 통한 동적 할당 linked list 생성
S_INFO *createstd(char std_num_temp[11], char name_temp[9]) {
	S_INFO *newptr;

    newptr = (S_INFO*)malloc(sizeof(S_INFO)); //sizeof(S_INFO) = 12

    newptr->std_num = (char*)malloc(sizeof(char)*strlen(std_num_temp)+1); //sizeof(char)*strlen(std_num_temp)+1 = 11
    newptr->name = (char*)malloc(sizeof(char)*strlen(name_temp)+1); //sizeof((char)*strlen(name_temp)+1) = 7

    if(newptr == NULL) {
        printf("에러\n");
        exit(1);
    }

    strcpy(newptr->std_num, std_num_temp);
    strcpy(newptr->name, name_temp);
    newptr->next = NULL;

	return newptr;
}
//linked list에 저장된 모든 정보를 출력
void print_s_info(S_INFO *print) {
	S_INFO *ptr;

	ptr = print;

    //next에 저장된 포인터의 주소가 NULL이 될 때까지 std_num와 name 출력을 반복
    while(ptr->next != NULL){
        printf("%s ", ptr->std_num);
        printf("%s\n", ptr->name);

        ptr = ptr->next;
    }
    //마지막 한 사람의 정보 출력이 되지 않았기 때문에 한 번 더 출력
    printf("%s ", ptr->std_num);
    printf("%s\n", ptr->name);

    return;
}

//student.txt에서 입력받은 정보의 type을 판단하고 input.txt와 비교하여 일치하는 정보가 있으면 출력
//없으면 add_list()를 통해 linked list의 정보를 추가
void searching(S_INFO *list, char temp[11]) {
	char *a = NULL;
	char *b = NULL;
	char c[5] = "학번";
	char d[5] = "이름";

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
			printf("목록에 없는 %s입니다.\n\n", c);
		}
		else {
			printf("목록에 없는 %s입니다.\n\n", d);
		}

        printf("%s를 목록에 추가합니다.\n", temp);
        add_list(temp, list);
    }

    return;
}

//student.txt에 없는 정보를 linked list와 student.txt에 추가
void add_list(char *info, S_INFO *list) {
    FILE *fp;
    char *f_name;
    f_name = "student.txt";
    fp = fopen(f_name, "a");
    confirm_file(fp, f_name);

	char *a = NULL;
	char *b = NULL;
	char c[5] = "학번";
	char d[5] = "이름";
    char add[11];
    char *add_std_num, *add_name;
    S_INFO *newptr;

    if (isdigit(info[0])) {
        a = info;
		printf("%s와 함께 추가할 %s를 입력하세요.", c, d);
    }
    else {
        b = info;
		printf("%s와 함께 추가할 %s를 입력하세요.", d, c);
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
