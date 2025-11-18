#include <stdio.h>
struct Prescription {
     int id; 
     char patientName[50]; 
     char doctorName[50]; 
     char medicine[50]; 
     char dosage[50];
     };

int main() {
     struct Prescription p[100];
      int count = 0; 
      int choice; 
while (1) {
//menu
    printf(" SIMPLE PRESCRIPTION MANAGEMENT\n");
     printf("1. Add Prescription\n");
      printf("2. View All Prescriptions\n"); 
      printf("3. Exit\n ");
       printf("Enter choice: ");
        scanf("%d", &choice);

if (choice == 1) {
        printf("Enter Prescription ID: ");
        scanf("%d", &p[count].id);

        printf("Enter Patient Name: ");
        scanf("%s", p[count].patientName);

        printf("Enter Doctor Name: ");
        scanf("%s", p[count].doctorName);

        printf("Enter Medicine: ");
        scanf("%s", p[count].medicine);

        printf("Enter Dosage: ");
        scanf("%s", p[count].dosage);

        count++;
        printf("Prescription added successfully!");

 } else if (choice == 2) { 
    if (count == 0) { 
        printf("No prescriptions added yet. ");
     } else { printf(" --- PRESCRIPTIONS LIST --- ");
         for (int i = 0; i < count; i++) { 
            printf("ID: %d ", p[i].id);
             printf("Patient: %s ", p[i].patientName);
             printf("Doctor: %s ", p[i].doctorName);
              printf("Medicine: %s ", p[i].medicine);
               printf("Dosage: %s ", p[i].dosage);
                printf("--------------------------- ");
             } 
            } 
        } else if (choice == 3) {
             printf("Exiting... ");
              break;
             } else {
                
                printf("Invalid choice! Try again. ");
             } 
            }
            return 0;
            }