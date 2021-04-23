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
- Timer per i bonus
- sistemare la grafica
- game over
- platform generation
- regole del gioco
- spawning bonus e nemici
- tempo per collisione fisica dei nemici

## REGOLE DEL GIOCO
- Vita del giocatore: 100
- Vita EasyEnemy: 10
- Vita MediumEnemy: 50