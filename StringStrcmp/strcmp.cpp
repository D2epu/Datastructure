#include <iostream>

int _strcmp ( const char * str_1, const char * str_2 )
{
    int i;

    for ( i = 0; str_1[i] == str_2[i]; i++ ) ;

    if ( str_1[i] == 0 ) return 0;

    return str_1[i] - str_2[i];
}

int _strcmp_ ( const char * str_1, const char * str_2 )
{
    while ( *str_1++ == *str_2++ ) ;

    if ( *( str_1 - 1 ) == 0 ) return 0;

    return *( str_1 - 1 ) - *( str_2 - 1 );
}

int main ()
{
    char str_1[1024], str_2[1024];

    std::cout << "enter first string : ";
    std::cin.getline ( str_1, 1023 );

    std::cout << "enter second string : ";
    std::cin.getline ( str_2, 1023 );

    if ( _strcmp ( str_1, str_2 ) == 0 ) std::cout << "both strings are equal";
    else if ( _strcmp ( str_1, str_2 ) > 0 )  std::cout << str_1 << " is greater than " << str_2;
    else if ( _strcmp ( str_1, str_2 ) < 0 )  std::cout << str_1 << " is less than " << str_2;

    return 0;
}
