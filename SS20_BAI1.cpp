#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[20];
    char title[100];
    char author[100];
    float price;
    char category[50];
} Book;

void inputBooks(Book books[], int *n) {
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin cho sach thu %d:\n", i + 1);
        printf("Ma sach: "); scanf("%s", books[i].id);
        printf("Ten sach: "); scanf(" %[^\n]%*c", books[i].title);
        printf("Tac gia: "); scanf(" %[^\n]%*c", books[i].author);
        printf("Gia tien: "); scanf("%f", &books[i].price);
        printf("The loai: "); scanf(" %[^\n]%*c", books[i].category);
    }
}

void displayBooks(Book books[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %s\n", books[i].id);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
        printf("\n");
    }
}

void addBookAtPosition(Book books[], int *n, int position) {
    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        books[i] = books[i - 1];
    }
    printf("Nhap thong tin cho sach moi:\n");
    printf("Ma sach: "); scanf("%s", books[position].id);
    printf("Ten sach: "); scanf(" %[^\n]%*c", books[position].title);
    printf("Tac gia: "); scanf(" %[^\n]%*c", books[position].author);
    printf("Gia tien: "); scanf("%f", &books[position].price);
    printf("The loai: "); scanf(" %[^\n]%*c", books[position].category);
    (*n)++;
}

void deleteBookById(Book books[], int *n, const char *id) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp(books[i].id, id) == 0) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ma sach %s.\n", id);
    }
}

void updateBookById(Book books[], int n, const char *id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].id, id) == 0) {
            found = 1;
            printf("Nhap thong tin moi cho sach co ma %s:\n", id);
            printf("Ma sach: "); scanf("%s", books[i].id);
            printf("Ten sach: "); scanf(" %[^\n]%*c", books[i].title);
            printf("Tac gia: "); scanf(" %[^\n]%*c", books[i].author);
            printf("Gia tien: "); scanf("%f", &books[i].price);
            printf("The loai: "); scanf(" %[^\n]%*c", books[i].category);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ma sach %s.\n", id);
    }
}

void sortBooksByPrice(Book books[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if ((ascending && books[j].price > books[j + 1].price) ||
                (!ascending && books[j].price < books[j + 1].price)) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void searchBooksByTitle(Book books[], int n, const char *title) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(books[i].title, title) != NULL) {
            found = 1;
            printf("Ma sach: %s\n", books[i].id);
            printf("Ten sach: %s\n", books[i].title);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia tien: %.2f\n", books[i].price);
            printf("The loai: %s\n", books[i].category);
            printf("\n");
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ten chua '%s'.\n", title);
    }
}

int main() {
    Book books[100];
    int n = 0;
    int choice;

    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang/giam).\n");
        printf("7. Tim kiem sach theo ten sach.\n");
        printf("8. Thoat.\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBooks(books, &n);
                break;
            case 2:
                displayBooks(books, n);
                break;
            case 3: {
                int position;
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                addBookAtPosition(books, &n, position);
                break;
            }
            case 4: {
                char id[20];
                printf("Nhap ma sach can xoa: ");
                scanf("%s", id);
                deleteBookById(books, &n, id);
                break;
            }
            case 5: {
                char id[20];
                printf("Nhap ma sach can cap nhat: ");
                scanf("%s", id);
                updateBookById(books, n, id);
                break;
            }
        
            case 7: {
                char title[100];
                printf("Nhap ten sach can tim: ");
                scanf(" %[^\n]%*c", title);
                searchBooksByTitle(books, n, title);
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

