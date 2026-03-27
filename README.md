# Company Sales Parser

> Automates the creation of day-end sales emails for store reporting.

While working at Bulk Barn, I frequently had to manually compile and write these emails. This tool streamlines the process by parsing backend data files and generating ready-to-use email drafts.

---

## Features

- **File Parsing** — Reads the daily sales file from the company's backend and extracts only the relevant data needed for emails.
- **User Input** — Prompts for the name of the person sending the email.
- **Email Generation** — Produces a `.txt` email file ready to copy and paste into your email client.
- **Time Saver** — Eliminates repetitive manual work, reduces errors, and speeds up daily reporting.

---

## How It Works

1. Loads the daily backend data file.
2. Filters out unnecessary information, keeping only the data needed for the email.
3. Prompts for your name as the sender.
4. Generates a formatted `.txt` email document.

---

## Compilation & Usage

1. Open a terminal in the project directory.
2. Compile using GCC:
   ```bash
   gcc -o run main.c
   ```
3. Run the program:
   ```bash
   ./run
   ```
4. Input the sales file name when prompted.
5. Input your name as the sender.
6. The program creates a `.txt` email document ready to copy into your email client.

---

## Example Output

```
To: manager@example.com
From: John Doe
Subject: Daily Sales Report - 2026-03-27

[Parsed sales data here]
```

---

## Notes

- Designed to save time on repetitive day-end emails.
- Only extracts relevant data for easier reporting.
- Flexible: works with daily backend files following the company's format.
