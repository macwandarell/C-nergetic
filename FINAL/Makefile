# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
COMMON_SRC = f_string.c
TARGETS = login registration admin main viewpage userpage selection billing

# Default target
all: $(TARGETS)

# Rules for each executable
login: Login.c $(COMMON_SRC)
	$(CC) $(CFLAGS) Login.c $(COMMON_SRC) -o login

registration: Registration.c $(COMMON_SRC)
	$(CC) $(CFLAGS) Registration.c $(COMMON_SRC) -o registration

admin: Admin.c $(COMMON_SRC)
	$(CC) $(CFLAGS) Admin.c $(COMMON_SRC) -o admin

main: Main.c $(COMMON_SRC)
	$(CC) $(CFLAGS) Main.c $(COMMON_SRC) -o main

viewpage: ViewPage.c $(COMMON_SRC)
	$(CC) $(CFLAGS) ViewPage.c $(COMMON_SRC) -o viewpage

userpage: user_page.c $(COMMON_SRC)
	$(CC) $(CFLAGS) user_page.c $(COMMON_SRC) -o userpage

selection: selection.c $(COMMON_SRC)
	$(CC) $(CFLAGS) selection.c $(COMMON_SRC) -o selection

billing: Billing.c $(COMMON_SRC)
	$(CC) $(CFLAGS) Billing.c $(COMMON_SRC) -o billing

# Clean target to remove all executables
clean:
	rm -f $(TARGETS)
