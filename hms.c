#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "prescriptions.dat"
#define MAX_NAME_LEN 100
#define MAX_MEDICINE_LEN 200
#define MAX_DOSAGE_LEN 100
#define MAX_NOTES_LEN 200

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int prescriptionID;
    char patientName[MAX_NAME_LEN];
    int patientAge;
    char doctorName[MAX_NAME_LEN];
    char medicine[MAX_MEDICINE_LEN];
    char dosage[MAX_DOSAGE_LEN];
    char notes[MAX_NOTES_LEN];
} Prescription;

// ------------------ FUNCTION DECLARATIONS ------------------
void addPrescription();
void viewPrescriptions();
void searchPrescription();
void updatePrescription();
void deletePrescription();

int idExists(int id);
void savePrescription(Prescription p);
void loadPrescriptions(Prescription prescriptions[], int *count);
void writeAllPrescriptions(Prescription prescriptions[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n====================================\n");
        printf("     PRESCRIPTION MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add New Prescription\n");
        printf("2. View All Prescriptions\n");
        printf("3. Search Prescription\n");
        printf("4. Update Prescription\n");
        printf("5. Delete Prescription\n");
        printf("6. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addPrescription(); break;
            case 2: viewPrescriptions(); break;
            case 3: searchPrescription(); break;
            case 4: updatePrescription(); break;
            case 5: deletePrescription(); break;
            case 6: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD PRESCRIPTION ------------------
void addPrescription() {
    Prescription p;

    printf("\n--- Add New Prescription ---\n");
    printf("Enter Prescription ID: ");
    scanf("%d", &p.prescriptionID);
    getchar();

    if (idExists(p.prescriptionID)) {
        printf("Error: Prescription ID already exists!\n");
        return;
    }

    printf("Enter Patient Name: ");
    fgets(p.patientName, sizeof(p.patientName), stdin);
    p.patientName[strcspn(p.patientName, "\n")] = '\0';

    printf("Enter Patient Age: ");
    scanf("%d", &p.patientAge);
    getchar();

    printf("Enter Doctor Name: ");
    fgets(p.doctorName, sizeof(p.doctorName), stdin);
    p.doctorName[strcspn(p.doctorName, "\n")] = '\0';

    printf("Enter Medicine List: ");
    fgets(p.medicine, sizeof(p.medicine), stdin);
    p.medicine[strcspn(p.medicine, "\n")] = '\0';

    printf("Enter Dosage Instructions: ");
    fgets(p.dosage, sizeof(p.dosage), stdin);
    p.dosage[strcspn(p.dosage, "\n")] = '\0';

    printf("Additional Notes: ");
    fgets(p.notes, sizeof(p.notes), stdin);
    p.notes[strcspn(p.notes, "\n")] = '\0';

    savePrescription(p);
    printf("Prescription saved successfully!\n");
}

// ------------------ SAVE PRESCRIPTION TO FILE ------------------
void savePrescription(Prescription p) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(&p, sizeof(Prescription), 1, fp);
    fclose(fp);
}

// ------------------ CHECK IF ID EXISTS ------------------
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Prescription p;
    while (fread(&p, sizeof(Prescription), 1, fp)) {
        if (p.prescriptionID == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ VIEW ALL PRESCRIPTIONS ------------------
void viewPrescriptions() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Prescription p;

    printf("\n%-10s %-20s %-5s %-20s %-20s %-20s %-20s\n",
           "ID", "Patient", "Age", "Doctor", "Medicine", "Dosage", "Notes");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(&p, sizeof(Prescription), 1, fp)) {
        printf("%-10d %-20s %-5d %-20s %-20s %-20s %-20s\n",
               p.prescriptionID, p.patientName, p.patientAge,
               p.doctorName, p.medicine, p.dosage, p.notes);
    }

    fclose(fp);
}

// ------------------ SEARCH PRESCRIPTION ------------------
void searchPrescription() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    Prescription p;

    printf("\nEnter Prescription ID: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Prescription), 1, fp)) {
        if (p.prescriptionID == id) {
            printf("\nPrescription Found:\n");
            printf("ID: %d\nPatient: %s\nAge: %d\nDoctor: %s\nMedicine: %s\nDosage: %s\nNotes: %s\n",
                   p.prescriptionID, p.patientName, p.patientAge,
                   p.doctorName, p.medicine, p.dosage, p.notes);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No prescription found with ID %d.\n", id);

    fclose(fp);
}

// ------------------ UPDATE PRESCRIPTION ------------------
void updatePrescription() {
    Prescription prescriptions[500];
    int count = 0, id, found = 0;

    loadPrescriptions(prescriptions, &count);

    printf("\nEnter Prescription ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (prescriptions[i].prescriptionID == id) {
            found = 1;

            printf("Update Medicine: ");
            fgets(prescriptions[i].medicine, sizeof(prescriptions[i].medicine), stdin);
            prescriptions[i].medicine[strcspn(prescriptions[i].medicine, "\n")] = '\0';

            printf("Update Dosage: ");
            fgets(prescriptions[i].dosage, sizeof(prescriptions[i].dosage), stdin);
            prescriptions[i].dosage[strcspn(prescriptions[i].dosage, "\n")] = '\0';

            printf("Update Notes: ");
            fgets(prescriptions[i].notes, sizeof(prescriptions[i].notes), stdin);
            prescriptions[i].notes[strcspn(prescriptions[i].notes, "\n")] = '\0';

            break;
        }
    }

    if (found) {
        writeAllPrescriptions(prescriptions, count);
        printf("Prescription updated successfully!\n");
    } else {
        printf("Prescription ID not found.\n");
    }
}

// ------------------ DELETE PRESCRIPTION ------------------
void deletePrescription() {
    Prescription prescriptions[500];
    int count = 0, id, found = 0;

    loadPrescriptions(prescriptions, &count);

    printf("\nEnter Prescription ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (prescriptions[i].prescriptionID == id) {
            found = 1;

            printf("Are you sure you want to delete Prescription %d? (y/n): ", id);
            char confirm =getchar();
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                // Shift remaining prescriptions to fill deleted spot
                for (int j = i; j < count - 1; j++) {
                    prescriptions[j] = prescriptions[j + 1];
                }
                count--;

                writeAllPrescriptions(prescriptions, count);
                printf("Prescription deleted successfully!\n");
            } else {
                printf("Delete operation cancelled.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Prescription ID not found.\n");
    }
}

// ------------------ LOAD ALL PRESCRIPTIONS ------------------
void loadPrescriptions(Prescription prescriptions[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        *count = 0;
        return;
    }

    while (fread(&prescriptions[*count], sizeof(Prescription), 1, fp)) {
        (*count)++;
    }

    fclose(fp);
}

// ------------------ WRITE ALL PRESCRIPTIONS BACK TO FILE ------------------
void writeAllPrescriptions(Prescription prescriptions[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fwrite(prescriptions, sizeof(Prescription), count, fp);
    fclose(fp);
}