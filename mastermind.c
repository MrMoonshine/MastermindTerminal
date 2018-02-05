#include<stdlib.h>
#include<stdio.h>
#include<time.h>
/*#include<unistd.h>*/
int main(void)
{
/*DARSTELLUNG

+---------+--+---------+
| O O O O |oo|Versuche:|
|         |oo|   X     |
+---------+--+---------+

*/
	printf("+----------------+\n");
	printf("|\x1b[36mMastermind-Spiel\x1b[0m|\n");
	printf("+----------------+---------------------------------+\n");
	printf("|Erklärung:      |\x1b[31mo\x1b[0m: Position:Falsch Farbe:Falsch  |\n");
	printf("|                |\x1b[33mo\x1b[0m: Position:Falsch Farbe:Richtig |\n");
	printf("|                |\x1b[32mo\x1b[0m: Position:Richtig Farbe:Richtig|\n");
	//BLAU;ROT;GRÜN;GELB;MAGENTA;Cyan;
	int color[6] = {34,31,32,33,35,36};
	printf("+----------------+---------------------------------+\n");
	printf("|\x1b[33mFalsche eingabe zählt als Fehlversuch!!!\x1b[0m          |\n");
	printf("+--------------------------------------------------+\n");

        printf("|Welche Tasten werden benutzt?                     |\n");
        printf("|\x1b[%dmA = blau, \x1b[%dmS = Rot, \x1b[%dmD = Grün\x1b[0m                       |\n",color[0],color[1],color[2]);
        printf("|\x1b[%dmF = Gelb,\x1b[%dm G = Magenta , \x1b[%dmH = Cyan       \x1b[0m           |\n",color[3],color[4],color[5]);
        printf("+--------------------------------------------------+\n");
	printf("|\x1b[35m<<<<<<<<<<<<<<<<<<<<<<=>>>>>>>>>>>>>>>>>>>>>>>>>>>\x1b[0m|\n");
	printf("+--------------------------------------------------+\n");

//Hier Wird der Farbcode Definiert
	int x = 0;
	int zuf[4];
	int cti[4]; //CTI ist das int array was aus den characters gebildet wird...
	srand(time(NULL));
for(x=0;x<4;x++)
{
	zuf[x] = rand()%6;
}
	int *pzf;
	pzf = zuf;

for(x=0;x<4;x++)
{
	printf("\x1b[%dm\t%d\t",color[zuf[x]], *pzf++);
	printf("\x1b[0m");
}
	char swi[4];
	int xy,y,g=0;
//OUTPUT ARRAY =>
	int out[4]={0,0,0,0};
	int outcol[4]={31,33,32};
//EINLESEN UND VERGLEICHEN......................7x
//Einlesen
for(xy = 7;xy>0;xy--)
{
	printf("\n|Farbreihenfolge eingeben:                         |\n");
	printf("+--------------------------------------------------+\n");
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
//OUTPUT ausrechen
for(y = 0;y<4;y++)
{
for(x=0;x<4;x++)
{
if(cti[y] == zuf[x])
{
	out[y]++;
}
}
if(cti[y]==zuf[y])
{
	out[y]++;
}
for(x=0;x<4;x++)
{
if(out[y]>2)
{
	out[y]=2;
}
}
	g = g + out[y];
}

if(g==8)
{
	printf("\n\x1b[32mDu hast Gewonnen!\x1b[0m");
	break;
}
//Ergebnis oder Hinweis aneigen
	printf("+---------+--+---------+\n");
	printf("| ");
for(x=0;x<4;x++)
{
	printf("\x1b[%dmO ",color[cti[x]]);
}
	printf("\x1b[0m|\x1b[%dmo\x1b[%dmo\x1b[0m|Versuche:|\n",outcol[out[0]],outcol[out[1]]);
	printf("|         |\x1b[%dmo\x1b[%dmo\x1b[0m|   %d     |\n",outcol[out[2]],outcol[out[3]],xy);
	printf("+---------+--+---------+---------------------------+");
//output auf 0 setzen
for(x=0;x<4;x++)
{
	out[x]=0;
}
	g = 0;
if(xy == 1)
{
	printf("\n\x1b[31mDu hast verloren!\x1b[0m");
}
//------------------
}

	printf("\x1b[0m\n\n");
}
