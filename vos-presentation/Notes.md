# Strežniki - Kaj so in kako jih uporabljamo

## Kaj je strežnik
Strežnik je strojna oprema, ki zagotavlja funkcionalnost za druge programe ali naprave, katerim rečemo klienti, oizorma odjemalci.

## Delitve

## Delitev po storitvi
Strežnike lahko razdelimo glede na to, za kaj jih uporabljamo.

- Strežnik za e-pošto (mail server)
- Strežnik za prenos datotek (file server)
- Strežnik za tiskanje (print server)
- Spletni strežik (web server)
- Aplikacijski strežnik (application server)

## Delitev po tipu
Strežnike lahko delimo tudi na fizične oblike.

- VPS (Virtual Private Server)
  - virtualni strežnik, z virtualizacijo fizični strežnik razdelimo na več manjših, virtualnih strežnikov
- Dedicated Server (namenski strežnik)
  - namenski strežnik je fizičen strežnik

## Delive po storitvi

### Kaj je strežnik za e-pošto
Strežnik za e-pošto nam omogoča, da postavimo poštne naslove na lastne domene in jih imamo pod lastnim nadzorom.

Delitev na:
- dohodno pošto (incoming)
  - dve glavni različici
    - IMAP - hrani e-pošto na strežniku
    - POP3 - hrani e-pošto na lokalnem računalniku (lahko tudi na strežniku)
- odhodno pošto (outgoing)
  - deluje na SMTP protokolu

#### Delovanje strežnika za e-pošto
1. Ko pošlješ sporočilo, se klient za e-pošto poveže na SMTP strežnik.
2. Klient pošlje vso potrebno sporočilo e-pošte na strežnik.
3. Strežnik preveri e-poštni naslov naslovnika:
  - če je domena enaka pošiljateljevi, pošlje direktno na IMAP/POP3 strežnik in končamo tukaj
  - če domena ni enaka pošiljateljevi, mora naš strežnik komunicirati s strežnikom naslovnika
4. Naš SMTP strežnik komunicira z DNS strežnikom, da najde IP naslovnikovega strežnika.
5. Naš SMTP strežnik se poveže na strežnik naslovnika preko pridobljenega IP naslova.
6. Naslovnikov SMTP strežnik pregleda naše sporočilo. Če je sporočilo validirano, ga pošlje na naslovnikov IMAP/POP3 strežnik.

DEMONSTRACIJA

### Kaj je strežnik za prenos datotek
Strežnik za prenos datotek nam omogoča prenašanje in gostovanje datotek na strežniku, z možnostjo dostopa do njih preko interneta.

#### Delovanje strežnika za prenos datotek

- Nalaganje
  1. FTP klient se poveže na strežnik
  2. Preko klienta izberemo datoteko za nalaganje
  3. Klient pošlje izbrano datoteko na strežnik

- Prenašanje
  1. FTP klient se poveže na strežnik
  2. Preko klienta izberemo datoteko za prenašanje
  3. Klient pošlje izbrano datoteko na lokalno napravo

### Kaj je strežnik za tiskanje
Strežnik za tiskanje nam omogoča, da tiskamo datoteke s tiskalnikom preko interneta.

Načeloma morata biti za delovanje tiskalnik in računalnik s katerega tiskamo v istem omrežju.

1. Strežni vzpostavi povezavo z računalnikom, preko katerega tiskamo
2. Sprejme nalogo in datoteko za tiskanje
3. Pošlje nalogo tiskalniku
4. Tiskalnik lokalno doda datoteko na čakalno vrsto
5. Tiskalnik tiska datoteko

### Kaj je spletni strežnik
S spletnim strežnikom, lahko gostujemo spletne strani na internetu, da jih lahko dostopajo vsi.

1. Uporabnik vpiše domeno v brskalnik
2. Brskalnik domeno pošlje na DNS strežnik in pridobi IP naslov
3. Brskalnik pošlje zahtevo spletnemu strežniku za prikaz spletne strani
4. Brskalnik prikaže spletno stran uporabniku

Pogosti spletni strežniki:
- nginx
- apache
- traefik

Več domen na istem spletnem strežniku/IP naslovu:
Da to dosežemo uporabimo reverse proxy oziroma povratni posrednik.
Reverse proxy na spletnem strežniku skrbi, da prave zahteve pokažejo pravo stran. Ko dobi brskalnik IP naslov strežnika, strežniku pošlje domeno s katere je prišel do strežnika in glede na domeno, mu bo odgovoril s pravo stranjo.

DEMONSTRACIJA

### Kaj je aplikacijski strežnik
Aplikacijski strežnik je strežnik, ki izvaja neko poslovno logiko nad aplikacijo in zagotavlja povezavo med uporabniškim vmesnikom ter podatkovno bazo.

Pristopov do izdelave aplikacijskega strežnika je ogromno, saj je nešteto opcij za izdelavo. 
Lahko ga izdelamo v različnih programskih jezikih, uporabimo katerokoli od baz v malem morju njih, definiramo metodo komunikacije, ki jo bo strežnik uporabljal.

Primer sistema:
- NodeJS & NestJS za logiko
- PostgreSQL za podatkovno bazo

Aplikacijski strežniki v praksi uporabljajo različne metode komunikacij. Najpogostejši so:
- REST
- SOAP
- GraphQL

DEMONSTRACIJA

## Delitev po tipu

### Kaj je VPS
Virtualni strežnik, z virtualizacijo fizični strežnik razdelimo na več manjših,virtualnih strežnikov.

Uporabljajo se za gostovanje različnih storitev, kot so katerakoli od tistih, ki sem jih omenil v prejšnjem delu predstavitve.

Primer Delitve namenskega strežnika na virtualne strežnike:
Sam pokažem norberta

### Kaj je namenski strežnik
Namenski strežnik je fizičen strežnik, uporabljen za bolj intenzivne aplikacije, programe, naloge...

Uporabi se lahko tudi za delitev strežnika na več virtualnih strežnikov, z programi za virtualizacijo kot so Proxmox, VMWare ESXi, Oracle VM in podobno.

## Viri
Lastno znanje