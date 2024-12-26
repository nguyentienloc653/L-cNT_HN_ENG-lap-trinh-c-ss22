#include<stdio.h>
struct SinhVien{
	int id;
	char fullName[50];
	int age;
};
//
void writeFile(struct SinhVien sinhVien[], int n);
int readFile(struct SinhVien sinhVien[]);
void addSinhVien(struct SinhVien sinhVien[], int *n);
void inDanhSach(struct SinhVien sinhVien[], int n);
void suaSinhVien(struct SinhVien sinhVien[], int n);
void xoaSinhVien(struct SinhVien sinhVien[], int *n);
void timKiem(struct SinhVien sinhVien[], int n);
void sapXep(struct SinhVien sinhVien[], int n);
int main(){
	struct SinhVien sinhVien[100];
	int choice;
	int n=readFile(sinhVien);
	do{
		printf("MENU\n");
		printf("1. In danh sach sinh vien\n");
		printf("2. Them sinh vien\n");
		printf("3. Sua thong tin sinh vien\n");
		printf("4. Xoa sinh vien\n");
		printf("5. Tim kiem sinh vien\n");
		printf("6. Sap xep danh sach sinh vien\n");
		printf("7. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				inDanhSach(sinhVien, n);
				break;
			case 2:
				addSinhVien(sinhVien, &n);
				break;
			case 3:
				suaSinhVien(sinhVien, n);
				break;
			case 4:
				xoaSinhVien(sinhVien, &n);
				break;
			case 5:
				timKiem(sinhVien, n);
				break;
			case 6:
				sapXep(sinhVien, n);
				break;
		}
	}while(choice!=7);
}
void writeFile(struct SinhVien sinhVien[], int n){
	FILE *file;
	file=fopen("sinhvien.bin", "wb");
	if(file==NULL){
		printf("Khong mo duoc file\n");
		return 1;
	}
	fwrite(sinhVien, sizeof(struct SinhVien), n, file);
	fclose(file);
}
int readFile(struct SinhVien sinhVien[]){
	FILE *file;
	file=fopen("sinhvien.bin", "rb");
	int n=0;
	while(fread(&sinhVien[n], sizeof(struct SinhVien), 1, file)){
		n++;
	}
	fclose(file);
	return n;
}
void addSinhVien(struct SinhVien sinhVien[], int *n){
	struct SinhVien sinhVienMoi;
	printf("Ban hay nhap thong tin sinh vien moi:\n");
	printf("Id sinh vien moi: ");
	scanf("%d", &sinhVienMoi.id);
	fflush(stdin);
	
	printf("Ho va ten cua sinh vien moi: ");
	fgets(sinhVienMoi.fullName, sizeof(sinhVienMoi.fullName), stdin);
	
	printf("Tuoi cua sinh vien moi: ");
	scanf("%d", &sinhVienMoi.age);
	fflush(stdin);
	
	sinhVien[*n]=sinhVienMoi;
	(*n)++;
	writeFile(sinhVien, *n);
}
void inDanhSach(struct SinhVien sinhVien[], int n){
	printf("Danh sach sinh vien:\n");
	for(int i=0; i<n; i++){
		printf("\nID sinh vien: %d\n", sinhVien[i].id);
		printf("Ho va ten sinh vien: %s", sinhVien[i].fullName);
		printf("Tuoi sinh vien: %d\n", sinhVien[i].age);
	}
}
//
void suaSinhVien(struct SinhVien sinhVien[], int n){
	int sua;
	printf("Ban hay nhap ID sinh vien muon sua: ");
	scanf("%d",&sua);
	for(int i=0; i<n; i++){
		if(sinhVien[i].id==sua){
			printf("Nhap ten sinh vien moi: ");
			getchar();
			fgets(sinhVien[i].fullName, sizeof(sinhVien[i].fullName), stdin);
			fflush(stdin);
			
			printf("Nhap tuoi sinh vien moi: ");
			scanf("%d", &sinhVien[i].age);
			
			writeFile(sinhVien, n);
			printf("Thong tin da duoc cap nhat thanh cong\n");
			return;
		}
	}
	printf("Khong tim thay sinh vien");
}
void xoaSinhVien(struct SinhVien sinhVien[], int *n){
	int xoa;
	printf("Ban hay nhap ID sinh vien muon sua: ");
	scanf("%d",&xoa);
	for(int i=0; i<*n; i++){
		if(sinhVien[i].id==xoa){
			for(int j=i; j<*n; j++){
				sinhVien[j]=sinhVien[j+1];
			}
			(*n)--;
			writeFile(sinhVien, *n);
			printf("Sinh vien da duoc xoa\n");
			return;
		}
	}
	printf("Khong tim thay sinh vien\n");
}
void timKiem(struct SinhVien sinhVien[], int n){
	int search;
	printf("Ban hay nhap id muon tim: ");
	scanf("%d", &search);
	int count=0;
	for(int i=0; i<n; i++){
		if(sinhVien[i].id==search){
			count=1;
			printf("\nId: %d\nHo va ten: %sTuoi: %d\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age);
		}
	}
	if(count==0){
		printf("Khong tim thay sinh vien nao co id can tim\n");
	}
}
void sapXep(struct SinhVien sinhVien[], int n){
	struct SinhVien temp;
	for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if (strcmp(sinhVien[i].fullName, sinhVien[j].fullName)>0){
                temp=sinhVien[i];
                sinhVien[i]=sinhVien[j];
                sinhVien[j]=temp;
            }
        }
    }
    writeFile(sinhVien, n);
    printf("Danh sach da duoc sap xep theo ho va ten sinh vien\n");
}
