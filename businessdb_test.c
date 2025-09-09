#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "database.h"


void should_be_equal(const char *message, int expected, int actual) {
    printf("%s\n", message);
    printf("%s: wanted %d, got %d\n",
           (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

void test_add_customer() {
    printf("\n**** Test: Add Customer ****\n");

    HashTable table;
    init_table(&table);

    int result = add_customer(&table, "john@gmail.com", "John Clarke", 42, "pizza");
    should_be_equal("Adding a valid customer", 0, result);

    result = add_customer(&table, "invalid-email", "Janet Dober", 31, "burger");
    should_be_equal("Adding a customer with invalid email", -1, result);
}

void test_load_database() {
    printf("\n**** Test: Load Database ****\n");

    HashTable table;
    init_table(&table);

    int result = load_database(&table, "customers.tsv");
    should_be_equal("Loading valid database", 0, result);

    result = load_database(&table, "non_existent_file.tsv");
    should_be_equal("Loading non-existent file", -1, result);
}

void test_delete_customer() {
    printf("\n**** Test: Delete Customer ****\n");

    HashTable table;
    init_table(&table);

    add_customer(&table, "bob@example.com", "Bob", 42, "pizza");
    int result = delete_customer(&table, "bob@example.com");
    should_be_equal("Delete existing customer", 0, result);

    Customer *found = lookup_customer(&table, "bob@example.com");
    should_be_equal("Verify customer was deleted", 0, found == NULL);

    result = delete_customer(&table, "nonexistent@example.com");
    should_be_equal("Delete non-existent customer", -1, result);
}

int main() {
    printf("Running tests for businessdb.c\n");

    test_add_customer();
    test_load_database();

    return 0;
}

