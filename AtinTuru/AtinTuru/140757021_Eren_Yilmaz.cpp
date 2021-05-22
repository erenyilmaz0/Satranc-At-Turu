#define _CRT_SECURE_NO_WARNINGS //scanf güvenlik hatasý verdiði için bu satýrý yazdým 
#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;
#define SATIR 8
#define SUTUN 8
int duzlem[SATIR][SUTUN];
int yatay[8], dikey[8];
int bulunulanSatir, bulunulanSutun;
int sayac = 1;
int KacIhtimalVar(const int sayi);
int HamleSec();
void Yazdir();

int main()
{
	bulunulanSatir = -1; 
	bulunulanSutun = -1;
	int i, j, sayi;
	yatay[0] = 2;  
	yatay[1] = 1; 
	yatay[2] =-1; 
	yatay[3] =-2; 
	yatay[4] =-2; 
	yatay[5] =-1; 
	yatay[6] = 1; 
	yatay[7] = 2;

	dikey[0] =-1; 
	dikey[1] =-2; 
	dikey[2] =-2; 
	dikey[3] =-1;  
	dikey[4] = 1;  
	dikey[5] = 2; 
	dikey[6] = 2; 
	dikey[7] = 1;
	
	for (i = 0; i<SATIR; i++)
		for (j = 0; j<SUTUN; j++)
			duzlem[i][j] = 0;
		while (bulunulanSatir<0 || bulunulanSatir>SATIR - 1){
		printf("Satir (0-%d) : ", SATIR - 1);
		scanf("%d", &bulunulanSatir);
	}
		while (bulunulanSutun<0 || bulunulanSutun>SUTUN - 1){
		printf("Sutun (0-%d) : ", SUTUN - 1);
		scanf("%d", &bulunulanSutun);
	}
		duzlem[bulunulanSatir][bulunulanSutun] = 1;
	sayac = 1;
	while (1)
	{
		getchar();
		Yazdir();
		sayac++;
		i = HamleSec();
		if (i == 8){
			if (sayac == (SATIR*SUTUN) + 1){
				getchar();
				Yazdir();
			}
			else{
				getchar();
				Yazdir();
			}
			getchar();
			return 0;
		}
		else{
			bulunulanSatir += yatay[i];
			bulunulanSutun += dikey[i];
		}
		duzlem[bulunulanSatir][bulunulanSutun] = sayac;
	}
}

void Yazdir()
{
	int i, j;
	if (sayac == (SATIR*SUTUN) + 1)
		printf("\nTEBRIKLER! \n");
	else    
		printf("sayac : %d \n", sayac);
	for (i = 0; i<SATIR; i++){
		for (j = 0; j<SUTUN; j++){
			if (duzlem[i][j] == 0){
				printf("  .  ");
			}
			else{
				if (duzlem[i][j] == sayac) 
					printf("%d", sayac, 31);
				else
					printf("%3d  ", duzlem[i][j]);
			}
		}
		printf("\n\n");
	}
}

int HamleSec()
{
	int hamle[8];
	int i, kucuk, adet;
	int seviye, seviye_x, seviye_y;
	for (i = 0; i<8; i++){
		if ((bulunulanSatir + yatay[i] >= 0 && bulunulanSatir + yatay[i]<SATIR) 
			&& (bulunulanSutun + dikey[i] >= 0 && bulunulanSutun + dikey[i]<SUTUN))
		{
			if (duzlem[bulunulanSatir + yatay[i]][bulunulanSutun + dikey[i]] == 0)
				hamle[i] = 1;
			else hamle[i] = 0;
		}
		else hamle[i] = 0;
	}
	for (i = 0, kucuk = 8; i<8; i++){
		if (hamle[i] == 1){
			hamle[i] = KacIhtimalVar(i);
			if (hamle[i] == '\0'){
				return i;
			}
			if (hamle[i]<kucuk) kucuk = hamle[i];
		}
	}
	if (kucuk == 8)
		return 8; 
	for (i = 0, adet = 0; i<8; i++){
		if (hamle[i] == kucuk) 
		{
			adet++; seviye = i;
		} 
	}
	if (adet == 1){
		return seviye;
	}
	for (i = 0; i<8; i++) 
	{
		if (hamle[i] == kucuk) 
		{
			seviye_x = bulunulanSatir + yatay[i];
			for (adet = 1; adet <= ((SATIR + 1) / 2); adet++){
				if (seviye_x == adet - 1 || seviye_x == SATIR - 1)
					seviye_x = adet; break;
			}
			seviye_y = bulunulanSatir + dikey[i];
			for (adet = 1; adet <= ((SUTUN + 1) / 2); adet++){
				if (seviye_y == adet - 1 || seviye_y == SATIR - 1)
					seviye_y = adet; break;
			}
			if (seviye_x>seviye_y)
			{
				seviye = seviye_x;
				seviye_x = seviye_y;
				seviye_y = seviye;
			}
			hamle[i] = 10 * seviye_x + seviye_y;
		}
	}
	for (i = 0, kucuk = 10 * SATIR + SUTUN; i<8; i++){
		if (hamle[i]>8){
			if (hamle[i]<kucuk) kucuk = hamle[i];
		}
	}
	for (i = 0; i<8; i++){
		if (hamle[i] == kucuk) return i;
	}
}

int KacIhtimalVar(const int sayi)
{
	int i, adet = 0;
	for (i = 0; i<8; i++)
	{
		if (
			(bulunulanSatir + yatay[sayi] + yatay[i] >= 0 && bulunulanSatir + yatay[sayi] + yatay[i]<8)
			&&
			(bulunulanSutun + dikey[sayi] + dikey[i] >= 0 && bulunulanSutun + dikey[sayi] + dikey[i]<8)
			)
		{
			if (duzlem[bulunulanSatir + yatay[sayi] + yatay[i]][bulunulanSutun + dikey[sayi] + dikey[i]] == 0)
				adet++;
		}
	}
	return adet;
}