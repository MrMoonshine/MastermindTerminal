#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
	int hlen;
	int unpri;
	int g, x, xy, y, d;
	int stat = 0;
	int ver = 0;
	int zuf[4]= {0,0,0,0};
	int cti[4]= {0,0,0,0};
	char swi[4];
	char clearc[10]="\x1b[0m";
	int out[4] = {0,0,0,0};

int printline1()
{
	int n;
	printf("\u2554");
	for(n = 0;n<50;n++)
	printf("\u2550");

	printf("\u2557");
}

int printline2()
{
int n = 0;
for(n = 0;n<unpri;n++);
	printf("\u2550");
}

int printline3()
{
        int n;
        printf("\u2560");
        for(n = 0;n<50;n++)
        printf("\u2550");

        printf("\u2563");
}

int printline4()
{
        int n;
        printf("\u2559");
        for(n = 0;n<50;n++)
        printf("\u2500");

        printf("\u255C");
}

int printline5()
{
        int n;
        printf("\u255A");
        for(n = 0;n<50;n++)
        printf("\u2550");

        printf("\u255D");
}


int printspace()
{
	int w = 0;
for(w = 0;w<19-hlen;w++)
{
printf(" ");
}
printf("\u2551");
}

int gewonnen()
{
		char *outcol[6] =
	{
		"\x1b[34m",
		"\x1b[31m",
		"\x1b[32m",
		"\x1b[33m",
		"\x1b[35m",
		"\x1b[36m",
	};
	char **ocol;
	ocol = outcol;

	printf("\n\u2551\x1b[32mDu hast mit %d Versuchen gewonnen!\x1b[0m                 \u2551",ver);
	printf("\n\u2551 Es war: ");
for(x=0;x<4;x++)
{
	printf("%sO",*(ocol+zuf[x]));
}
	printf("                                     %s\u2551\n",clearc);
	printline5();
	stat = 1;
}


int verloren()
{
	char *outcol[6] =
	{
		"\x1b[34m",
		"\x1b[31m",
		"\x1b[32m",
		"\x1b[33m",
		"\x1b[35m",
		"\x1b[36m",
	};
	char **ocol;
	ocol = outcol;
	
	printf("\n\u2551\x1b[31mDu hast verloren!\x1b[0m Es war: ");
for(x=0;x<4;x++)
{
	printf("%sO ",*(ocol+zuf[x]));
}
	printf("                %s\u2551\n",clearc);
	printline5();	
}

int eua()//einlesen und ausgeben
{
	char *outcol[6] =
	{
		"\x1b[34m",
		"\x1b[31m",
		"\x1b[32m",
		"\x1b[33m",
		"\x1b[35m",
		"\x1b[36m",
	};
	char **ocol;
	ocol = outcol;
	ver++;
	printf("\n\u2551Farbreihenfolge eingeben:                         \u2551\n");
	printline4();
	printf("\n");
	scanf("%s",&swi);

//In Integer "umwandeln"
for(x=0;x<4;x++)
{
switch(swi[x])
{
	case 'a': cti[x]=0; break;
	case 's': cti[x]=1; break;
	case 'd': cti[x]=2; break;
	case 'f': cti[x]=3; break;
	case 'g': cti[x]=4; break;
	case 'h': cti[x]=5; break;
	default: printf("\n\x1b[31mFalsche eingabe...\x1b[0m\n"); cti[x]=0; break; break;
}
}
//OUTPUT ausrechen-----------------------------------------
for(y = 0;y<4;y++)
{
	out[y] = 0;
	for(x=0;x<4;x++)
	{
	if(cti[y]==zuf[x])
	{
		out[y] = 1;
	}
	}

if(cti[y]==zuf[y])
{
		out[y]=2;
}

}
}

int ausg()
{
	char *outcol[6] =
	{
		"\x1b[34m",
		"\x1b[31m",
		"\x1b[32m",
		"\x1b[33m",
		"\x1b[35m",
		"\x1b[36m",
	};
	char **ocol;
	ocol = outcol;
	char *acol[] =
	{
		"\x1b[31m",
		"\x1b[33m",
		"\x1b[32m",
	};
	char **ucol;
	ucol = acol;
	
	printf("\u2554");
	unpri = 9;;
for(x = 0;x<unpri;x++)
{
	printf("\u2550");
}
	printf("\u2566");
	printf("\u2550\u2550");
	printf("\u2566");
for(x = 0;x<unpri;x++)
{
        printf("\u2550");
}

	printf("\u2557");
	printf("\n\u2551 ");
for(x=0;x<4;x++)
{
	printf("%sO ",*(ocol + cti[x]));
}
	printf("%s\u2551%so%so%s\u2551Versuche:\u2551\n",clearc,*(ucol+out[0]),*(ucol+out[1]),clearc);
	printf("\u2551         \u2551%so%so%s\u2551",*(ucol+out[2]),*(ucol+out[3]),clearc);
switch (xy)
{
	case 3:		printf("   \x1b[33m%d%s     \u2551\n",xy-1,clearc); break;
	case 2:		printf("   \x1b[35m%d%s     \u2551\n",xy-1,clearc); break;
	case 1:		printf("   \x1b[31m%d%s     \u2551\n",xy-1,clearc); break;
	default:	printf("   %d     \u2551\n",xy-1); break;
}
	printf("\u2560");
	unpri = 9;
for(x = 0;x<unpri;x++)
{
        printf("\u2550");
}
	printf("\u2569");
	printf("\u2550");
	printf("\u2550");
	printf("\u2569");
	unpri = 9;
for(x = 0;x<unpri;x++)
{
        printf("\u2550");
}
	printf("\u2569");
	unpri = 27;
for(x = 0;x<unpri;x++)
{
        printf("\u2550");
}
	printf("\u2557");
	g = 0;
//gewinnpunkte
for(x=0;x<4;x++)
{
if(cti[x]==zuf[x])
{
		g++;
}
}
}
int zufgen()
{
do
{
for(x=0;x<4;x++)
{
	zuf[x] = rand()%6;
}
	d = 0;

for(y = 0;y<4;y++)
{
for(x=0;x<4;x++)
{
		if(zuf[y]==zuf[x])
		{
			d++;
		}
}
}
}while(d > 4);
}

int start()
{
	char *outcol[6] =
	{
		"\x1b[34m",
		"\x1b[31m",
		"\x1b[32m",
		"\x1b[33m",
		"\x1b[35m",
		"\x1b[36m",
	};
	char **ocol;
	ocol = outcol;
	char hostname[1023];
	hlen = gethostname(hostname, 1024);
	
	printline1();
	printf("\n\u2551%s                Mastermind-Spiel                  %s\u2551\n",*(ocol+5),clearc);
	printf("\u2551                 Hallo %s%s%s!",*(ocol+2),hostname,clearc);
	printspace();
	printf("\n\u2560");
	unpri = 16;
for(x = 0;x<unpri;x++)
{
	printf("\u2550");
}
	printf("\u2566");
	unpri = 33;
for(x = 0;x<unpri;x++)
{
        printf("\u2550");
}

	printf("\u2563");
	printf("\n\u2551Erklärung:      \u2551%so%s: Position:Falsch Farbe:Falsch  \u2551\n",*(ocol+1),clearc);
	printf("\u2551                \u2551%so%s: Position:Falsch Farbe:Richtig \u2551\n",*(ocol+3),clearc);
	printf("\u2551                \u2551%so%s: Position:Richtig Farbe:Richtig\u2551\n",*(ocol+2),clearc);
	printf("\u2560");
	unpri = 16;
for(x = 0;x<unpri;x++)
{
        printf("\u2550");
}
        printf("\u2569");
        unpri = 33;
for(x = 0;x<unpri;x++)
{
        printf("\u2550");
}

        printf("\u2563");

	printf("\n\u2551%sDieses Spiel wird mit 4 Stellen Gespielt%s          \u2551\n",*(ocol+0),clearc);
	printline3();
	printf("\n\u2551%sFalsche eingabe zählt als Fehlversuch!!!%s          \u2551\n",*(ocol+3),clearc);
	printline3();
        printf("\n\u2551Welche Tasten werden benutzt?                     \u2551");
        printf("\n\u2551%s A = Blau,%s S = Rot, %sD = Grün%s                      \u2551",*(ocol+0),*(ocol+1),*(ocol+2),clearc);
        printf("\n\u2551%s F = Gelb,%s G = Magenta , %sH = Cyan       %s          \u2551\n",*(ocol+3),*(ocol+4),*(ocol+5),clearc);
        printline3();
	printf("\n\u2551%s",*(ocol+4));
	unpri = 50;
for(x = 0;x<unpri;x++)
{
	printf("\u2504");
}
	printf("%s\u2551\n",clearc);
	printline3();
	
}
//MAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAIN
int main(void)
{
	//Blau,Rot,Grün,Gelb,Magenta,Cyan
	char *outcol[6] =
	{
		"\x1b[34m",
		"\x1b[31m",
		"\x1b[32m",
		"\x1b[33m",
		"\x1b[35m",
		"\x1b[36m",
	};

	char **ocol;
	ocol = outcol;
/*DARSTELLUNG

+---------+--+---------+
| O O O O |oo|Versuche:|
|         |oo|   X     |
+---------+--+---------+

*/
	system("clear");
	start();
	srand(time(NULL));
	zufgen();
//Versuche,Einlesungen
for(xy = 7;xy>0;xy--)
{
	eua();
	ausg();
//output auf 0 setzen
g = 0;
for(x=0;x<4;x++)
{
if(cti[x]==zuf[x])
{
		g++;
}
	out[x]=0;
	cti[x]=0;
}

if(g==4)
{
	gewonnen();
}
else
{
	g = 0;
}
if(xy == 1)
{
	verloren();
	break;
}

if(stat == 1)
{
		break;
}
}

	printf("\x1b[0m\n\n");
}
