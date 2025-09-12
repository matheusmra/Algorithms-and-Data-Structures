#include<stdio.h>
#include<stdbool.h>

bool isVogal(char linha[], int size)
{
    bool resp = true;

    for(int i = 0; i < size; i++)
    {
        if( ! ( linha[i] == 'a' || linha[i] == 'e' || linha[i] == 'i' || linha[i] == 'o' || linha[i] == 'u' ||
                linha[i] == 'A' || linha[i] == 'E' || linha[i] == 'I' || linha[i] == 'O' || linha[i] == 'U') )
        {
            resp = false;
            i = size;
        }
    }

    return resp;
}

bool isConsoante(char linha[], int size)
{
    bool resp = true;

    for(int i = 0; i < size; i++)
    {
        if( !( linha[i] >= 'a' && linha[i] <= 'z' || linha[i] >= 'A' && linha[i] <= 'Z' ) ) 
        {
            resp = false;
            i = size;
        }
        if( linha[i] == 'a' || linha[i] == 'e' || linha[i] == 'i' || linha[i] == 'o' || linha[i] == 'u' ||
            linha[i] == 'A' || linha[i] == 'E' || linha[i] == 'I' || linha[i] == 'O' || linha[i] == 'U' ) 
        {
            resp = false;
            i = size;
        }
    }

    return resp;
}

bool isInt(char linha[], int size)
{
    bool resp = true;

    for(int i = 0; i < size; i++)
    {
        if( !(linha[i] >= '0' && linha[i] <= '9') )
        {
            resp = false;
            i = size;
        }
    }

    return resp;
}

bool isReal(char linha[], int size)
{
    bool resp = true;
    bool ponto = false;

    for(int i = 0; i < size; i++) 
    {
        if( !(linha[i] >= '0' && linha[i] <= '9') ) 
        {
            if (linha[i] == '.' || linha[i] == ',' && !ponto ) 
            {
                ponto = true;
            } 
            else 
            {
                resp = false;
                i = size;
            }
        }
    }

    if(!ponto)
    {
        resp = false;
    }

    return resp;
}

bool isFim(char linha[])
{
    return(linha[0] == 'F' && linha[1] == 'I' && linha[2] == 'M'  && linha[3] == '\0');
}

int getSize(char linha[])
{
    int cont = 0;
    for(int i = 0; linha[i] != '\0' ; i++)
    {
        cont++;
    }
    return cont-1;
}

//o fgets armazena o \n na string tambem, com este metodo trocamos o \n pelo \0 que fininaliza o array
void removeEnter(char linha[]) {
    int i = 0;
    while (linha[i] != '\0') {
        if (linha[i] == '\n') {
            linha[i] = '\0';
            i--;
        }
        i++;
    }
}

int main()
{
    char linha[100];
    fgets(linha, sizeof(linha), stdin);
    removeEnter(linha);

    while(!(isFim(linha)))
    {
        int length = getSize(linha);
        if(isVogal(linha, length))
        {
            printf("SIM ");
        }
        if(!(isVogal(linha, length)))
        {
            printf("NAO ");
        }

        if(isConsoante(linha, length))
        {
            printf("SIM ");
        }
        if(!(isConsoante(linha, length)))
        {
            printf("NAO ");
        }

        if(isInt(linha, length))
        {
            printf("SIM ");
        }
        if(!(isInt(linha, length)))
        {
            printf("NAO ");
        }

        if(isReal(linha, length))
        {
            printf("SIM ");
        }
        if(!(isReal(linha, length)))
        {
            printf("NAO ");
        }

        printf("\n");

        fgets(linha, sizeof(linha), stdin);
        removeEnter(linha);
    }
    
    return 0;

}