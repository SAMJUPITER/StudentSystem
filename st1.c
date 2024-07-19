#include<stdio.h>
#include<conio.h>
#include<string.h>
#define tab printf("\t\t\t")

struct liststudent {
    char name[20];
    char lastname[35];
    char phonenum[20];
    char email[30];
    char address[30];
} li;

void creatnewstudent() {
    FILE *fp;
    fp = fopen("studentinfo.txt", "a+");
    
    system("cls");
    tab; printf("=======================\n");
    tab; printf("      New student\n");
    tab; printf("=======================\n");    
    tab; printf("Input name : "); fflush(stdin); gets(li.name);
    tab; printf("Input lastname : "); fflush(stdin); gets(li.lastname);
    tab; printf("Phonenum : "); fflush(stdin); gets(li.phonenum);
    tab; printf("Input email : "); fflush(stdin); gets(li.email);
    tab; printf("Input address : "); fflush(stdin); gets(li.address);
    fprintf(fp, "%s %s %s %s %s\n", li.name, li.lastname, li.phonenum, li.email, li.address);
    fclose(fp);
    tab; printf("=======SUCCESSFUL======\n");
    system("pause");
}

void editstudent() {
    FILE *fp, *fp_temp;
    char searchname[20];
    int found = 0;

    system("cls");
    tab; printf("=======================\n");
    tab; printf("      Edit student\n");
    tab; printf("=======================\n");
    tab; printf("Input name to edit: "); fflush(stdin); gets(searchname);

    fp = fopen("studentinfo.txt", "r");
    fp_temp = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %s %s %s\n", li.name, li.lastname, li.phonenum, li.email, li.address) != EOF) {
        if (strcmp(li.name, searchname) == 0) {
            found = 1;
            tab; printf("Input new lastname : "); fflush(stdin); gets(li.lastname);
            tab; printf("Phonenum : "); fflush(stdin); gets(li.phonenum);
            tab; printf("Input email : "); fflush(stdin); gets(li.email);
            tab; printf("Input address : "); fflush(stdin); gets(li.address);
        }//if
        fprintf(fp_temp, "%s %s %s %s %s\n", li.name, li.lastname, li.phonenum, li.email, li.address);
    }//while
    fclose(fp);
    fclose(fp_temp);

    remove("studentinfo.txt");
    rename("temp.txt", "studentinfo.txt");

    if (found) {
        tab; printf("=======SUCCESSFUL======\n");
    } else {
        tab; printf("=======NOT FOUND=======\n");
    }
    system("pause");
}

void searchstudent() {
    FILE *fp;
    char searchname[20];
    int found = 0;

    system("cls");
    tab; printf("=======================\n");
    tab; printf("      Search student\n");
    tab; printf("=======================\n");
    tab; printf("Input name to search: "); fflush(stdin); gets(searchname);

    fp = fopen("studentinfo.txt", "r");

    while (fscanf(fp, "%s %s %s %s %s\n", li.name, li.lastname, li.phonenum, li.email, li.address) != EOF) {
        if (strcmp(li.name, searchname) == 0) {
            found = 1;
            tab; printf("Name: %s\n", li.name);
            tab; printf("Lastname: %s\n", li.lastname);
            tab; printf("Phonenum: %s\n", li.phonenum);
            tab; printf("Email: %s\n", li.email);
            tab; printf("Address: %s\n", li.address);
            break;
        }
    }
    fclose(fp);

    if (!found) {
        tab; printf("=======NOT FOUND=======\n");
    }
    system("pause");
}

void liststudents() {
    FILE *fp;

    system("cls");
    tab; printf("=======================\n");
    tab; printf("      List students\n");
    tab; printf("=======================\n");

    fp = fopen("studentinfo.txt", "r");

    while (fscanf(fp, "%s %s %s %s %s\n", li.name, li.lastname, li.phonenum, li.email, li.address) != EOF) {
        tab; printf("Name: %s\n", li.name);
        tab; printf("Lastname: %s\n", li.lastname);
        tab; printf("Phonenum: %s\n", li.phonenum);
        tab; printf("Email: %s\n", li.email);
        tab; printf("Address: %s\n", li.address);
        tab; printf("-----------------------\n");
    }
    fclose(fp);

    system("pause");
}

void deletestudent() {
    FILE *fp, *fp_temp;
    char searchname[20];
    int found = 0;

    system("cls");
    tab; printf("=======================\n");
    tab; printf("      Delete student\n");
    tab; printf("=======================\n");
    tab; printf("Input name to delete: "); fflush(stdin); gets(searchname);

    fp = fopen("studentinfo.txt", "r");
    fp_temp = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %s %s %s\n", li.name, li.lastname, li.phonenum, li.email, li.address) != EOF) {
        if (strcmp(li.name, searchname) != 0) {
            fprintf(fp_temp, "%s %s %s %s %s\n", li.name, li.lastname, li.phonenum, li.email, li.address);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(fp_temp);

    remove("studentinfo.txt");
    rename("temp.txt", "studentinfo.txt");

    if (found) {
        tab; printf("=======SUCCESSFUL======\n");
    } else {
        tab; printf("=======NOT FOUND=======\n");
    }
    system("pause");
}

void main() {
    int ch;
    do {
        system("cls");
        tab; printf("=======================\n");
        tab; printf("      MAIN MENU\n");
        tab; printf("=======================\n");
        tab; printf("1. Create new student\n");
        tab; printf("2. Edit student\n");
        tab; printf("3. Search student\n");
        tab; printf("4. List students\n");
        tab; printf("5. Delete student\n");
        tab; printf("0. Exit\n");
        tab; printf("=======================\n");
        tab; printf("      Enter option: ");
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch) {
            case 1: creatnewstudent();
                    break;
            case 2: editstudent();
                    break;
            case 3: searchstudent();
                    break;
            case 4: liststudents();
                    break;
            case 5: deletestudent();
                    break;
        }
    } while (ch != 0);
}

