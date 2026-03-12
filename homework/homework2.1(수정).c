#include <stdio.h>

void Findvowel(int ch){
    switch (ch)
    {
        case 'a':
        case 'e':
        case 'o':
        case 'i':
        case 'u':
        case 'A':
        case 'E':
        case 'O':
        case 'I':
        case 'U':
            printf("vowel ");
            break;
        
        default:
            break;
    }
}


void Whatis(int ch)
{
    if((ch >= 'a'&& ch <= 'z')||(ch >= 'A' && ch <= 'Z')){
        printf("alphabet, ");
        if(ch >= 'a' && ch <= 'z')
            printf("lower-case, ");
        if(ch >= 'A'&& ch <= 'Z')
            printf("upper-case ");
        Findvowel(ch);
    }

    if(ch >= '!' && ch <= '/')
        printf("symbol (not decimal number, not alphabet)");
    
    if(ch >= '0'&& ch <= '9')
        printf("decimal number");
    
    printf("\n");
}

int main(void){
    char ch;
    
    while(ch != '.'){
        printf("Input a character : ");
        scanf("%c", &ch);
        Whatis(ch);
        
    }
    
    return 0;
}