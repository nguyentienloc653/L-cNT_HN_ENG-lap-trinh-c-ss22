#include<stdio.h>
#include<string.h>
struct Book{
	char bookId[50];
	char nameBook[100];
	char tacGia[50];
	float giaSach;
	char theLoai[50];
};
void soLuongVaThongTinSach(struct Book book[], int *n);
void hienThiThongTinSach(struct Book book[], int n);
void themSach(struct Book book[], int *n);
void xoaSach(struct Book book[], int *n);
void capNhatSach(struct Book book[], int n);
void tangDan(struct Book book[], int n);
void timSach(struct Book book[], int n);
int main(){
	struct Book book[100];
	int choice;
	int n=0;
	do{
		printf("MENU\n");
		printf("1. Nhap so luong va thong tin sach\n");
		printf("2. Hien thi thong tin sach\n");
		printf("3. Them sach vao vi tri\n");
		printf("4. Xoa sach theo ma sach\n");
		printf("5. Cap nhat thong tin sach theo ma sach\n");
		printf("6. Sap xep sach theo gia (tang/giam)\n");
		printf("7. Tim kiem theo ten sach\n");
		printf("8. Thoat\n\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				soLuongVaThongTinSach(book, &n);
				break;
			}
			case 2:{
				hienThiThongTinSach(book, n);
				break;
			}
			case 3:{
				themSach(book, &n);
				break;
			}
			case 4:{
				xoaSach(book, &n);
				break;
			}
			case 5:{
				capNhatSach(book, n);
				break;
			}
			case 6:{
				int choose=0;
				printf("1. Sap xep tang dan\n");
				printf("2. Sap xep giam dan\n");
				printf("Lua chon cua ban: ");
				scanf("%d", &choose);
				if(choose==1){
					tangDan(book, n);
				}
				if(choose==2){
					giamDan(book, n);
				}
				break;
			}
			case 7:{
				timSach(book, n);
				break;
			}
		}
	}while(choice!=8);
}
void soLuongVaThongTinSach(struct Book book[], int *n){
	printf("Nhap so luong sach: ");
	scanf("%d", n);
	fflush(stdin);
	for(int i=0; i<*n; i++){
		printf("\nMoi nhap thong tin quyen sach thu %d\n", i+1);
		printf("Id sach: ");
		fgets(book[i].bookId, sizeof(book[i].bookId), stdin);
		fflush(stdin);
		
		printf("Ten sach: ");
		fgets(book[i].nameBook, sizeof(book[i].nameBook), stdin);
		fflush(stdin);
		
		printf("Tac gia: ");
		fgets(book[i].tacGia, sizeof(book[i].tacGia), stdin);
		fflush(stdin);
		
		printf("Gia tien: ");
		scanf("%f", &book[i].giaSach);
		getchar();
		
		printf("The loai: ");
		fgets(book[i].theLoai, sizeof(book[i].theLoai), stdin);
		fflush(stdin);
	}
}
void hienThiThongTinSach(struct Book book[], int n){
	printf("Thong tin sach:\n");
	for(int i=0; i<n; i++){
		printf("Id sach:%s", book[i].bookId);
		printf("Ten sach:%s", book[i].nameBook);
		printf("Tac gia sach:%s", book[i].tacGia);
		printf("Gia tien sach:%.2f\n", book[i].giaSach);
		printf("The loai:%s\n", book[i].theLoai);
	}
}
void themSach(struct Book book[], int *n){
	struct Book newBook;
	printf("Hay nhap thong tin cua sach moi:\n");
	printf("Id sach moi: ");
	scanf("%s", newBook.bookId);
	
	printf("Ten sach moi: ");
	scanf("%s", newBook.nameBook);
	
	printf("Ten tac gia cua sach moi: ");
	scanf("%s", newBook.tacGia);
	
	printf("Gia tien sach moi: ");
	scanf("%f", &newBook.giaSach);
	
	printf("The loai sach moi: ");
	scanf("%s", newBook.theLoai);
	
	book[*n]=newBook;
	(*n)++;
	printf("Danh sach sau khi them sach moi:\n");
	for(int i=0; i<*n; i++){
		printf("Id sach:%s\n", book[i].bookId);
		printf("Ten sach:%s\n", book[i].nameBook);
		printf("Tac gia sach:%s\n", book[i].tacGia);
		printf("Gia tien sach:%f\n", book[i].giaSach);
		printf("The loai:%s\n", book[i].theLoai);
	}
}
void xoaSach(struct Book book[], int *n){
	char xoa[50];
	printf("Nhap id sach muon xoa: ");
	fgets(xoa, sizeof(xoa), stdin);
	fflush(stdin);
	for(int i=0; i<*n; i++){
		if(strcmp(book[i].bookId, xoa)==0){
			for(int j=i; j<*n-1; j++){
				book[j]=book[j+1];
			}
			(*n)--;
			printf("Danh sach sach sau khi xoa:\n");
			for(int i=0; i<*n; i++){
				printf("Id sach:%s\n", book[i].bookId);
				printf("Ten sach:%s\n", book[i].nameBook);
				printf("Tac gia sach:%s\n", book[i].tacGia);
				printf("Gia tien sach:%f\n", book[i].giaSach);
				printf("The loai:%s\n", book[i].theLoai);
			}
		}
	}
}
void capNhatSach(struct Book book[], int n){
	char update[50];
	int count=0;
	printf("Nhap id sach muon cap nhat: ");
	scanf("%s", update);
	for(int i=0; i<n; i++){
		if(strcmp(book[i].bookId, update)==0){
			count=1;
			printf("Cap nhat thong tin sach:\n");
			printf("Ten sach: ");
			fgets(book[i].nameBook, sizeof(book[i].nameBook), stdin);
			printf("Ten tac gia: ");
			fgets(book[i].tacGia, sizeof(book[i].tacGia), stdin);
			printf("Gia sach: ");
			scanf("%f", &book[i].giaSach);
			printf("The loai sach: ");
			fgets(book[i].theLoai, sizeof(book[i].theLoai), stdin);
			printf("Danh sach sach sau khi cap nhat:\n");
			for(int i=0; i<n; i++){
				printf("Id sach:%s\n", book[i].bookId);
				printf("Ten sach:%s\n", book[i].nameBook);
				printf("Tac gia sach:%s\n", book[i].tacGia);
				printf("Gia tien sach:%f\n", book[i].giaSach);
				printf("The loai:%s\n", book[i].theLoai);
			}
		}
	}
	if(count==0){
		printf("Id khong ton tai\n");
	}
}
void tangDan(struct Book book[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(book[i].giaSach>book[j].giaSach){
				struct Book temp=book[i];
				book[i]=book[j];
				book[j]=temp;
			}
		}
	}
	printf("Danh sach sau khi sap xep tang dan:\n");
	for(int i=0; i<n; i++){
		printf("Id sach:%s\n", book[i].bookId);
		printf("Ten sach:%s\n", book[i].nameBook);
		printf("Tac gia sach:%s\n", book[i].tacGia);
		printf("Gia tien sach:%f\n", book[i].giaSach);
		printf("The loai:%s\n", book[i].theLoai);
	}
}
void giamDan(struct Book book[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(book[i].giaSach<book[j].giaSach){
				struct Book temp=book[i];
				book[i]=book[j];
				book[j]=temp;
			}
		}
	}
	printf("Danh sach sau khi sap xep giam dan:\n");
	for(int i=0; i<n; i++){
		printf("Id sach:%s\n", book[i].bookId);
		printf("Ten sach:%s\n", book[i].nameBook);
		printf("Tac gia sach:%s\n", book[i].tacGia);
		printf("Gia tien sach:%f\n", book[i].giaSach);
		printf("The loai:%s\n", book[i].theLoai);
	}
}
void timSach(struct Book book[], int n){
	char tenSach[100];
	int count=0;
	printf("Nhap ten sach ban muon tim: ");
	fgets(tenSach, sizeof(tenSach), stdin);
	for(int i=0; i<n; i++){
		if(strstr(book[i].nameBook, tenSach)!= NULL){
		count=1;
		printf("Id sach:%s\n", book[i].bookId);
		printf("Ten sach:%s\n", book[i].nameBook);
		printf("Tac gia sach:%s\n", book[i].tacGia);
		printf("Gia tien sach:%f\n", book[i].giaSach);
		printf("The loai:%s\n", book[i].theLoai);
		}
	}
	if(count==0){
		printf("Ten sach khong ton tai\n");
	}
}
