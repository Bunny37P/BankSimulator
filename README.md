## Execution

1. **Compile the Code:**
   - Compile the source code files using a C++ compiler. For example:
     ```bash
     g++ -o bank_system.out .\main.cpp .\bank_acc.cpp .\transactions.cpp
     ```
2. **Run:**
    - Run the executable or .out file generated after compilation. For example:
    ```
    .\bank_system.out < sample_input.txt
    ```

## Program Description

The program will read the following commands from input and process them as described below:

1. **Process Next X Transactions (F X):**
   - Process the next X transactions after the cursor.
   - If the last transaction is processed before completing X transactions, the cursor stays in the last node.

2. **Undo Y Transactions (R Y):**
   - Undo Y transactions starting from the cursor.
   - If the first transaction is processed before completing Y transactions, the cursor stays in the first node.

3. **Insert Transaction T After Kth Transaction (I T K):**
   - Insert a new transaction T immediately after the Kth transaction in the list.
   - Insert only if K is a valid value.
   - If inserting before the cursor position, process this new transaction as well.
   - The cursor position does not change.

4. **Delete Up to M Number of Transactions of Account A (D A M):**
   - Delete (up to) M (= 0) number of transactions of account A after/before (but excluding) the cursor's transaction.
   - Delete in the forward direction if M > 0 and reverse direction if M < 0.
   - Update the balance of account A accordingly.
   - The cursor stays in its original location.

5. **Process All Transactions (C):**
   - Process all transactions after the cursor.

6. **Print Processed Transactions of Account Number Y (S Y):**
   - Print all the processed transactions (until the cursor) of Account Number Y, one transaction per line.
   - If Y is invalid, no output is generated.

7. **Print Count of Accounts with Balance Greater than or Equal to X (G X):**
   - Print the count of the accounts whose balance is greater than or equal to X, with respect to the current cursor position.

8. **Print Account Number(s) with Highest Balance (M):**
   - Print the Account Number with the highest balance, with respect to the current cursor position.
   - If there is more than one account number with the same highest balance, print all numbers on one line separated by a single space, in increasing order.

9. **Print Balance of Account Number X (V X):**
   - Print the balance of Account Number X, with respect to the current cursor position.

### Input
The inputs are:
- The first line specifies the number of accounts to be maintained, denoted as C.
- The second line contains C space-separated unsigned integers - each integer denotes an account number.
- The next line specifies the number of transactions to be maintained, denoted as N.
- The next set of N lines: each line denotes either a deposit or withdrawal transaction. (in the format {account_number} {W/D} {amount})
- Inserts only the transactions of valid account numbers to the list, in the same order as in the input file. Invalid account numbers will be ignored.
- Each following line contains a processing directive (as listed above).
- The last line contains only the word END.

### Constraints
- Deposit and Withdrawal amounts will be non-negative integers less than or equal to 50000.

### Output
This will be the output of each query as applicable.
