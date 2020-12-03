

struct DIR {
	char name[256];
}

struct DIR* opendir(char* name){...}
struct DIR* readir(struct DIR* dir){...}


void tree(char* name)
{
	struct DIR *pDir_Curr;
	struct DIR *pDir_Next;
	
	if( opendir(name) == NULL ) return;
	
	pDir_Curr = opendir(name);
	printf("%s\n", pDir_Curr->name );

	pDir_Next = readir(pDir_Curr);
	tree( pDir_Next->name );
	return;
}
