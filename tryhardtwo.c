#include <stdio.h>

void nhapChuoi(char **str) {
    char buffer[1000];
    printf("Nhập vào chuỗi: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Loại bỏ ký tự newline ở cuối chuỗi
    *str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(*str, buffer);
}

void inChuoi(char *str) {
    if (str == NULL) {
        printf("Chưa có chuỗi nào được nhập.\n");
    } else {
        printf("Chuỗi đã nhập: %s\n", str);
    }
}

void demChuCai(char *str) {
    if (str == NULL) {
        printf("Chưa có chuỗi nào được nhập.\n");
        return;
    }
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    printf("Số lượng chữ cái trong chuỗi: %d\n", count);
}

void demChuSo(char *str) {
    if (str == NULL) {
        printf("Chưa có chuỗi nào được nhập.\n");
        return;
    }
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    printf("Số lượng chữ số trong chuỗi: %d\n", count);
}

void demKyTuDacBiet(char *str) {
    if (str == NULL) {
        printf("Chưa có chuỗi nào được nhập.\n");
        return;
    }
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    printf("Số lượng ký tự đặc biệt trong chuỗi: %d\n", count);
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhập vào chuỗi\n");
        printf("2. In ra chuỗi\n");
        printf("3. Đếm số lượng chữ cái trong chuỗi và in ra\n");
        printf("4. Đếm số lượng chữ số trong chuỗi và in ra\n");
        printf("5. Đếm số lượng ký tự đặc biệt trong chuỗi và in ra\n");
        printf("6. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                demChuCai(str);
                break;
            case 4:
                demChuSo(str);
                break;
            case 5:
                demKyTuDacBiet(str);
                break;
            case 6:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 6);

    if (str != NULL) {
        free(str);
    }

    return 0;
}