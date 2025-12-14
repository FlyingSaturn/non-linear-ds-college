#include <stdio.h>
#include <math.h>
#include <limits.h>
#define A 0.6180339887
#define EMPTY INT_MAX

int primary_hash(int funcop, int k, int m);
int division_method(int k, int m);
int multiplication_method(int k, int m);
int mid_square_method(int k, int m);
void collision_handle(int collisionop, int a[], int h_k, int k, int m);
void linear_probing(int a[], int h_k, int k, int m);
void quadratic_probing(int a[], int h_k, int k, int m);
void double_hashing(int a[], int h1_k, int h2_k, int k, int m);
void search_key(int a[], int m, int k, int funcop, int collisionop);

int main(void)
{
	int m;
	printf("Hash Table Size (m): ");
	scanf("%d", &m);
	int table[m];
	for (int i = 0; i < m; i++)
		table[i] = EMPTY;

	int funcop;
	do {
	printf("Hash functions:\n1. Division method\n2. Multiplication method\n3. Mid-square method\nChoice: ");
	scanf("%d", &funcop);
	} while (funcop < 1 || funcop > 3);
	
	int collisionop;
	do {
	printf("Collision Handling Methods:\n1. Linear probing\n2. Quadratic probing\n3. Double hashing\nChoice: ");
	scanf("%d", &collisionop);
	} while(collisionop < 1 || collisionop > 3);

	int N;
	printf("N: ");
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		printf("Key %d: ", i + 1);
		int k;
		scanf("%d", &k);
		int h_k = primary_hash(funcop, k, m);
		collision_handle(collisionop, table, h_k, k, m);
	}
	printf("Load factor : %.2f", ((N * 1.0d)/m));

	char choice;
    do {
        int k;
        printf("\nEnter key to search: ");
        scanf("%d", &k);
        
        // We reuse the logic inside this function
        search_key(table, m, k, funcop, collisionop);
        
        printf("Search another? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
}

int primary_hash(int funcop, int k, int m)
{
	switch (funcop)
	{
		case 1:
			return division_method(k, m);
		case 2:
			return multiplication_method(k, m);
		case 3:
			return mid_square_method(k, m);
	}
}

int division_method(int k, int m)
{
	return k%m;
}

int multiplication_method(int k, int m)
{
	return floor(m * ((k * A) - floor(k * A)));
}

int mid_square_method(int k, int m)
{
	unsigned long long sq = (unsigned long long) k * k;
	int total_digits = (sq == 0) ? 1 : (int) floor(log10(sq)) + 1;
	int digits_needed = ceil(log10(m)); // 0 to m - 1
	int cut_right = (total_digits - digits_needed) / 2;	// that division is a geometrical estimate
	if (cut_right < 0) cut_right = 0;
	unsigned long long divisor = pow(10, cut_right);
	unsigned long long mod = pow(10, digits_needed);
	unsigned long long middle = (sq / divisor) % mod;
	return (int) middle % m;
}

void collision_handle(int collisionop, int a[], int h_k, int k, int m)
{
	switch(collisionop)
	{
		case 1:
			linear_probing(a, h_k, k, m);
			break;
		case 2:
			quadratic_probing(a, h_k, k, m);
			break;
		case 3:;
			int h2_k = 1 + (k % (m - 1));
			double_hashing(a, h_k, h2_k, k, m);
	}
}

void linear_probing(int a[], int h_k, int k, int m)
{
	for (int i = 0; i < m; i++)
	{
		int hi_k = (h_k + i) % m;
		printf("Probe %d: Checking index %d...\t", i+1, hi_k);
		if (a[hi_k] == EMPTY) 
		{
			a[hi_k] = k;
			printf("Inserted key %d at index %d\n", k, hi_k);
			return;
		}
		else
		{
			printf("Collision at index %d\n", hi_k);
		}
	}
	printf("Error: Table full.\n", k);
}

void quadratic_probing(int a[], int h_k, int k, int m)
{
	for (int i = 0; i < m; i++)
	{
		int hi_k = (h_k + i*i) % m;
		printf("Probe %d: Checking index %d...\t", i+1, hi_k);
		if (a[hi_k] == EMPTY) 
		{
			a[hi_k] = k;
			printf("Inserted key %d at index %d\n", k, hi_k);
			return;
		}
		else
		{
			printf("Collision at index %d\n", hi_k);
		}
	}
	printf("Error: Table full.\n", k);
}

void double_hashing(int a[], int h1_k, int h2_k, int k, int m)
{
	for (int i = 0; i < m; i++)
	{
		int hi_k = (h1_k + i * h2_k) % m;
		printf("Probe %d: Checking index %d...\t", i+1, hi_k);
		if (a[hi_k] == EMPTY) 
		{
			a[hi_k] = k;
			printf("Inserted key %d at index %d\n", k, hi_k);
			return;
		}
		else
		{
			printf("Collision at index %d\n", hi_k);
		}
	}
	printf("Error: Table full.\n", k);
}

void search_key(int a[], int m, int k, int funcop, int collisionop) {
    // 1. Re-calculate the primary hash
    int h_k = primary_hash(funcop, k, m);
    
    // 2. Determine secondary hash if needed
    int h2_k = 0;
    if (collisionop == 3) {
        h2_k = 1 + (k % (m - 1));
    }

    printf("\nSearching for Key %d:\n", k);

    // 3. Run the exact same loop as insertion
    for (int i = 0; i < m; i++) {
        int idx = 0;
        
        // MIRROR THE MATH from Insertion
        if (collisionop == 1)      idx = (h_k + i) % m;
        else if (collisionop == 2) idx = (h_k + (i*i)) % m;
        else if (collisionop == 3) idx = (h_k + (i*h2_k)) % m;
        
        printf("Probe %d: Checking index %d...", i+1, idx);
        
        // Case A: Found the key
        if (a[idx] == k) {
            printf(" FOUND!\n");
            printf("Key %d found at index %d after %d probes.\n", k, idx, i+1);
            return;
        }
        
        // Case B: Found an EMPTY slot (Stop searching)
        if (a[idx] == EMPTY) {
            printf(" EMPTY. (Stop)\n");
            printf("Key %d NOT found (hit empty slot).\n", k);
            return;
        }
        
        // Case C: Collision (Keep going)
        printf(" Occupied (Mismatch).\n");
    }
    
    printf("Key %d NOT found (scanned entire table).\n", k);
}
