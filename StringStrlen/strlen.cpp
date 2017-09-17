#include <iostream>

int _strlen_ ( const char * str )
{
    const char * p = str;

    while ( *p++ ) ;

    return p - str - 1;
}

int _strlen ( const char * str )
{
    int len;

    for ( len = 0; str[len]; len++ ) ;

    return len;
}

int main ()
{
    char str[1024];

    std::cout << "enter any string : ";
    std::cin.getline ( str, 1023 );

    std::cout << "length of '" << str << "' : " << _strlen ( str );

    return 0;
}
