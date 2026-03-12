#include <stdio.h>

void Findvowel(int ch){
    switch (ch)
    {
    case 0x61:
        printf("vowel ");
        break;
    
    default:
        break;
    }
}


void Whatis(int ch)
{
    if((ch>'a'&& ch<'z')||(ch>'Z'|| ch<'Z')){
        printf("alphabet, ");
        if(ch>'a'&& ch<'z')
            printf("lower-case, ");
        if(ch>'Z'|| ch<'Z')
            printf("upper-case ");
        Findvowel(ch);
    }

    if(ch>'!'&& ch<'/')
        printf("symbol (not decimal number, not alphabet)");
    
    if(ch>'0'&& ch<'9')
        printf("decimal number");
    
}

int main(void){
    int ch;
    
    while(ch!='.'){
        printf("Input a character :");
        scanf("%d",&ch);
        Whatis(ch);
        
    }
    
    return 0;
}