# Funkcije v SQL

## Funkcije, ki jih definira SQL standard
- **position** - išče podniz v nizu ali besedilu
- **char_length, octet_length, bit_length** - vrne velikost niza
- **substring** - vrne podniz niza ali besedila
- **upper**, **lower** - pretvori niz v velike ali majhne črke
- **extract** - vrne določeno komponento datuma ali časa
- **current_date**, **current_time**, **current_timestamp** - vrne trenutni datum/čas
- **nullif** - primerja vrednosti izraza
- **coalesce** - vrne vrednost prvega izraza, ki ni null
- **cast** - pretvori en tip podatka v drugi

### Position
`POSITION (str in str2)`

### Substring
`SUSTRING (str FROM start [ FOR length ])`

### Exract
`EXTRACT ({ DAY | MONTH | YEAR | HOUR | MINUTE | SECOND } FROM arg)`

### Coalesce
`COALESCE (expr1 {, expr2})`

