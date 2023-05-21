//todo.h
#include <stdio.h>

typedef struct {
    char title[100]; //ex) OSS Lab11
    char deadline[20]; //ex) 2023-05-08
    char day[10]; // ex) Mon
    int hrs; //ex) 4(���� �ҿ� �ð�)
    int check; // ex) 0, 1(�Ϸ��ϸ� 1 �Է¹޾Ƽ� ��ǥ��)
} ToDo;

//����
int selectMenu();
int completeTodo(ToDo *t);
void saveData(ToDo *t, int count);
int loadData(ToDo *t);
int addTodo(ToDo *t); //���� �߰�
int updateTodo(ToDo *t); //���� ����: return addTodo()

//����
int selectDataNo(ToDo *t, int count);
int deleteTodo(ToDo *t); //���� ����
void todoRead(ToDo t); //���� ����Ʈ ���
int listTodo(ToDo *t, int count);

