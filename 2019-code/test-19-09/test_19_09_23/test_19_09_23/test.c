#define _CRT_SECURE_NO_WARNINGS 1







#if 0
#include <stdio.h>
#include <string.h>

int main()
{
	
	return 0;
}


/* memcpy example */
#include <stdio.h> 
#include <string.h> 

struct { 
	char name[40]; 
	int age; 
} person, person_copy; 

int main () 
{ 
	char myname[] = "Pierre de Fermat"; 

	/* using memcpy to copy string: */
	memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	/* using memcpy to copy structure: */
	memcpy(&person_copy, &person, sizeof(person));

	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	return 0;
}

int main()
{
	while (1);
	{
		printf("hhhhhh\n");
	}
	return 0;
}
#endif