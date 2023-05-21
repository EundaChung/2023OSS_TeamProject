#include "todo.h"

//main
int main(void) {
  ToDo t[100];
  int count = loadData(t);
  int index = count;
  int menu;

  while(1){
    menu = selectMenu();
    if(menu == 0) {
      printf("Bye!\n");
      break;
    }
    
    else if (menu == 1) { //���� ��ȸ
      if(count > 0) {
        listTodo(t, index);
      }
    }
    
    else if(menu == 2){ //���� �߰�
      count += 1;
      addTodo(&t[index++]);

    }
    else if (menu == 3){ //���� ����
      updateTodo(t);

    }
    else if (menu == 4){ //���� ����
      //int no = selectDataNo(t, index);
      // int deleteok;
      // printf("������ �����Ͻðڽ��ϱ�?(����:1)");
      // scanf("%d", &deleteok);
      // if (deleteok == 1){
      //   if (&t[no -1] == NULL) count--;
      // }
    }
            
    else if (menu == 5){ //���� ����
      saveData(t, index);

    }
    else if(menu == 6){ //���� �ҷ�����
      loadData(t);
        
    }

    else if (menu == 7){ //���Ϻ� ���� �߰�
      //addTodoByDay(t, &index, &count);
    }
    else if (menu == 8){ //�Ϸ� ǥ�� ���
      int no = selectDataNo(t, index);
      int completeok;
      printf("�Ϸ��ϼ̳���? (�Ϸ�: 1, ���: 0)");
      scanf("%d", &completeok);
      if(completeok == 1){
        completeTodo(&t[no-1]);
        printf("=> ���� �Ϸ�!\n");
      }
      else{
        printf("=> ��ҵ�! \n");
      }
      

    }

  }
}