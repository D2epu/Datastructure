#include <iostream>

const char * _strcpy ( char * str_1, const char * str_2 )
{
    for ( int i = 0; str_1[i] = str_2[i]; i++ ) ;

    return str_1;
}

int _strlen ( const char * str )
{
    int len;

    for ( len = 0; str[len]; len++ ) ;

    return len;
}

const char * _strcat ( char * str_1, const char * str_2 )
{
    _strcpy ( str_1 + _strlen ( str_1 ), str_2 );

    return str_1;
}

int main ()
{
    char str_1[1024], str_2[1024];

    std::cout << "enter first string : ";
    std::cin.getline ( str_1, 1023 );

    std::cout << "enter second string : ";
    std::cin.getline ( str_2, 1023 );

    std::cout << "concatented string is : " << _strcat ( str_1, str_2 );

    return 0;
}
