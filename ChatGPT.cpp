//#include <stdio.h>
//#include <stdlib.h>
//
//// Định nghĩa cấu trúc nút của danh sách liên kết đơn
//struct Node {
//    int data;
//    struct Node* next;
//};
//
//// Khởi tạo một danh sách liên kết đơn rỗng
//struct Node* head = NULL;
//
//// Thêm một phần tử vào đầu danh sách
//void insertAtBeginning(int data) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = data;
//    newNode->next = head;
//    head = newNode;
//}
//
//// Thêm một phần tử vào cuối danh sách
//void insertAtEnd(int data) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = data;
//    newNode->next = NULL;
//    if (head == NULL) {
//        head = newNode;
//        return;
//    }
//    struct Node* temp = head;
//    while (temp->next != NULL) {
//        temp = temp->next;
//    }
//    temp->next = newNode;
//}
//
//// Thêm một phần tử vào vị trí bất kì trong danh sách
//void insertAtPosition(int data, int position) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = data;
//    if (position == 1) {
//        newNode->next = head;
//        head = newNode;
//        return;
//    }
//    struct Node* temp = head;
//    for (int i = 1; i < position - 1 && temp != NULL; i++) {
//        temp = temp->next;
//    }
//    if (temp == NULL) {
//        printf("Invalid position\n");
//        return;
//    }
//    newNode->next = temp->next;
//    temp->next = newNode;
//}
//
//// Xóa phần tử ở đầu danh sách
//void deleteAtBeginning() {
//    if (head == NULL) {
//        printf("List is empty\n");
//        return;
//    }
//    struct Node* temp = head;
//    head = head->next;
//    free(temp);
//}
//
//// Xóa phần tử ở cuối danh sách
//void deleteAtEnd() {
//    if (head == NULL) {
//        printf("List is empty\n");
//        return;
//    }
//    if (head->next == NULL) {
//        free(head);
//        head = NULL;
//        return;
//    }
//    struct Node* temp = head;
//    while (temp->next->next != NULL) {
//        temp = temp->next;
//    }
//    free(temp->next);
//    temp->next = NULL;
//}
//
//// Xóa phần tử ở vị trí bất kì trong danh sách
//void deleteAtPosition(int position) {
//    if (head == NULL) {
//        printf("List is empty\n");
//        return;
//    }
//    struct Node* temp = head;
//    if (position == 1) {
//        head = head->next;
//        free(temp);
//        return;
//    }
//    for (int i = 1; temp != NULL && i < position - 1; i++) {
//        temp = temp->next;
//    }
//    if (temp == NULL || temp->next == NULL) {
//        printf("Invalid position\n");
//        return;
//    }
//    struct Node* nextNode = temp->next->next;
//    free(temp->next);
//    temp->next = nextNode;
//}
//
//// Tìm phần tử trong danh sách
//void search(int key) {
//    struct Node* temp = head;
//    int pos = 1;
//    while (temp != NULL) {
//        if (temp->data == key) {
//            printf("Element %d found at position %d\n", key, pos);
//            return;
//        }
//        temp = temp->next;
//        pos++;
//    }
//    printf("Element %d not found in the list\n", key);
//}
//
//// In ra danh sách
//void printList() {
//    struct Node* temp = head;
//    printf("List: ");
//    while (temp != NULL) {
//        printf("%d ", temp->data);
//        temp = temp->next;
//    }
//    printf("\n");
//}
//
//int main() {
//    int choice, data, position, key;
//
//    while (1) {
//        printf("\n-- MENU --\n");
//        printf("1. Thêm phần tử vào đầu danh sách\n");
//        printf("2. Thêm phần tử vào cuối danh sách\n");
//        printf("3. Thêm phần tử vào bất kì vị trí trong danh sách\n");
//        printf("4. Xóa phần tử ở đầu danh sách\n");
//        printf("5. Xóa phần tử ở cuối danh sách\n");
//        printf("6. Xóa phần tử ở bất kì vị trí trong danh sách\n");
//        printf("7. Tìm phần tử trong danh sách\n");
//        printf("8. In ra danh sách\n");
//        printf("0. Thoát\n");
//        printf("Chọn một số: ");
//        scanf("%d", &choice);
//
//        if (choice == 0) {
//            printf("Thoát khỏi chương trình\n");
//            break;
//        }
//        else if (choice == 1) {
//            printf("Nhập giá trị phần tử: ");
//            scanf("%d", &data);
//            insertAtBeginning(data);
//        }
//        else if (choice == 2) {
//            printf("Nhập giá trị phần tử: ");
//            scanf("%d", &data);
//            insertAtEnd(data);
//        }
//        else if (choice == 3) {
//            printf("Nhập giá trị phần tử: ");
//            scanf("%d", &data);
//            printf("Nhập vị trí: ");
//            scanf("%d", &position);
//            insertAtPosition(data, position);
//        }
//        else if (choice == 4) {
//            deleteAtBeginning();
//        }
//        else if (choice == 5) {
//            deleteAtEnd();
//        }
//        else if (choice == 6) {
//            printf("Nhập vị trí cần xóa: ");
//            scanf("%d", &position);
//            deleteAtPosition(position);
//        }
//        else if (choice == 7) {
//            printf("Nhập giá trị cần tìm: ");
//            scanf("%d", &key);
//            search(key);
//        }
//        else if (choice == 8) {
//            printList();
//        }
//        else {
//            printf("Lựa chọn không hợp lệ\n");
//        }
//    }
//
//    return 0;
//}
