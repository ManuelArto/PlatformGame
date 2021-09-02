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

## TODO
COLLISIONE:
	- Contatto fisico: Player - Enemies					✔
	- Spari between shooter and character				✔	
	- Spari - Piattaforme								✔
	- EasyEnemies - Piattaforme o Muro					✔
	- Spari - Spari										
	- Player - Bonus									✔
	- Controllo proiettile x+-1
NEMICI:
	- Fixing HardEnemy
	- ALLA FINE: gestire vita, punti danno ecc..
GENERAZIONE:
	- Generazione piattaforme per stanza (procedural generation)
	- Gestione nemici (spawning e instanziamento lista dinamica)
	- Nemici e bonus pseudo-random (spawning su punteggio/livello)
SOLO ALLA FINE:
	- Definire GIOCO (Gestione vita punti bonus nemici ecc..)
	- Check di tutto il codice, inserimento commenti e eventuale redefined