#include<stdio.h>
int main(){
	int arr[100], n = 0, choice;
	do{
		printf("\nMENU\n");
		printf("1.Nhap so phan tu va gia tri cho mang\n");
		printf("2.In ra gia tri cac phan tu theo dang (arr[0] = 1, arr[1] = 5 …)\n");
		printf("3.Ðem so luong cac so hoan hao co trong mang. Biet so hoan hao la so co tong cac uoc bang chinh no\n");
		printf("4.Tim gia tri nho thu hai trong mang, khong duoc sap xep mang\n");
		printf("5.Them mot phan tu vao vi tri dau tien trong mang\n");
		printf("6.Xoa phan tu tai mot vi tri cu the\n");
		printf("7.Sap xep mamg theo thu tu giam dan\n");
		printf("8.Cho nguoi dung nhap vao mot phan tu, tim kiem xem phan tu do co ton tai trong mang hay khong\n");
		printf("9.Sap xep lai mang và hien thi ra toàn bo phan tu có trong mang sao cho toàn bo so le dung truoc, so chan dung sau\n");
		printf("10.Ðao nguoc thu tu cua cac phan tu co trong mang và hien thi ra toan bo phan tu co trong mang theo dang (arr[0] = 1 - le, arr[1] = 2 - chan …)\n");
		printf("11.Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
			printf("Nhap so phan tu: ");
				scanf("%d",&n);
				if(n<=0 || n>100){
					printf("So luong phan tu khong hop le !\n");
					break;
				}
				for(int i = 0; i < n; i++){
					printf("Phan tu tai vi tri %d: ",i);
					scanf("%d",&arr[i]);
				}
				break;
			}
			case 2:{
				printf("Cac phan tu trong mang: ");
				for(int i = 0; i < n; i++){
					printf("arr[%d] = %d\t",i ,arr[i]);
				}
				break;
			}
			case 3:{
				int count = 0;
                for (int i = 0; i < n; i++) {
                    int sum = 0;
                    for (int j = 1; j < arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            sum += j;
                        }
                    }
                    if (sum == arr[i]) {
                        count++;
                    }
                }
                printf("So luong so hoan hao trong mang: %d\n", count);
                break;
            }
			case 4:{
				if (n < 2) {
                    printf("Mang khong du phan tu de tim gia tri nho thu 2.\n");
                    break;
                }
                int min1 = arr[0], min2 = __INT_MAX__;
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min1) {
                        min2 = min1;
                        min1 = arr[i];
                    } else if (arr[i] > min1 && arr[i] < min2) {
                        min2 = arr[i];
                    }
                }
                if (min2 == __INT_MAX__) {
                    printf("Khong co gia tri nho thu 2 trong mang.\n");
                } else {
                    printf("Gia tri nho thu 2 trong mang la: %d\n", min2);
                }
                break;
            }
			case 5:{
				if (n >= 100) {
                    printf("Mang da day, khong the them phan tu moi.\n");
                }
                int value, position;
                printf("Nhap vi tri can them (0 - %d): ", n);
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                for (int i = n; i > position; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[position] = value;
                n++;
				break;
			}
			case 6:{
				int index;
				printf("Nhap vao vi tri muon xoa trong mang: ");
				scanf("%d",&index);
				if(index<=0 || index>100){
					printf("Vi tri khong hop le");
					break;
				}
				for(int i=index;i<n-1;i++){
					arr[i]=arr[i+1];
				}
				n--;
				break;
			}
			case 7:{
				for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] < arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da sap xep giam dan: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
				break;
			}
			case 8:{
				int value, left = 0, right = n - 1, mid, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                while (left <= right) {
                    mid = (left + right) / 2;
                    if (arr[mid] == value) {
                        found = 1;
                        printf("Gia tri %d nam o vi tri: %d\n", value, mid);
                        break;
                    } else if (arr[mid] < value) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay gia tri %d trong mang.\n", value);
                }
                break;
            }
			case 9:{
				
            }
			case 10:{
				
            }
			case 11:{
				printf("Thoat chuong trinh.\n");
				break;
			}
			default:
                printf("Lua chon khong hop le!\n");
                break;
		}
	} while ( choice != 11);
	return 0;
}  
