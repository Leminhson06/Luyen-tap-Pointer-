#include <stdio.h>

void inputArray(int *arr, int *size) {
    printf("Nhap so pha tu cua mang: \n");
    scanf("%d", size);
    *arr = (int *)malloc(*size * sizeof(int));
    printf("Nhap cac pha tu cua mang: \n");
    for (int i = 0; i < *size; i++) {
        printf("Phan tu %d", i);
        scanf("%d", &(*arr)[i]);
    }
}

void displayArray (int *arr, int size) {
    if (size == 0) {
        printf("Mang trong.\n");
        return;
    }
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int sumArray (int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int findMaxElement(int *arr, int size) {
    if(size == 0) {
        printf("Mang trong, khong co gia tri lon nhat.\n");
        return -1;
    }
    int max = arr[0];
    for (int i = 1;i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        printf("%d", &choice);

        switch (choice) {
            case 1:
                if (arr != NULL) {
                    free(arr);
                }
                inputArray(&arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                printf("Do dai mang: %d\n", size);
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", sumArray(arr, size));
                break;
            case 5:
                int max = findMaxElement(arr, size);
                if (size != 0) {
                    printf("Phan tu lon nhat trong mang: %d\n", max);
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);
    if (arr != NULL) {
        free(arr);
    }

    return 0;
}

void insertArray(int *a, int *b) {
    int temp = *a;
    *b = *a;
    temp = *b;
    
