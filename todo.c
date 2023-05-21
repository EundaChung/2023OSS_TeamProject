#include "todo.h"
#include <string.h>

int selectMenu(){
    int menu;
    printf("\n\n *** 1Jung *** \n");
    printf("0. ����\n\n");
    printf("1. ���� ��ȸ\n"); //���� ����Ʈ ��� + �����Ϸ� üũǥ��
    printf("2. ���� �߰�\n");
    printf("3. ���� ����\n");
    printf("4. ���� ����\n");
    printf("5. ���� ����\n");
    printf("6. ���� �ҷ�����\n");
    printf("7. ���� �߰�(���Ϻ�)\n");
    printf("8. ���� �Ϸ�\n");
    printf("Select Menu: ");
    scanf("%d", &menu);
    return menu;   
}

//���� �Ϸ� ���
int completeTodo(ToDo *t){
  t->check = 1;
  return 1;
}

//���� �߰� ���
int addTodo(ToDo *t){
  int repeat;
  char repeatDeadline[20];
  int repeatDays;
  printf("1. �ܼ� �߰� 2. �ݺ� �߰� >> ");
  scanf("%d", &repeat);
  if(repeat == 2){
    printf("last date to add Todo(format: 20XX-XX-XX)>> "); //�ݺ� ������ �߰��� ������ ��¥
    scanf("%s", repeatDeadline);

    printf("Title: ");
    scanf("%s", t->title);
    printf("Deadline(format: after * days): ");
    scanf("%d", &repeatDays);
    printf("Estimated time to complete(hrs): ");
    scanf("%d", &t->hrs);
    printf("=> ���ο� �ݺ� ������ �߰��Ǿ����ϴ�!");
    return 1;

  }
  else{
    printf("Title: ");
    getchar();
    scanf("%[^\ns]", t->title);
    getchar();
    printf("Deadline(format: 20XX-XX-XX): ");
    scanf("%s", t->deadline);
    printf("Day(Mon, Tues, Wed, Thurs, Fri, Sat, Sun): ");
    scanf("%s", t->day);
    printf("Estimated time to complete(hrs): ");
    scanf("%d", &t->hrs);
    printf("=> ���ο� ������ �߰��Ǿ����ϴ�!");
    return 1;
  }
}
//�̿ϼ�
void saveData(ToDo *t, int count){
    FILE *fp;
    char filename[20];
    printf("������ ���� �̸�: ");
    scanf("%s", filename);

    fp = fopen(filename, "wt");
    printf("\nNo Title Deadline Day Hours Finish\n");
    
    for(int i=0; i<count; i++){
        if(t[i].hrs == -1) continue;
        fprintf(fp, "%2d %s %s %s %d %d\n", i+1, t[i].title, t[i].deadline, t[i].day, t[i].hrs, t[i].check);
    }
    fclose(fp);
    printf("=> %s ���Ͽ� �����! \n",filename);

}
//�̿ϼ�
int loadData(ToDo *t){
    int i, count = 0;
    FILE *fp;
    char filename[20];
    printf("�ҷ��� ���� �̸�: ");
    scanf("%s", filename);
    
    fp=fopen(filename, "rt");
    if(fp == NULL){
        printf("=> ���� ����! \n");
        return 0;
    }
    for(i=0; i<100; i++){
        fscanf(fp, "%s", t[i].title);
        if(feof(fp)) break;
        fscanf(fp, "%s", t[i].deadline);
        fscanf(fp, "%s", t[i].day);
        fscanf(fp, "%d", &t[i].hrs);
    }
    fclose(fp);
    printf("=> %s ���� �ε� ����!\n", filename);
    return i; //�� ��� ����ź�� ����

}

int updateTodo(ToDo *t){
    return addTodo(t);
    }

int selectDataNo(ToDo *t, int count){
    int no;
    listTodo(t, count);
    printf("��ȣ��?");
    scanf("%d", &no);
    return no;
}

// //���� ���� ���
// int deleteTodo(ToDo *t){
//     t->check = -1;
//     return 1;
// }


//���� ���� ����Ʈ ��� ���
void todoRead(ToDo t){
    printf("%s  %s  %s  %d %d\n", t.title, t.deadline, t.day, t.hrs);
}

//deadline ���� ���
void readDeadline(ToDo t){
  printf("%s  %s  %s  %d %d\n", t.title, t.hrs);
}

void todoByDeadline(ToDo t){
  printf("\n%s %s\n", t.deadline, t.day);
}


int listTodo(ToDo *t, int count){
    printf("\nNo    Title   Deadline    Day     Hours   Finish\n");
    printf("====================================================\n");
    for(int i=0; i<count; i++){
        if(t[i].check == -1) continue;
        printf("%2d    ", i+1);
        todoRead(t[i]);
        //�����Ϸ� üũǥ��
        if(t[i].check == 1){ 
            printf("  ��\n");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    return 1;
}

//���� �߰� ��� (���Ϻ���)
// void addTodoByDay(ToDo *t[], int *index, int *count) {
//   int dayMenu;
//   printf("������ �����ϼ���:\n");
//   printf("1. ������\n");
//   printf("2. ȭ����\n");
//   printf("3. ������\n");
//   printf("4. �����\n");
//   printf("5. �ݿ���\n");
//   printf("6. �����\n");
//   printf("7. �Ͽ���\n");
//   printf("Select Day: ");
//   scanf("%d", &dayMenu);

//   if (dayMenu < 1 || dayMenu > 7) {
//     printf("�߸��� �����Դϴ�.\n");
//     return;
//   }
//     char day[10];
//   switch (dayMenu) {
//     case 1:
//       strcpy(day, "Mon");
//       break;
//     case 2:
//       strcpy(day, "Tue");
//       break;
//     case 3:
//       strcpy(day, "Wed");
//       break;
//     case 4:
//       strcpy(day, "Thu");
//       break;
//     case 5:
//       strcpy(day, "Fri");
//       break;
//     case 6:
//       strcpy(day, "Sat");
//       break;
//     case 7:
//       strcpy(day, "Sun");
//       break;
//   }

//   printf("Title: ");
//   scanf("%s", t[*index]->title);
//   printf("Deadline (format: 20XX-XX-XX): ");
//   scanf("%s", t[*index]->deadline);
//   strcpy(t[*index]->day, day);
//   printf("Estimated time to complete (hrs): ");
//   scanf("%d", &t[*index]->hrs);
//   t[*index]->check = 0;

//   printf("=> ���ο� ������ �߰��Ǿ����ϴ�!\n");
//   (*index)++;
//   (*count)++;
// }