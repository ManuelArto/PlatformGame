# PlatformGame
Gioco costituito da piattaforme di cui il giocatore si serve per muoversi all’interno di esso, per schivare nemici o per raccogliere bonus.

Man mano che il giocatore avanza tra i livelli, i nemici acquisiscono sempre più attacco e più vita.

Il gioco si conclude quando la vita arriva a 0 e verrà visualizzato a schermo il punteggio ottenuto. 

## Come eseguirlo
Nella cartella del progetto:

```bash
$ make
$ ./Game.out (linux)
```

## Elementi del gioco
- Ambiente:
  - Diviso in stanze e livelli (ogni 2 stanze di avanza di 1 livello)
  - Il giocatore rimane fermo e l'ambiente si muove dietro di esso
- Giocatore:
  - Spara
  - Si muove a destra e sinistra, salta, sale e scende dalle piattaforme
- Nemici:
  - Generazione su piattaforme
  - Tipi:
	  1. Easy: missile che viene generato all'altezza del giocatore e in fondo alla schermo
	  2. Medium: spara e si muove solo sulla sua piattaforma dove è stato generato
	  3. Hard: spara e cerca di raggiungerti
- Bonus:
  - Life: aumenta la vita
  - Points: aumenta i punti
  - Minigun: aumenta frequenza di fuoco per un tempo limitato
  - Invincibility: il giocatore diventa immune per un tempo limitato

## Dati del gioco

Giocatore:
- Vita: 200
- Attacco: 20
- Cooldown_shoot: 0.3

EasyEnemy:
- Vita: 20 (ogni 2 livelli aumenta di 5)
- Attacco: 10 (ogni 2 livelli aumenta di 5)
- Cooldown_spawning: 5s (ogni 2 livelli si decrementa di 1 secondo, fino a 1)
- Cooldown_movement: 0

MediumEnemy:
- Vita: 40 (ogni 2 livelli aumenta di 5)
- Attacco: 20 (ogni 2 livelli aumenta di 5)
- Points: 100 (ogni 2 livelli aumenta di 25)
- Cooldown_movement: 1.0 (ogni 2 livelli si decrementa di 0.2, fino ad arrivare a 0.4)
- Cooldown_shoot: 1.0
- min_distance_shoot: 30

HardEnemy:
- Vita: 60 (ogni 2 livelli aumenta di 5)
- Attacco: 30 (ogni 2 livelli aumenta di 5)
- Points: 150 (ogni 2 livelli aumenta di 25)
- Cooldown_movement: 0.5 (ogni 2 livelli si decrementa di 0.1 (fino a 0.2))
- Cooldown_shoot: 1.0
- min_distance_shoot: 30

Probabilità bonus per stanza:
- 1: 20%
- 2: 50%, 
- 3: 10%, 
- 0: 20%

Bonus:
- Points: +50 (ogni 2 livelli aumenta di 25)
- Life: +30 (ogni 2 livelli aumenta di 20)
- Minigun: 5 secondi (ogni 2 livelli aumenta di 1, fino a 12)
- Invincibility: 5 secondi	 ogni 2 livelli aumenta di 1, fino a 12)
