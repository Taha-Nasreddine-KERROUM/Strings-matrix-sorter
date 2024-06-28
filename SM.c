#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void pswap ( char **p, 
                        char **q )
{
    char *temp = *p;
    *p = *q;
    *q = temp;
}

void readNstrings ( char ***str, int n ) {
    *str = ( char** ) malloc ( n * sizeof( char* ) );
    if ( *str == NULL ) {
        puts(" memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    for ( char **st = *str; st < *str + n; ++st ) {
        char s[100];
        long int u = st - *str;
        printf(" string %ld: ", u + 1);
        gets(s);
        *st = ( char* ) malloc ( strlen( s ) + 1 );
        if ( *st == NULL ) {
            puts(" memory allocation failed");
            exit(EXIT_FAILURE);
        }
        strcpy(*st, s);
        while (u > 0 && ( strcasecmp( *(*str + u - 1) , *(*str + u) ) > 0 ) ) {
            pswap((*str + u), (*str + u - 1));
            u--;
        }
    }
}

void readWsort ( char ***str, int *n ) {
    int u = *n;
    *str = ( char** ) realloc ( *str, ++(*n) * sizeof( char* ) );
    char s[100];
    gets(s);
    *(*str + u) = ( char* ) malloc ( strlen( s ) + 1 );
    strcpy(*(*str + u), s);
    while (u > 0 && ( strcasecmp( *(*str + u - 1) , *(*str + u) ) > 0 ) ) {
        pswap((*str + u), (*str + u - 1));
        u--;
    }
}

void display ( char **str, int n ) {
    for ( char **s = str; s < str + n; ++s )
        puts(*s);
}

int main()
{
    char **string;
    int n;
    printf(" how many strings you want sweet heart? .");
    scanf("%d%*c", &n);
    readNstrings( &string, n );
    printf(" here's your %d strings sorted\n", n);
    display( string, n );
    printf(" now enter your string you wanna add: ");
    readWsort( &string, &n );
    printf(" here's your new %d strings sorted\n", n);
    display( string, n );
    return 0;
}
