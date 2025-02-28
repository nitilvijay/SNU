# Customer database
customers = [
    {'acc': 123, 'ph': 9080093377, 'pin': 1111, 'curr': 5859, 'last_five': [120, -80, 50, -59, 22]},
    {'acc': 456, 'ph': 9080093377, 'pin': 1111, 'curr': 0, 'last_five': []},  # Added missing fields
    {'acc': 223, 'ph': 9894328537, 'pin': 2222, 'curr': 4674, 'last_five': [-120, 80, -50, 59, 22]},
    {'acc': 789, 'ph': 9943921516, 'pin': 3333, 'curr': 796387, 'last_five': [120, -80, -50, 59, 22]},
    {'acc': 987, 'ph': 9843331668, 'pin': 4444, 'curr': 33159, 'last_five': [-120, -80, -50, 59, 22]},
    {'acc': 654, 'ph': 9944102080, 'pin': 5555, 'curr': 6943, 'last_five': [120, -80, -50, -59, 22]}
]

# Global variables
current_account = None

# Function to verify ATM PIN
def verify_pin():
    global current_account
    atm_pin = int(input("Enter your ATM PIN: "))

    for customer in customers:
        if customer['acc'] == current_account and customer['pin'] == atm_pin:
            return True
    return False

# Function to update last five transactions
def update_transactions(last_five, amount):
    last_five.insert(0, amount)  # Add new transaction at the start
    if len(last_five) > 5:
        last_five.pop()  # Keep only the last 5 transactions
    return last_five

# Withdraw money
def withdraw():
    global customers, current_account
    amount = int(input("Enter the amount to withdraw: "))

    for customer in customers:
        if customer['acc'] == current_account:
            if amount > customer['curr']:
                print("❌ Not enough balance.")
            else:
                customer['curr'] -= amount
                customer['last_five'] = update_transactions(customer['last_five'], -amount)
                print(f"✅ Withdrawal successful! Current balance: ₹{customer['curr']}")

# Deposit money
def deposit():
    global customers, current_account
    amount = int(input("Enter the amount to deposit: "))

    for customer in customers:
        if customer['acc'] == current_account:
            customer['curr'] += amount
            customer['last_five'] = update_transactions(customer['last_five'], amount)
            print(f"✅ Deposit successful! Current balance: ₹{customer['curr']}")

# Check balance
def check_balance():
    global customers, current_account

    for customer in customers:
        if customer['acc'] == current_account:
            print(f"💰 Current balance: ₹{customer['curr']}")

# View transaction history
def transaction_history():
    global customers, current_account

    for customer in customers:
        if customer['acc'] == current_account:
            print("📜 Transaction History: ", customer['last_five'])

# Change PIN
def change_pin():
    global customers, current_account

    for customer in customers:
        if customer['acc'] == current_account:
            old_pin = int(input("Enter your current PIN: "))

            if customer['pin'] == old_pin:
                new_pin = int(input("Enter your new PIN: "))
                customer['pin'] = new_pin
                print("✅ PIN changed successfully!")
                return
            else:
                print("❌ Incorrect old PIN.")

# Main ATM menu
def atm_menu():
    while True:
        print("\n--- ATM MENU ---")
        print("1. Withdraw")
        print("2. Deposit")
        print("3. Check Balance")
        print("4. Transaction History")
        print("5. Change PIN")
        print("6. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            withdraw()
        elif choice == 2:
            deposit()
        elif choice == 3:
            check_balance()
        elif choice == 4:
            transaction_history()
        elif choice == 5:
            change_pin()
        elif choice == 6:
            print("👋 Thank you for using the ATM. Have a great day!")
            break
        else:
            print("❌ Invalid choice. Please select again.")

# Main program loop
while True:
    account_number = int(input("\nEnter your account number: "))

    # Validate account number
    found = False
    for customer in customers:
        if customer['acc'] == account_number:
            found = True
            current_account = account_number
            break

    if not found:
        print("❌ Invalid account number. Try again.")
        continue

    # Verify ATM PIN
    if verify_pin():
        atm_menu()  # Proceed to ATM menu
    else:
        print("❌ Incorrect PIN. Try again.")
