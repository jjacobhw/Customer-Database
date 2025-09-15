# Customer Database

A simple command-line customer database application written in C that allows you to manage customer information, including email addresses, names, shoe sizes, and favorite foods. Data is stored in Tab-Separated Values (TSV) format for easy portability.

This was a fun project I made for a class, where I experimented to see if a
customer's shoe size was correlated with the nutritional value of their favorite foods.

## Features

- ✅ Add new customers or update existing ones
- 🔍 Look up customers by email address
- 🗑️ Delete customers from the database
- 📋 List all customers in insertion order
- 💾 Save/load data to/from TSV files
- 🧪 Comprehensive test suite included

## Prerequisites

- GCC compiler (or any C99-compatible compiler)
- Make utility
- Unix-like operating system (Linux, macOS, BSD)

## Setup

### 1. Clone/Download the Repository

```bash
# If you have the source files, ensure they're in a directory
mkdir businessdb
cd businessdb
# Copy all .c and .h files to this directory
```
### 2. Compile the Application

```bash
# Option 1: Use 'make' (recommended)
make              # Compile the application
make test         # Compile and run tests
make clean        # Remove compiled files
make install      # Install to /usr/local/bin (requires sudo)

# Option 2: Compile the main application manually and test suite (optional)
gcc -std=c99 -Wall -Wextra -o businessdb businessdb.c database.c customer.c

# Test suite
gcc -std=c99 -Wall -Wextra -o businessdb_test businessdb_test.c database.c customer.c
```

### 3. Start the Application

Run the command to begin

```bash
./businessdb
```

The application will attempt to load existing customer data from `customers.tsv` if it exists, then present a command prompt.

### Available Commands

#### Add a Customer
```
Enter command: add
Enter email: john.doe@example.com
Enter name: John Doe
Enter shoe size: 42
Enter favorite food: Pizza
```

#### Look Up a Customer
```
Enter command: lookup
Enter email: john.doe@example.com
Email: john.doe@example.com, Name: John Doe, Shoe Size: 42, Favorite Food: Pizza
```

#### Delete a Customer
```
Enter command: delete
Enter email: john.doe@example.com
```

#### List All Customers
```
Enter command: list
Email: john.doe@example.com, Name: John Doe, Shoe Size: 42, Favorite Food: Pizza
Email: jane.smith@example.com, Name: Jane Smith, Shoe Size: 38, Favorite Food: Sushi
```

#### Save Database
```
Enter command: save
```
Saves all customer data to `customers.tsv`.

#### Exit Application
```
Enter command: quit
```

## File Format

The application uses Tab-Separated Values (TSV) format for data storage. Each line represents one customer:

```
email@domain.com	Customer Name	42	Favorite Food
jane@example.com	Jane Smith	38	Sushi
bob@test.org	Bob Johnson	45	Burger
```

**‼️Warning:** Avoid using tab characters in customer data as they will interfere with the file format.

## Example Session

```bash
$ ./businessdb
Enter command: add
Enter email: alice@example.com
Enter name: Alice Cooper
Enter shoe size: 39
Enter favorite food: Tacos

Enter command: add  
Enter email: bob@test.org
Enter name: Bob Wilson
Enter shoe size: 44
Enter favorite food: Spaghetti

Enter command: list
Email: alice@example.com, Name: Alice Cooper, Shoe Size: 39, Favorite Food: Tacos
Email: bob@test.org, Name: Bob Wilson, Shoe Size: 44, Favorite Food: Spaghetti

Enter command: lookup
Enter email: alice@example.com
Email: alice@example.com, Name: Alice Cooper, Shoe Size: 39, Favorite Food: Tacos

Enter command: save

Enter command: quit
```

## Running Tests

Execute the test suite to verify the application works correctly:

```bash
# If using Makefile
make test

# Or compile and run manually
gcc -std=c99 -Wall -Wextra -o businessdb_test businessdb_test.c database.c customer.c
./businessdb_test
```

Expected output:
```
Running tests for businessdb.c

**** Test: Add Customer ****
Adding a valid customer
SUCCESS: wanted 0, got 0
Adding a customer with invalid email
SUCCESS: wanted -1, got -1

**** Test: Load Database ****
Loading valid database
SUCCESS: wanted 0, got 0
Loading non-existent file
SUCCESS: wanted -1, got -1
```

### Creating Sample Data

You can create a sample `customers.tsv` file manually:

```bash
cat > customers.tsv << 'EOF'
john@example.com	John Doe	42	Pizza
jane@example.com	Jane Smith	38	Sushi
bob@test.org	Bob Johnson	45	Burgers
alice@demo.com	Alice Brown	40	Salad
EOF
```

## Memory Management

This application uses dynamic memory allocation. To check for memory leaks during development:

```bash
# Install valgrind (Ubuntu/Debian)
sudo apt-get install valgrind

# Run with memory checking
valgrind --leak-check=full --show-leak-kinds=all ./businessdb

# Example session, then quit and check output
```

## Performance Notes

- **Hash table size:** Fixed at 256 buckets
- **Lookup time:** O(1) average case, O(n) worst case
- **Memory usage:** Approximately 50-100 bytes per customer plus overhead
- **File I/O:** Entire database loaded into memory at startup

📝Important: For datasets larger than 10,000 customers, consider implementing dynamic hash table resizing.

