#include <iostream>

const char * _strcpy ( char * dest, const char * src )
{
    for ( int i = 0; dest[i] = src[i]; i++ ) ;

    return dest;
}

const char * _strcpy_ ( char * dest, const char * src )
{
    while ( *dest++ = *src++ ) ;
}

int main ()
{
    char src[1024], dest[1024];

    std::cout << "enter any string : ";
    std::cin.getline ( src, 1023 );

    std::cout << "copied string is : " << _strcpy ( dest, src );

    return 0;
}
