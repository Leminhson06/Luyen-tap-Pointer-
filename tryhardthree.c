#include <stdio.h>

void nhapChuoi(char *str) {
    char buffer[1000];
    printf("Nhap vao chuoi: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 
    *str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(*str, buffer);
}

void inChuoiDaoNguoc(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    int len = strlen(str);
    printf("Chuỗi đảo ngược: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

void demSoTu(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    printf("So luong tu trong chuoi: %d\n", count);
}

void soSanhChuoi(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi duoc nhap.\n");
        return;
    }
    char *str2;
    nhapChuoi(&str2);
    if (strlen(str2) > strlen(str)) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else if (strlen(str2) < strlen(str)) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else {
        printf("Chuoi moi co do dai nhu ban dau.\n");
    }
    free(str2);
}

void inHoaChuCai(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    char *p = str;
    while (*p) {
        *p = toupper(*p);
        p++;
    }
    printf("Chuoi sau khi in hoa: %s\n", str);
}

void themChuoi(char **str) {
    if (*str == NULL) {
        printf("Chua co chuoi nao duoc nhap.\n");
        return;
    }
    char *str2;
    nhapChuoi(&str2);
    *str = (char *)realloc(*str, (strlen(*str) + strlen(str2) + 1) * sizeof(char));
    strcat(*str, str2);
    free(str2);
    printf("Chuoi sau khi them: %s\n", *str);
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoiDaoNguoc(str);
                break;
            case 3:
                demSoTu(str);
                break;
            case 4:
                soSanhChuoi(str);
                break;
            case 5:
                inHoaChuCai(str);
                break;
            case 6:
                themChuoi(&str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.Vui long chon lai.\n");
        }
    } while (choice != 7);

    if (str != NULL) {
        free(str);
    }

    return 0;
}
