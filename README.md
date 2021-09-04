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
PUNTI:
	- Add points when kill enemies
NEMICI:
	- Check HardEnemy for each template room
	- ALLA FINE: gestire vita, punti danno ecc..
GENERAZIONE:
	- Nemici e bonus pseudo-random (spawning su punteggio/livello)
VIEW:
	- Modifica Screen iniziale
	- Modifica Screen finale
SOLO ALLA FINE:
	- Definire GIOCO (Gestione vita punti bonus nemici ecc..)
	- Check di tutto il codice, inserimento commenti e eventuale redefined

## Definizione del gioco
Giocatore:
- Vita: 250
- Attacco: 20

EasyEnemy:
	- Vita: 20
	- Attacco: 10
	- Cooldown_spawning: 5s (ogni 3 livelli si decrementa di 1 secondo)
	- Cooldown_movement: 0.2s (ogni 3 livelli si decrementa di 0.1, fino ad arrivare a 0)
MediumEnemy:
	- Vita: 40
	- Attacco: 20
	- Cooldown_movement: 0.5
	- Cooldown_shoot: 0.5
HardEnemy:
	- Vita: 60
	- Attacco: 30
	- Cooldown_movement: 0.5
	- Cooldown_shoot: 0.5

4 Bonus:
- Punti:+50
- Vita:+50
- Minigun: 5 secondi 
- Invincibilità: 5 secondi

Ogni 4 stanze si avanza di un livello, e ogni 3 livelli i nemici diventano sempre più potenti (attacco +5, vita +5)
Ogni 3 livelli minigun e invincibilità aumentano di un secondo