# Prescription Management System (C Program)

A simple menu-driven Prescription Management System written in C.  
This program allows users to store, manage, and view prescription details efficiently using structures and arrays.

---

## 📌 Abstract
The Prescription Management System is a basic C application designed to handle patient prescription records. It uses structures to group related information like patient name, doctor name, medicine, and dosage. The system allows adding multiple prescriptions and viewing all stored prescriptions through a simple text-based menu interface.

---

## 🚀 Features
- Add new prescriptions  
- Store multiple prescription records (up to 100)  
- View all saved prescriptions  
- Menu-driven system  
- Uses structure for better data organization  
- Easy to compile and run on any C compiler  

---

# 📌 Technical Requirements (Aligned With Provided Code)

## 1. **System Overview**

The Prescription Management System is a simple, menu-driven C program that lets the user:

* Add a prescription to memory
* View all stored prescriptions

The program runs entirely in a terminal and uses in-memory storage only.

---

## 2. **Language & Compilation Requirements**

* **Language Standard:** C99 or later
* **Compiler:** GCC or Clang
* **Build:** Optional `Makefile`
* Recommended compiler flags:

  * `-Wall -Wextra`

The program must compile as a single C source file.

---

## 3. **In-Memory Data Requirements**

* The program stores prescription records in a **fixed-size array** with a capacity of **100 entries**.
* A counter tracks how many prescriptions have been added during runtime.
* No files or external storage are used.
* All data exists only while the program is running.

---

## 4. **Program Flow Requirements**

### 4.1 Menu System

The program must display a looped text menu with three actions:

1. Add a prescription
2. View all prescriptions
3. Exit

Menu selection is accepted using `scanf`.

### 4.2 Adding a Prescription

The program prompts the user to enter:

* Prescription ID
* Patient name
* Doctor name
* Medicine name
* Dosage

Each value is read from user input and stored in the next available slot in the array.

### 4.3 Viewing Prescriptions

When the user chooses to view prescriptions:

* If no entries exist, display a message indicating none are available.
* Otherwise, display all stored prescriptions sequentially, showing the saved fields.

---

## 5. **Runtime Requirements**

* Program must run in a standard terminal environment.
* Only the standard I/O library is required:

  ```c
  #include <stdio.h>
  ```


## 🖼 Screenshot

Here is how the program looks:

<img width="236" height="261" alt="Screenshot 2025-11-20 134318" src="https://github.com/user-attachments/assets/9e175c3c-7abc-459f-a00b-c7d95a04e053" />

---


## 🛠 How to Compile and Run

### **Using GCC Compiler**
```bash
gcc hms.c<img width="717" height="105" alt="Screenshot 2025-11-20 134646" src="https://github.com/user-attachments/assets/f4d6f275-aa9c-4802-9ea3-ed8eab4983c9" />
<img width="221" height="146" alt="Screenshot 2025-11-20 134525" src="https://github.com/user-attachments/assets/c854044b-e53b-4379-8cd7-dd08f070c8e1" />

.\a.exe

