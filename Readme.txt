Program: 
Ide o program ktorý dokáže nájsť cestu v bludisku ktoré mu zadáte.
Bludisko ukladám do dvoch dvojrozmerných polí, prvé pošlem do funkcie hladaj cestu. 
cestu hladá štýlom 
že má poradie smerov ktorými sa má pohybovať, pokial sa ocitne na
 križovatke tak si zaznačí jej súradnice.
 vyberie sa jedným smerom a pokial je cesta
 neprejazdná vráti sa späť na križovatku. Keď vyčerpá všetky 
 možnosti vráti sa o 
daľšiu križovatku naspät až dokial nenájde správnu cestu. pri každom pohybe si 
 
zaznamenávam posun polom do pola Cesta, v prípade návratu na križovatku sa cesta 
vymaže (od suradnic 
 križovatky) a začne sa písať novšia. Keď pocet krokov presiahne 
určitý počet tak sa zastaví alebo ked 
 neexistuje cesta. výsledné bludisko sa vykreslí
 z druhého bludiska(povodne) pomocov zaznačených údajov v 
 poli cesta. jednotlivé 
navstívené body sa prepisujú na "0" a výsledná cesta je taktiež vykreslená "0".


na refaktoring som pouzil namiesto if switch pretoze je prehladnejsi.