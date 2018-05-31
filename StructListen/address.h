#pragma once

#include "stdafx.h"
#include <string.h>
#include <malloc.h>
#include <windows.h>


typedef struct address {
	char *name;
	char *firstname;
	char *street;
	char *city;
	char *zipcode;

	address *prev;
	address *next;
} address;


void print_spacer();


address *create_entry(address *prev,
	const char *name,
	const char *firstname,
	const char *street,
	const char *city,
	const char *zipcode);


void free_entryfield(char *string);


void free_entry(address *entry);


address* switch_address(address *point, bool next);


address* input_new_entry(address *prev);


char* input_data(const char *msg);


address* edit_current_entry(address *entry);