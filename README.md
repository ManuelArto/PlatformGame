# PlatformGame

PlatformGame 2021

## Gioco
- Ambiente:
  - Diviso in livelli (stanze per ogni livello --> poi ti muovi con l'ambiente)
  - Generazione pseudo-random con seed ??
  - Piattaforme / fossi
- Giocatore:
  - spara
  - si muove a destra e sinistra e saltare(??)
  - vita (diminuisce, GAME OVER a 0)
  - punti (aumentano quando uccidi nemici)
- Nemici:
  - spawning su piattaforme o su terreno
  - diversi tipi:
	  1. base: tipo missile (aumenta la velocità)
	  2. medio: spara, si muove solo sulla sua piattaforma di spawn (aumenta la frequenza di fuoco, vita ??)
	  3. avanzato: spara, si muove verso di te (aumenta frequenza di fuoco e colpi, vita ??)
- Bonus a tempo:
  - minigun: aumenta frequenza di fuoco
  - rallenty: nemici più lenti
  - Invulnerabilità: immune

## TODO
- sistemare problema collision e fare merge
- fare i template
- spawning bonus e nemici
- gestione livello difficoltà

## REGOLE DEL GIOCO
Giocatore:
- Vita: 200
- Attacco: 20

Nemici:
- Vita EasyEnemy: 20
- Vita MediumEnemy: 40
- Vita HardEnemy: 60
- Attacco EasyEnemy: 10
- Attacco MediumEnemy: 20
- Attacco HardEnemy: 30

4 Bonus: 
- Punti: +50
- Vita: +50
- Minigun: 10 secondi 
- Invincibilità: 10 secondi

