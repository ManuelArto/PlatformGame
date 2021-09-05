# PlatformGame

PlatformGame 2021

## Gioco
- Ambiente:
  - Diviso in livelli (stanze per ogni livello --> poi ti muovi con l'ambiente)
  - Piattaforme procedural generation con seed iniziale
- Giocatore:
  - spara
  - si muove a destra e sinistra, salta, sale e scende dalle piattaforme
  - vita (diminuisce, GAME OVER a 0)
  - punti (aumentano quando uccidi nemici e col bonus)
- Nemici:
  - spawning su piattaforme o su terreno
  - Tipi:
	  1. base: tipo missile (aumenta la velocità)
	  2. medio: spara, si muove solo sulla sua piattaforma di spawn (aumenta la frequenza di fuoco, vita ??)
	  3. avanzato: spara, si muove verso di te (aumenta frequenza di fuoco e colpi, vita ??)
- Bonus:
  - life: aumenta la vita
  - minigun: aumenta frequenza di fuoco
  - points: aumenta i punti
  - Invulnerabilità: immune (cambia colore)

## TODO
Change __null to NULL
NEMICI:
	- Check HardEnemy for each template room
	- ALLA FINE: gestire vita, punti danno ecc..
SOLO ALLA FINE:
	- Check di tutto il codice, inserimento commenti

## Definizione del gioco

Giocatore:
- Vita: 200
- Attacco: 20

EasyEnemy:
	- Vita: 20
	- Attacco: 10
	- Cooldown_spawning: 5s (ogni 2 livelli si decrementa di 1 secondo, fino a 1)
	- Cooldown_movement: 0.2s (ogni 2 livelli si decrementa di 0.1, fino ad arrivare a 0)
MediumEnemy:
	- Vita: 40
	- Attacco: 20
	- Points: 100 (ogni 2 livelli aumenta 25)
	- Cooldown_movement: 1.0 (ogni 2 livelli si decrementa di 0.2, fino ad arrivare a 0.4)
	- Cooldown_shoot: 0.5
	- min_distance_shoot: 30
HardEnemy:
	- Vita: 60
	- Attacco: 30
	- Points: 150 (ogni 2 livelli aumenta 25)
	- Cooldown_movement: 0.5 (ogni 2 livelli si decrementa di 0.1 (fino a 0.2))
	- Cooldown_shoot: 0.5
	- min_distance_shoot: 30

4 Bonus:
(1: 20%, 2: 50%, 3: 10%, 0: 20%)
- Punti: +50 (ogni 2 livelli aumenta 25)
- Vita: +30 (ogni 2 livelli aumenta 20)
- Minigun: 5 secondi		(ogni 2 livelli aumenta di 1, fino a 12)
- Invincibilità: 5 secondi	(ogni 2 livelli aumenta di 1, fino a 12)

Ogni 2 stanze si avanza di un livello, e ogni 2 livelli i nemici diventano sempre più potenti (attacco +5, vita +5)
Ogni 2 livelli minigun e invincibilità aumentano di un secondo