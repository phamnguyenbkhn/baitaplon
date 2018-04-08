
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
struct Student{
    char TermNote[10];
    char classID[20];
    char courseID[10];
    char name[50];
    char SectionType[10];
    char note[30];
    char StudentID[10];
    char StudentName[30];
    char BirthDate[20];
    char groupName[50];
    char termID[10];
    char AcademicName[50];
    char studyGroupName[10];
    char TimeTable[100];
};

struct Node{
    Student data;
    Node *Next;
    Node *Prev;
};
struct DList{
    Node *Head;
    Node *Tail;
};  
    
void Init(DList &l){
    l.Head = l.Tail = NULL;
}

void addTail(DList &l, Node *new_node){
    if(l.Head == NULL) l.Head = l.Tail = new_node;//tao 1 node moi va head &tail deu tro den khi tao node dau tien
    else{
        l.Tail->Next = new_node;
        new_node->Prev = l.Tail;
        l.Tail = new_node;
    }
}

Node *getStudent(char TermNote[],
    char classID[],
    char courseID[],
    char name[],
    char SectionType[],
    char note[],
    char StudentID[],
    char StudentName[],
    char BirthDate[],
    char groupName[],
    char termID[],
    char AcademicName[],
    char studyGroupName[],
    char TimeTable[])
{
    Node *p = new Node;
    if(p == NULL){
        return NULL;
    }
    else{
        strcpy(p->data.TermNote, TermNote);
        strcpy(p->data.classID, classID);
        strcpy(p->data.courseID, courseID);
        strcpy(p->data.name, name);
        strcpy(p->data.SectionType, SectionType);
        strcpy(p->data.note, note);
        strcpy(p->data.StudentID, StudentID);
        strcpy(p->data.StudentName, StudentName);
        strcpy(p->data.BirthDate, BirthDate);
        strcpy(p->data.groupName, groupName);
        strcpy(p->data.termID, termID);
        strcpy(p->data.AcademicName, AcademicName);
        strcpy(p->data.TimeTable, TimeTable);
        p->Next = NULL;
        p->Prev = NULL;
        return p;
    }
}

void input(DList &l){
    FILE *file1;
    Student studentInfo[20000];
    int i1 = 0;
    file1 = fopen("data1.txt", "r");
    while(fscanf(file1, "%s %s %s %s %s %s %s %s %s %s %s %s %s", &studentInfo[i1].TermNote, &studentInfo[i1].classID, 
            &studentInfo[i1].courseID, &studentInfo[i1].name, &studentInfo[i1].SectionType, &studentInfo[i1].note,
            &studentInfo[i1].StudentID, &studentInfo[i1].StudentName, &studentInfo[i1].BirthDate, &studentInfo[i1].groupName,
            &studentInfo[i1].termID, &studentInfo[i1].AcademicName, &studentInfo[i1].TimeTable) == 13 && strlen(studentInfo[i1].studyGroupName) == 0){
        i1++;
    }   

    for (int j = 0; j<i1; j++){
        Node *p = getStudent(studentInfo[j].TermNote, studentInfo[j].classID,
            studentInfo[j].courseID, studentInfo[j].name, studentInfo[j].SectionType, studentInfo[j].note,
            studentInfo[j].StudentID, studentInfo[j].StudentName, studentInfo[j].BirthDate, studentInfo[j].groupName,
            studentInfo[j].termID, studentInfo[j].AcademicName, studentInfo[j].studyGroupName, studentInfo[j].TimeTable);
        addTail(l, p);
        printf("\nDa khoi tao node moi thu %d: %s", j+1, p->data.StudentName);
    }   
    
    FILE *file2 = fopen("data2.txt", "r");
    int i2 = i1+1;
    while(fscanf(file2, "%s %s %s %s %s %s %s %s %s %s %s %s", &studentInfo[i2].TermNote, &studentInfo[i2].classID, 
            &studentInfo[i2].courseID, &studentInfo[i2].name, &studentInfo[i2].SectionType, &studentInfo[i2].note,
            &studentInfo[i2].StudentID, &studentInfo[i2].StudentName, &studentInfo[i2].BirthDate, &studentInfo[i2].groupName,
            &studentInfo[i2].termID, &studentInfo[i2].AcademicName) == 12 && strlen(studentInfo[i2].TimeTable) == 0){
        i2++;
    }   
 
        
    for (int j = i1; j<i2; j++){
        Node *p = getStudent(studentInfo[j].TermNote, studentInfo[j].classID,
            studentInfo[j].courseID, studentInfo[j].name, studentInfo[j].SectionType, studentInfo[j].note,
            studentInfo[j].StudentID, studentInfo[j].StudentName, studentInfo[j].BirthDate, studentInfo[j].groupName,
            studentInfo[j].termID, studentInfo[j].AcademicName, studentInfo[j].studyGroupName, studentInfo[j].TimeTable);
        addTail(l, p);
        printf("\nDa khoi tao node moi thu %d: %s", j+1, p->data.StudentName);
    }
}

void printStudent(Node *p){
    printf("%s  %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", p->data.TermNote, p->data.StudentName,
            p->data.StudentID, p->data.BirthDate, p->data.classID, p->data.courseID,
            p->data.name, p->data.SectionType, p->data.note, p->data.groupName,
            p->data.termID);
}

void timLop(DList &l, char maLop[]){
    printf("\nDanh sach lop %s: ", maLop);
    int i = 1;
    Node *p = l.Head;
    while(p){
        if(strcmp(maLop, p->data.classID) == 0){
            printf("\n%d. ", i);
            printStudent(p);
            i++;
        }
        p = p->Next;
    }
}

void timLopTheoMaMonHoc(DList &l){
    char maMonHoc[10];
    printf("\nNhap ma mon hoc: ");
    cin.ignore();
    cin.getline(maMonHoc, 10);
    fflush(stdin);
    Node *p = l.Head;
    printf("\n\nDanh sach cac lop %s: ", maMonHoc);
    while(p){
        if(strcmp(maMonHoc, p->data.courseID) == 0){
            if(strcmp(p->Prev->data.classID, p->data.classID)){
                timLop(l, p->data.classID);
                printf("\n");
            }
        }
        p = p->Next;
    }
}

void thongTinLopSinhVien(DList &l){
    char MSSV[10];
    printf("\nNhap ma sinh vien: ");
    cin.ignore();
    cin.getline(MSSV, 10);
    fflush(stdin);
    Node *p = l.Head;
    printf("\nCac lop sinh vien theo hoc: ");
    while(p){
        if(strcmp(MSSV, p->data.StudentID) == 0){
            printf("\nLop: %s. Mon hoc: %s. Thoi khoa bieu: %s", p->data.classID, p->data.name, p->data.TimeTable);
        }
        p = p->Next;
    }
}

void timSVCungHoTen(DList &l){
    char hoTen[30];
    printf("\nNhap ho ten: ");
    cin.ignore();
    cin.getline(hoTen, 30);
    fflush(stdin);
    Node *p = l.Head;
    printf("\nCac sinh vien co ho ten: %s", hoTen);
    int i = 1;
    while(p){
        if(strcmp(hoTen, p->data.StudentName) == 0){
            printf("\n%d. Ma sinh vien: %s. Ma lop: %s. Mon hoc: %s. "
                    "Thoi khoa bieu: %s", i, p->data.StudentID, p->data.classID,
                    p->data.name, p->data.TimeTable);
        }
        p = p->Next;
    }
}

void inDanhSach(DList l){
    Node *p = l.Head;
    int i = 1;
    while(p){
        printf("\n\nHoc sinh thu %d: %s", i, p->data.StudentID);
        p = p->Next;
        i++;
    }
}

int menu(){
    int i;
    printf("\n\nNHAP LUA CHON CUA BAN: ");
    scanf("%d", &i);
    return i;
}

int main(int argc, char** argv) {
    DList l;
    Init(l);
    input(l);
    printf("\n\n_______________CHUONG TRINH QUAN LY SINH VIEN_______________\n"
            "1. HIEN THI DANH SACH SINH VIEN THEO LOP\n"
            "2. HIEN THI DANH SACH SINH VIEN THEO MON HOC\n"
            "3. HIEN THI DANH SACH LOP CUA MOT SINH VIEN\n"
            "4. HIEN THI DANH SACH LOP CAC SINH VIEN CUNG HO TEN\n"
            "NHAP 0 DE KET THUC CHUONG TRINH\n");

    int i = menu();
    while(i){
        switch(i){
            case 1:
                char maLop[10];
                printf("\n\nNhap ma lop: ");
                cin.ignore();
                cin.getline(maLop, 10);
                fflush(stdin);
                timLop(l, maLop);
                break;
            case 2:
                timLopTheoMaMonHoc(l);
                break;
            case 3:
                thongTinLopSinhVien(l);
                break;
            case 4:
                timSVCungHoTen(l);
                break;
        }
        i = menu();
    }
}  
