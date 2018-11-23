# Search_Student
----------------
## 개요
------
이 프로그램은 학번을 입력하면 이름을, 이름을 입력하면 학번을 출력해주는 프로그램입니다.
학번과 이름으로 만들어진 구조체로 linked list를 만들어 학생들의 학번과 이름이 입력되어있는 student.txt로부터 정보를 저장합니다.
검색하고자하는 이름 또는 학번이 입력되어있는 input.txt를 불러와서 student.txt로부터 불러온 데이터와 비교하여 그에 맞는 학번 또는 이름으로 변환된 정보를 cmd에 출력하는 것이 목적입니다.
만약 input.txt에 있는 정보가 student.txt에 있는 정보와 일치하지 않는 경우가 없으면 이름 또는 학번을 키보드를 통해 추가로 입력받아서 student.txt에 출력해줍니다.

## 함수
------
- void confirm_file(FILE *file, char *file_name)
: source와 같은 폴더 또는 지정된 경로에 파일이 존재하지 않는 경우, “file_name 파일이 같은 폴더에 존재하지 않습니다.“라는 문구를 출력해주는 함수입니다.

- void print_s_info(S_INFO *print)
: 구조체로 된 linked list에 저장된 학번과 이름을 차례로 모두 출력하는 함수입니다.

- void searching(S_INFO *list, char temp[11]);
: student.txt로부터 main함수의 구조체로 된 linked list에 입력받은 정보와 input.txt로부터 main함수의 temp에 입력받은 정보를 비교해서 input.txt으로부터 학번이 입력되었으면, student.txt로부터 그 학번과 일치하는 이름을, input.txt으로부터 이름이 입력되었으면 student.txt로부터 그 이름과 일치하는 학번을 cmd에 출력해주는 함수입니다. 만약 student.txt에 없는 이름이나 학번이 input.txt로부터 입력이 되면 add_list();로 linked list와 student.txt 파일 마지막에 추가시켜줍니다.

- void add_list(char *info, S_INFO *list);
: student.txt에 없는 이름이나 학번이 input.txt로부터 입력되었을 때, 그에 맞는 정보를 키보드를 통해 변수 add에 새로 입력받고 linked list와 student.txt 파일의 마지막에 추가시켜줍니다. 함수 종료 전, student.txt에 저장된 총 학생의 숫자를 나타내는 전역 변수 size의 값을 +1 증가시켜줍니다.

- S_INFO *createstds(int k);
: *createstd();를 통해 student.txt로부터 정보를 하나씩 linked list를 k개만큼 생성해주는 함수입니다. k개만큼 생성 후, head의 주소 값을 반환해줍니다.

- S_INFO *createstd(char std_num_temp[11], char name_temp[9]);
: *createstds()로부터 받아온 정보를 malloc()을 통해 동적 할당받은 주소에 하나씩 입력합니다.