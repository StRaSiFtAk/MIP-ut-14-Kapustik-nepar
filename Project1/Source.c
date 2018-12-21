// projekt 2.c -- Denis Vladimír Bílik, 12.4.2018 08:41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sirka, dlzka, dlzka1 = 0, polica = 0, stlpec = 1, navrat = 1, riesenie = 0, pocitadlo1, pocitadlo2;
char nacitanie[201], sklad[201][201], sklad1[201][201], ulozene_pozicie_polica[400000], ulozene_pozicie_stlpec[400000], kroky[400000], cesta[400000];

void nulovanie() {
	int m, n;
	polica = 0;
	stlpec = 1;
	//k= 0;
	//l= 0;
	pocitadlo1 = 0;
	pocitadlo2 = 0;
	//pocitadlo3= 0;
	dlzka = 0;
	dlzka1 = 1;
	sirka = 0;
	//sirka1=0;
   // x= 0;
	//y= 0;
	//z= 0;
   // w= 0;
	//q= 0;
	riesenie = 0;
	for (m = 0; m < 201; m++) {
		for (n = 0; n < 201; n++) {
			sklad[m][n] = '\0';
			sklad1[m][n] = '\0';
			nacitanie[m] = '\0';
		}
	}
	for (m = 0; m <= 40000; m++) {
		ulozene_pozicie_polica[m] = '\0';
		ulozene_pozicie_stlpec[m] = '\0';
		kroky[m] = '\0';
		cesta[m] = '\0';
	}
}

void hladaj_cestu() {
	int d = 0, p = 0, l = 0, h = 0, smery = 0, moznost = 0, i = 0;
	while (polica == dlzka - 1 && stlpec == sirka - 1) {
		break;
	}

	sklad[0][1] = '0';
	//polica=0;
	//stlpec=1;
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
	printf("tadeto som chodil: \n");
	for (j = 0; j <= dlzka; j++) {
		for (i = 0; i < sirka; i++) {
			printf("%c", sklad[j][i]);
		}
		printf("\n");
	}
}


void vypis_bludisko() {
	int r, s, polica1 = 0, stlpec1 = 1, krok;
	for (krok = 0; krok < pocitadlo2; krok++) {
		if (cesta[krok] == 'd') {
			polica1++;
			sklad1[polica1][stlpec1] = 'O';
		}
		if (cesta[krok] == 'h') {
			polica1--;
			sklad1[polica1][stlpec1] = 'O';
		}
		if (cesta[krok] == 'l') {
			stlpec1--;
			sklad1[polica1][stlpec1] = 'O';
		}
		if (cesta[krok] == 'p') {
			stlpec1++;
			sklad1[polica1][stlpec1] = 'O';
		}
	}
	printf("riesenie: \n");
	for (r = 0; r < dlzka; r++) {
		for (s = 0; s < sirka; s++) {
			printf("%c", sklad1[r][s]);
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
		while (polica != dlzka - 1 && stlpec != sirka - 1) {
			hladaj_cestu();
		}
		vypis_sklad();
		vypis_bludisko();

		nulovanie();
	}
	printf("\n");
	return 0;
}