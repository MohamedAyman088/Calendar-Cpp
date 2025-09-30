# 📅 Calendar Console App (C++)

A simple **C++** console application that displays a **calendar** for a specific month or an entire year.  
The program correctly handles leap years and prints the calendar in a clean table format.

---

## 🚀 Features
- Display the calendar for a specific month.
- Display the calendar for a full year (12 months).
- Automatically detects leap years.
- Simple main menu for navigation.
- Works on **Windows** and **Linux/Mac**.

---

## 🖥️ How to Run
### 1. Copy the code
Save the provided code in a file named `main.cpp`.

### 2. Compile
On **Windows** (using g++):
```bash
g++ main.cpp -o calendar.exe
```

On **Linux / Mac**:
```bash
g++ main.cpp -o calendar
```

### 3. Run
On **Windows**:
```bash
calendar.exe
```

On **Linux / Mac**:
```bash
./calendar
```

---

## 📋 Main Menu
When you run the program, you’ll see:

```
===========================================
        Main Menue Screen
===========================================
[1] Month Calendar
[2] Year Calendar
[3] Exit
===========================================
```

- **[1]** Enter year and month → shows the calendar for that month.  
- **[2]** Enter year → shows the full calendar for the entire year.  
- **[3]** Exit the program.

---

## 🛠️ Requirements
- C++11 or newer.
- **g++** or any C++ compiler.

---

## 📸 Example Output
```
Please Enter a Year? 2025
Please Enter a Month? 9

   __________________Sep__________________

   Sun   Mon   Tuh   Wed   Thu   Fri   Set
       1     2     3     4     5     6
    7     8     9    10    11    12    13
   14    15    16    17    18    19    20
   21    22    23    24    25    26    27
   28    29    30
   _______________________________________
```

---

## 👤 Author
- A simple training project for practicing **C++** and building console-based applications.  
