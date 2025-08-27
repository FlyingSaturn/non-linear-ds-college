#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool valid_identifier(char email[], const int start, const int end);
bool contains_domain_name(char email[]);
bool contains_extension(char emai[]);
bool perfect_extension(char email[], const int start, const int end);

int main()
{
    const int MAX = 100;
    char email[MAX];
    printf("Enter the email address: ");
    fgets(email, MAX, stdin);
    if (int l = strlen(email); email[l - 1] == '\n')
        email[l - 1] = '\0';
    if (!contains_domain_name(email))
    {
        printf("Invalid. (Reason: Domain name does not exist)\n");
        return 0;
    }
    char *fu = strchr(email, '@');
    if (!valid_identifier(email, 0, fu - email))
    {
        printf("Invalid. (Reason: Invalid user name - not a valid identifier)\n");
        return 0;
    }
    if (!contains_extension(email))
    {
        printf("Invalid. (Reason: Invalid domain name - no extension)\n");
        return 0;
    }
	char *dot = strchr(email, '.');
	if (!valid_identifier(email, fu - email + 1, dot - email))
	{
		printf("Invalid. (Reason: Invalid domain name - not a valid identifier)\n");
		return 0;
	}
    if (!perfect_extension(email, fu - email + 1, MAX))
    {
        printf("Invalid. (Reason: Invalid domain name - wrong extension)\n");
        return 0;
    }
    printf("Valid.\n");
}

bool valid_identifier(char email[], const int start, const int end)
{
    // If nothing is there
    if (start >= end)
        return false;
    // A special condition
    if (!isalpha(email[start]) && email[start] != '_')
            return false;
    // The general condition
    for (int i = start + 1; i < end; i++)
        if (!isalnum(email[i]) && email[i] != '_')
            return false;
    return true;
}

bool contains_domain_name(char email[])
{
	if (strchr(email, '@') == NULL)
		return false;
	return true;
}

bool contains_extension(char email[])
{
	if (strchr(email, '.') == NULL)
		return false;
	return true;
}

bool perfect_extension(char email[], const int start, const int end)
{
	char *domain = strchr(email, '.');
	const char *valid[] = {".com", ".in", ".ac.in", ".edu", ".org"};

	for (int i = 0, count = sizeof(valid) / sizeof(valid[0]); i < count; i++)
		if (strcmp(domain, valid[i]) == 0)
			return true;
	return false;
}
