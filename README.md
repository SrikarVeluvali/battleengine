# Battle Engine (Release) Documentation

### Presented as a Project for Internals in I year I sem at `KMIT`

**Author:** Srikar Veluvali

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Gameplay](#gameplay)
  - [Bot Selection](#bot-selection)
  - [Battle Mechanics](#battle-mechanics)
  - [Leaderboard](#leaderboard)
- [Secret Battle](#secret-battle)
- [Additional Notes](#additional-notes)

## Introduction

The Battle Engine is a text-based command-line game written in C. It simulates a series of battles between the player and various bots. The goal is to defeat all opponents and achieve the highest score on the leaderboard. The game features strategic combat, dynamic battle sequences, and a secret battle with a special challenge.

## Features

- Choose from three different bots: MechBot, PsyBot, AgileBot.
- Engage in strategic turn-based battles with various opponents.
- Experience dynamic battle sequences with unique attack options.
- Compete for the top spot on the leaderboard.
- Unlock a secret battle with an extra challenge.

## Getting Started

1. **Compile:** Compile the source code using a C compiler (e.g., GCC).
   ```
   gcc -o battle_engine battle_engine.c
   ```

2. **Run:** Execute the compiled program.
   ```
   ./battle_engine
   ```

## Gameplay

### Bot Selection

At the beginning of the game, you'll be prompted to choose a bot from three options:

1. MechBot - HP: 100, Speed: 60
2. PsyBot - HP: 100, Speed: 60
3. AgileBot - HP: 100, Speed: 70

### Battle Mechanics

- Each battle is turn-based, with alternating attacks between you and your opponent.
- Choose attacks from a menu based on your bot's abilities and available move points (PP).
- Some attacks have a chance to miss, adding an element of unpredictability.
- Monitor your HP (hit points) and opponent's HP to gauge the progress of the battle.
- The battle ends when either your HP or your opponent's HP drops to zero.

### Leaderboard

After completing battles, your score is calculated based on the number of battles won. Your score is then displayed on the leaderboard alongside other players' scores.

## Secret Battle

If you manage to complete all battles successfully, you'll unlock a secret battle against the mysterious ???Bot. This battle provides an additional challenge and a unique experience.

## Additional Notes

- This game contains dynamic battle sequences with various attack options.
- Sound effects and background music enhance the gaming experience.
- The game includes an engaging storyline with interactions between characters.
- The secret battle adds an element of mystery and exploration to the gameplay.

Feel free to explore, strategize, and aim for the highest score on the leaderboard! Good luck and have fun battling your way to victory!
