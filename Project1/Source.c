// projekt 2.c -- Denis Vladimír Bílik, 12.4.2018 08:41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sirka, dlzka, dlzka1, polica = 0, stlpec = 0;
char nacitanie[201], sklad[201][201];

void nulovanie() {
	int m, n;
	sirka = 0;
	dlzka = 0;
	dlzka1 = 0;
	polica = 0;
	stlpec = 0;
	for (m = 0; m < 201; m++) {
		for (n = 0; n < 201; n++) {
			sklad[m][n] = '\0';
			nacitanie[m] = '\0';
		}
	}
}

void hladaj_cestu() {
	int i, pohyb = 0;
	polica = 0;
	stlpec = 1;
	sklad[0][1] = '0';
	while (polica != dlzka - 1 && stlpec != sirka - 1) {
		pohyb = 0;
		if (sklad[polica - 1][stlpec] == '.' && pohyb == 0) {
			polica--;
			pohyb = 1;
		}
		if (sklad[polica + 1][stlpec] == '.' && pohyb == 0) {
			polica++;
			pohyb = 1;
		}
		if (sklad[polica][stlpec + 1] == '.' && pohyb == 0) {
			stlpec++;
			pohyb = 1;
		}
		if (sklad[polica][stlpec - 1] == '.' && pohyb == 0) {
			stlpec--;
			pohyb = 1;
		}
		sklad[polica][stlpec] = '0';
	}
}


void vypis_sklad() {
	int i, j;
	printf("Vypis: \n");
	for (j = 0; j <= dlzka; j++) {
		for (i = 0; i < sirka; i++) {
			printf("%c", sklad[j][i]);
		}
		printf("\n");
	}


}
void nacitaj_bludisko() {
	int i, j;
	sirka = strlen(nacitanie);
	for (i = 0; i < sirka; i++) {
		sklad[0][i] = nacitanie[i];
	}
	for (i = 0; i < 201; i++)
		nacitanie[i] = '\0';
	while (gets(&nacitanie) != NULL)
	{
		if (!strcmp(nacitanie, "----"))
			break;
		strcpy(&sklad[dlzka1][0], nacitanie);
		for (i = 0; i < 201; i++)
			nacitanie[i] = '\0';
		dlzka1++;
	}
	dlzka = dlzka1;
}



int main(void) {
	int i, j;
	while (gets(&nacitanie) != NULL) {
		nacitaj_bludisko();
		//hladaj_cestu (); 
		vypis_sklad();
		nulovanie();
	}
	printf("\n");
	return 0;
}