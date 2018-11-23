#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Search_Student.h"

int main()
{
    FILE *fp, *fpr; //fp : student.txt file 읽어오기 용도의 파일 포인터 선언, fpr : input.txt file 읽어오기 용도의 파일 포인터 선언
    int i_size = 0; //input.txt로부터 입력받은 학생의 수
    int i = 0;
    char std_num_temp[11], name_temp[9]; //student.txt로부터 읽어온 학생들의 이름을 임시로 저장해둘 변수
    char temp[11]; //input.txt로부터 읽어온 학생들의 정보들을 임시로 저장해둘 변수
    char *f_name; //파일 이름 저장

    S_INFO *s_info;

    //student.txt 열기
    f_name = "student.txt";
    fp = fopen(f_name, "r");
    confirm_file(fp, f_name); //같은 폴더에 name을 가진 file이 없으면 err msg를 출력해주는 함수

    //student.txt에 저장된 학생들의 수 구하기
    while (fscanf(fp, "%s %s", std_num_temp, name_temp) != EOF) //fscanf 함수는 파일의 끝에 도착하거나 에러가 발생하면 EOF를 반환한다
        size++;

    //size만큼 구조체 생성
    s_info = createstds(size);

    printf("%s 파일을 불러왔습니다.\n\n", f_name);

    //student.txt 닫기
    fclose(fp);

    //input.txt 열기
    f_name = "input.txt";
    fpr = fopen(f_name, "r");
    confirm_file(fpr, f_name);

    //input.txt에 저장된 정보의 수
    while (fscanf(fpr, "%s", temp) != EOF)
        i_size++;

    rewind(fpr); //파일 포인터에 연결된 파일의 다음 읽기/쓰기 위치를 파일의 시작 지점으로 이동한다.

    //input.txt에 저장된 정보와 관련된 정보를 검색
    for (i = 0; i < i_size; i++) {
        fscanf(fpr, "%s", temp);
        printf("search : %s\n", temp);
        searching(s_info, temp);
    }

    //linked list에 저장된 모든 정보 cmd에 출력
    print_s_info(s_info);

    //input.txt 닫기
    fclose(fpr);

    //heap에 할당받은 정보 할당 해제
    for(i = 0; i < size; i++){
        free(s_info->std_num);
        free(s_info->name);
    }

    free(s_info);

    return 0;
}
