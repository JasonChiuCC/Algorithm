
/*
home
 -sub1
   -A
   -B
 -sub2
   -C
   -D
*/
struct DIR {
	char name[256];
}

// return file/DIR
struct DIR* opendir(char* name)     {...}

// return file/DIR under input
struct DIR* readir (struct DIR* dir){...}

// Example : input = home
void tree(char* name)
{
	struct DIR *pDir_Curr;
	struct DIR *pDir_Entry;
	
	// Check
	if( opendir(name) == NULL ) return;
	
	// Loop Current folder
	while( (pDir_Entry = readir(pDir_Curr)) != NULL )
	{
		if ( strcmp(entry->d_name, ".")  == 0 || 
		     strcmp(entry->d_name, "..") == 0)
		{
		    continue;
		}
   
        // Display Current folder name
        printf(" %s \n", pDir_Entry->name );
        tree( pDir_Entry->name );
	}
	return;
}
