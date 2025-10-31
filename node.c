#include <stdio.h>
#include <stdlib.h>
struct node {
  int serial_number;
  int volume;
  char *ch;
  struct node *next;
};
// 链表node查找函数
struct node *LinkList_Find(struct node *head, int target, int number) {
  struct node *ptr, *ptr_next;
  ptr = head;
  while (ptr->serial_number != target) {
    if (ptr->serial_number == number - 1) {
      printf("not find");
      return NULL;
    }
    printf("%d is searchinging...\n", ptr->serial_number);
    ptr = ptr->next;
  }
  printf("find ok\n");
  printf("current node serial_number:%d\n", ptr->serial_number);
  return ptr;
}

// 动态内存分配链表函数
struct node *CreateList_Funcation(int number) {
  struct node *ptr_next, *ptr,
      *head = (struct node *)malloc(sizeof(struct node));
  head->serial_number = 0;
  // 动态内存分配链表
  for (int i = 1; i < number; i++) {
    if (i == 1) {
      ptr = (struct node *)malloc(sizeof(struct node));
      while (ptr == NULL) {
        ptr = (struct node *)malloc(sizeof(struct node));
      }
      ptr->serial_number = i;
      head->next = ptr;
    } else {
      ptr_next = (struct node *)malloc(sizeof(struct node));
      while (ptr_next == NULL) {
        ptr_next = (struct node *)malloc(sizeof(struct node));
        printf("not good\n");
      }
      ptr_next->serial_number = i;
      printf("now is%d\n", i);
      ptr->next = ptr_next;
      ptr = ptr_next;
    }
  }
  return head;
}
int main() {
  int number, number_find;
  printf("please input number:");
  scanf("%d", &number);
  struct node *head = CreateList_Funcation(number);
  printf("now have %dnodes of list\n", number);
  char ch;
  printf("find nodes?(y/n)");
  scanf(" %c", &ch);
  if (ch == 'y') {
    struct node *node_find;
    printf("input node's serial number:");
    // 移除多余的getchar()，避免干扰输入（原因见下文）
    scanf(" %d", &number_find);
    node_find =
        LinkList_Find(head, number_find, number); // 假设函数仍保留number参数

    // 关键：检查node_find是否有效
    if (node_find != NULL) {
      printf("第%d node:\n", node_find->serial_number); // 单数node更合理
      printf("volume:%d\n", node_find->volume);
      printf("ch_ptr:%p\n", node_find->ch);
      printf("next node ptr:%p", node_find->next); // 补充换行符，输出更整洁
    } else {
      printf("无法访问不存在的节点\n");
      return 0;
    }

  } else {
    return 0;
  }
}
