#include "stdafx.h"
#include "address.h"


void print_spacer()
{
	printf("---------------------------------------\n");
}


address *create_entry(address *prev,
	const char *name,
	const char *firstname,
	const char *street,
	const char *city,
	const char *zipcode) {

	auto *entry = (address*)malloc(sizeof(address));

	entry->name = _strdup(name);
	entry->firstname = _strdup(firstname);
	entry->street = _strdup(street);
	entry->city = _strdup(city);
	entry->zipcode = _strdup(zipcode);

	if (prev != NULL)
		prev->next = entry;

	entry->next = NULL;
	entry->prev = prev;

	return entry;
}

void free_entryfield(char* string)
{
	memset(string, ' ', strlen(string));
	free(string);
}


void free_entry(address *entry)
{
	if (entry != NULL)
	{
		address *prev = entry->prev;
		address *next = entry->next;

		prev->next = next;
		next->prev = prev;

		free_entryfield(entry->name);
		free_entryfield(entry->firstname);
		free_entryfield(entry->street);
		free_entryfield(entry->city);
		free_entryfield(entry->zipcode);
		free(entry);
	}
}


address *switch_address(address *point, bool next)
{
	if (next)
		if (point->next != NULL)
			point = point->next;

	if (!next)
		if (point->prev != NULL)
			point = point->prev;

	return point;
}


address *input_new_entry(address *prev)
{
	address *new_entry = NULL;

	char* in_name		= NULL;
	char* in_firstname	= NULL;
	char* in_street		= NULL;
	char* in_city		= NULL;
	char* in_zipcode	= NULL;

	in_name			= input_data("Enter the entry's name.");
	in_firstname	= input_data("Enter the entry's firstname.");
	in_street		= input_data("Enter the entry's street.");
	in_city			= input_data("Enter the entry's city.");
	in_zipcode		= input_data("Enter the entry's zipcode.");

	new_entry = create_entry(prev, in_name, in_firstname, in_street, in_city, in_zipcode);
	return new_entry;
}


void redup_entryfield(char *field, const char* message)
{
	free_entryfield(field);
	field = _strdup(input_data(message));
}


address *edit_current_entry(address *entry)
{
	if (entry == NULL)
		return NULL;

	const int wait_time = 1000;

	char* in_name		= NULL;
	char* in_firstname  = NULL;
	char* in_street		= NULL;
	char* in_city		= NULL;
	char* in_zipcode	= NULL;

	char input[15] = "\0";

	while (true)
	{
		system("cls");

		printf("Name		:	%s\n", entry->name);
		printf("Surname		:	%s\n", entry->firstname);
		printf("Street		:	%s\n", entry->street);
		printf("City		:	%s\n", entry->city);
		printf("Zipcode		:	%s\n", entry->zipcode);
		print_spacer();
		printf("\n");
		printf("What would you like to edit?	\n\n");
		printf("[Name]		: edit name.		\n");
		printf("[Firstname]	: edit firstname.	\n");
		printf("[Street]	: edit street.		\n");
		printf("[City]		: edit city.		\n");
		printf("[Zipcode]	: edit zipcode.		\n");
		printf("[Back]		: cancel editing.	\n");
		printf("\n");
		print_spacer();
		printf("\n");

		gets_s(input, 15);
		printf("\n");

		if (strcmp(input, "Name") == 0)
		{
			redup_entryfield(entry->name, "Enter the entry's new name.");
		}
		else if (strcmp(input, "Firstname") == 0)
		{
			redup_entryfield(entry->firstname, "Enter the entry's new firstname.");
		}
		else if (strcmp(input, "Street") == 0)
		{
			redup_entryfield(entry->street, "Enter the entry's new street.");
		}
		else if (strcmp(input, "City") == 0)
		{
			redup_entryfield(entry->city, "Enter the entry's new city.");
		}
		else if (strcmp(input, "Zipcode") == 0)
		{
			redup_entryfield(entry->zipcode, "Enter the entry's new zipcode.");
		}
		else if (strcmp(input, "Back") == 0)
		{
			break;
		}
		else
		{
			print_spacer();
			printf("Unknown command | %s\n", input);
			print_spacer();
			Sleep(wait_time);
		}
	}

	return entry;
}


char* input_data(const char *msg)
{
	auto input		= (char*)malloc(20 * sizeof(char));
	char conf[5]	= "";

	while (strcmp(conf, "Yes") != 0)
	{
		print_spacer();
		printf("\n");
		printf("%s (Max. 20 characters)\n", msg);
		printf("\n > ");
		gets_s(input, 20);
		printf("\n");
		printf("Is %s correct? (Yes|No)\n", input);
		printf("\n > ");
		gets_s(conf, 5);
		printf("\n");
		print_spacer();
		printf("\n");
	}

	return input;
}