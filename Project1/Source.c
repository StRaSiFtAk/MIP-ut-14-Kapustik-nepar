// projekt 2.c -- Denis Vladimír Bílik, 12.4.2018 08:41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sirka, polica = 0, stlpec = 0;
char nacitanie[201], sklad[201][201];




void vypis_sklad() {
	int i, j;

	for (j = 0; j <= 4; j++) {
		for (i = 0; i < sirka; i++) {
			printf("%c", sklad[j][i]);
		}
		printf("\n");
	}

}
void nacitaj_bludisko() {
	int i = 0, j;
	sirka = 0;
	scanf("%s", &nacitanie);
	scanf("\n");
	sirka = strlen(nacitanie);
	for (j = 0; j < sirka; j++) {
		sklad[0][j] = nacitanie[j];
	}
	polica = 1;

	while (scanf("%c", &sklad[polica][stlpec]) > 0) {
		//printf("%c",sklad[polica][stlpec]);
		stlpec++;
		i++;
		if (i == sirka) {
			scanf("\n");
			i = 0;
			stlpec = 0;
			polica++;
		}
	}
}



int main(void) {
	int i, j;

	nacitaj_bludisko();
	vypis_sklad();
	printf("\n");
	return 0;
}