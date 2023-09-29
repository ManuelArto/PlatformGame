<img src="logo.png" width=80%><br>

## Introduction
A game consisting of platforms that the player uses to navigate within it, either to dodge enemies or collect bonuses.

As the player progresses through the levels, enemies become increasingly aggressive and gain more health.

The game concludes when the player's life reaches zero, after which their score is displayed on the screen.

For more information, please consult the project report: [click here](Report.pdf)

## How to Run
In the project folder:

```bash
$ make
$ ./Game.out (linux)
```

## Game Elements
- **Environment**:
  - Divided into rooms and levels (every 2 rooms advance to 1 level)
  - The player remains stationary while the environment moves behind them
- **Player**:
  - Shoots
  - Moves right and left, jumps, and ascends or descends from platforms
- **Enemies**:
  - Spawn on platforms
  - Types:
    1. Easy: Missile generated at the player's height and at the bottom of the screen
    2. Medium: Shoots and moves only on its generated platform
    3. Hard: Shoots and tries to reach the player
- **Bonuses**:
  - *Life*: Increases player's life
  - *Points*: Increases points
  - *Minigun*: Increases fire rate for a limited time
  - *Invincibility*: Makes the player immune for a limited time

## Game Data

Player:
- Life: 200
- Attack: 20
- Cooldown_shoot: 0.3

EasyEnemy:
- Life: 20 (increases by 5 every 2 levels)
- Attack: 10 (increases by 5 every 2 levels)
- Cooldown_spawning: 5s (decreases by 1 second every 2 levels, down to 1)
- Cooldown_movement: 0

MediumEnemy:
- Life: 40 (increases by 5 every 2 levels)
- Attack: 20 (increases by 5 every 2 levels)
- Points: 100 (increases by 25 every 2 levels)
- Cooldown_movement: 1.0 (decreases by 0.2 every 2 levels, down to 0.4)
- Cooldown_shoot: 1.0
- min_distance_shoot: 30

HardEnemy:
- Life: 60 (increases by 5 every 2 levels)
- Attack: 30 (increases by 5 every 2 levels)
- Points: 150 (increases by 25 every 2 levels)
- Cooldown_movement: 0.5 (decreases by 0.1 every 2 levels, down to 0.2)
- Cooldown_shoot: 1.0
- min_distance_shoot: 30

Bonus room probabilities:
- 1: 20%
- 2: 50%
- 3: 10%
- 0: 20%

Bonuses:
- **Points**: +50 (increases by 25 every 2 levels)
- **Life**: +30 (increases by 20 every 2 levels)
- **Minigun**: 5 seconds (increases by 1 every 2 levels, up to 12)
- **Invincibility**: 5 seconds (increases by 1 every 2 levels, up to 12)