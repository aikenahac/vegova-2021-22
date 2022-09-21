# Varnost podatkovnih baz
## Obstojnost podatkov
- Backup
- Varnostna kopija
- Arhiv

### Backup
- V primeru izpada primarne zbirke podatkov zagotavlja razpoložljivost seundarna (backup)
- Je popolna slika primarne zbirke v določenemu trenutku in preklop je hiter
- Ključno je konsistentno stanje zbirke podatkov ves čas delovanja
- Razpoložljivost

### Varnostna kopija
- Podatki ali strojna oprema se včasih "pokvari"
- Povrnitev traja daljši čas
- Povrnitev običajno pomeni tudi vrnitev na stanje v preteklosti in morebitno ponavljanje transakcij, ki so bile izvedene po izdelavi varnostne kopije
- Celovitost

### Obstojnost podatkov
**Arhiv:**
- Poslovne zahteve
	- Katere podatke o preteklosti rabimo danes ali v prihodnosti
- Zakonske zahteve
	- Katere podatke smemo/moramo hraniti v skladu z zakonskimi predpisi
- Najdražje zahteve zaradi zastarevanja programske in strojne opreme

### Varnost zbirk podatkov
- Kraja in ponarejanje
- Izguba zaupanja
- Izguba zasebnosti
- Izguba celovitosti
- Izguba razpoložljivosti
