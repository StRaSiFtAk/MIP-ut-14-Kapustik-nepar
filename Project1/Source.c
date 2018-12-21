// projekt 2.c -- Denis Vladimír Bílik, 12.4.2018 08:41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sirka, dlzka, dlzka1, polica = 0, stlpec = 0, navrat = 1, riesenie = 0, pocitadlo1, pocitadlo2;
char nacitanie[201], sklad[201][201], sklad1[201][201], ulozene_pozicie_polica[400000], ulozene_pozicie_stlpec[400000], kroky[400000], cesta[400000];

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
			sklad1[m][n] = '\0';
			nacitanie[m] = '\0';
		}
	}
}

void hladaj_cestu() {
	int d = 0, p = 0, l = 0, h = 0, smery = 0, moznost = 0, i=0;
	while (polica == dlzka - 1 && stlpec == sirka - 1) {          //hladá dokiaľ nepríde do ciela
		break;
	}
	
	sklad[0][1] = 'O';
	if (sklad[polica + 1][stlpec] == '.') {          
		d = 1;
		smery++;
	}
	if (sklad[polica][stlpec + 1] == '.') {
		p = 1;
		smery++;
	}
	if (sklad[polica][stlpec - 1] == '.') {
		l = 1;
		smery++;
	}
	if (sklad[polica - 1][stlpec] == '.') {
		h = 1;
		smery++;
	}
	if (smery == 0) {
		if (navrat > pocitadlo1)
			riesenie = 1;
		polica = ulozene_pozicie_polica[pocitadlo1 - navrat];
		stlpec = ulozene_pozicie_stlpec[pocitadlo1 - navrat];
		pocitadlo2 = kroky[pocitadlo1 - navrat];
		navrat++;
	}

	if (smery == 1) {
		if (d == 1) {
			polica++;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'd';
			pocitadlo2++;
		}
		if (l == 1) {
			stlpec--;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'l';
			pocitadlo2++;
		}
		if (p == 1) {
			stlpec++;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'p';
			pocitadlo2++;
		}
		if (h == 1) {
			polica--;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'h';
			pocitadlo2++;
		}
	}
	if (smery > 1) {
		navrat = 1;
		if (ulozene_pozicie_polica[pocitadlo1 - 1] == polica && ulozene_pozicie_stlpec[pocitadlo1 - 1] == stlpec)
			i++;
		else {
			ulozene_pozicie_polica[pocitadlo1] = polica;
			ulozene_pozicie_stlpec[pocitadlo1] = stlpec;
			kroky[pocitadlo1] = pocitadlo2;
			pocitadlo1++;
		}
	}
	if (smery > 1) {
		if (p == 1 && moznost == 0) {
			stlpec++;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'p';
			pocitadlo2++;
			moznost++;
		}
		if (d == 1 && moznost == 0) {
			polica++;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'd';
			pocitadlo2++;
			moznost++;
		}
		if (l == 1 && moznost == 0) {
			stlpec--;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'l';
			pocitadlo2++;
			moznost++;
		}
		if (h == 1 && moznost == 0) {
			polica--;
			sklad[polica][stlpec] = 'O';
			cesta[pocitadlo2] = 'h';
			pocitadlo2++;
			moznost++;
		}
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
		sklad1[0][i] = nacitanie[i];
	}
	for (i = 0; i < 201; i++)
		nacitanie[i] = '\0';
	while (gets(&nacitanie) != NULL)
	{
		if (!strcmp(nacitanie, "----"))
			break;
		strcpy(&sklad[dlzka1][0], nacitanie);
		strcpy(&sklad1[dlzka1][0], nacitanie);
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