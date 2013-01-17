/*
*	Código responsável por gerenciar a impressão de caracterres
* 	no modo protegido. 
*	http://wiki.osdev.org/Printing_To_Screen
*
*/

// Aponta para o dado na pilha que deverá ser lido.
typedef char *va_list;

// Desloca o ponteiro sizeof(type) bytes.
#define next_arg(p, type) p=p+sizeof(type);

// Imprime um caracter na tela
#define printc(c,video) *video++ = c; *video++=0x0a;

// Local da memória onde a tela é mapeada
#define VIDEO 0xB8000

/*
*   Função getInt retorna um inteiro (4 bytes) a partir de um ponteiro.
*   O ponteiro deve estar apontando para o primeiro byte de um inteiro.
*/ 
int getInt(char *p){
	int* i = (int*)p;
	return (i[0]);
}

/*
*  Imprime na tela o valor (value) de um inteira convertido em uma base (base)
*  Como durante a impressão o valor do endereço video é alterado. A função retorna o
*  novo valor de video. 
*/
char* printint( int value, char * video, int base)
{
    int isNegative = (base==10) & (value < 0);
    char *p= (char*)0x400000;			//ATENÇÃO: Como não existe uma heap por Kernel
						// to pegando um valor alta aleatório. Deve ser 
						// arrumado assim que possível.
    char *t;
    t=p;

    do
    {
        *p++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    } while ( value );

    if(isNegative){
    	printc('-',video);
    }

    while(p-- != t){
	printc(*p,video);
    }

    return video;

}

/*
*	Mesma função do printf no C. Recebe uma String e a posição a ser impresso
*	x e y; A string contem marcas que são substituidos pelos valores passados;
*	Possui suporte para:
*		%d Inteiro
*		%b Binário de um inteiro
*		%x Hexadecimal de um inteiro
*		%c Caracter
*		%s String
*		%% Valor de %
*		\n Quebra de linha
*		
*/
void print(const char *str,int x, int y,...){

	char *video = ((char *) VIDEO) + 160 * x + y;

	char *s;

	
	va_list va = (char*)(&y + 1);
	while(*str != 0){
		if(*str != '%'){
			
			if(*str == 0x0a){	// Quebra de linha "\n"
				int v = (int)(video - VIDEO);
				video+=160-(v-160*(v/160));
			}else{
	 	        	printc(*str,video);
			}			
			str++;
			


		}else {
		
			switch(*++str)
			{
				case 'd':
					video = printint(getInt(va),video,10);
					next_arg(va,int);
					break;
				case 'c':
					printc((char)*va,video);
					next_arg(va,int);
					break;
				case 'x':
					video = printint(getInt(va),video,16);
					next_arg(va,int);
					break;
				case 'b':
					video = printint(getInt(va),video,2);
					next_arg(va,int);
					break;
				case '%':
					printc('%',video);
					break;
				case 's':
					s = (char*) (getInt(va));
					while(*s != 0){
						printc((char)*s++,video);
					}
					next_arg(va,int);
					break;
				
			}
			
			str++;	
		}
	}
}



/*
*	Limpa a tela escrevendo o valor 0x0 em todos os espaços.
*/
void clearscreen() {

    char *video = (char *) VIDEO;
    int i;
    for(i=0;i<20000;i++)
	*video++= 0x0;

}
