# Blackjack_AI

A small C++ Blackjack game implementation. This repository contains the source code for a console-based Blackjack game with simple AI/dealer logic and player/human interfaces.

## Overview

This project implements the core components of a Blackjack game in C++: cards, deck, players (human and dealer), game flow, printing utilities, and simple statistics.

It's organized as a small, self-contained command-line program that can be compiled with g++.

## Prerequisites

- A C++ compiler (g++ recommended).
- Standard C++ library (no external dependencies).

On Windows, you can use MinGW-w64, MSYS2, or WSL to get `g++`.

## Build & Run

If you are currently inside the `build/` directory, first move up to the project root:

```powershell
cd ..    # if you are in the build directory
```

Then compile the project with g++ from the project root:

```powershell
g++ src/blackjack.cpp src/card.cpp src/dealer.cpp src/deck.cpp src/game.cpp src/human.cpp src/player.cpp src/print.cpp src/statistics.cpp -o blackjack
```

Run the program:

```powershell
./blackjack       # viola!
```

Note for Windows users using native PowerShell (without a Unix-like environment): after compilation the executable will typically be `blackjack.exe`, so run:

```powershell
.\blackjack.exe
```

(or `./blackjack.exe` if your shell supports that form).

## Project structure

- `src/` - C++ source files
  - `blackjack.cpp` - main entry point
  - `card.cpp`, `deck.cpp` - card and deck implementation
  - `player.cpp`, `human.cpp`, `dealer.cpp` - player types and dealer logic
  - `game.cpp` - game flow and rules
  - `print.cpp` - console output utilities
  - `statistics.cpp` - simple game stats
- `header/` - header files for each module
- `build/` - optional place for build artifacts
- `data/` - any game data (if used)

## Notes & Tips

- The compile command above lists all `.cpp` files individually. You can also use a small Makefile to simplify builds.
- If you prefer incremental builds, consider splitting object files and linking them instead of a single long g++ command.
- If you use an IDE (Visual Studio, CLion, etc.), create a project and add the `src/` files.

## Suggested next steps

- Add a `Makefile` or `CMakeLists.txt` to simplify building across platforms.
- Add a simple test harness for deterministic game scenarios.
- Add documentation for modifying AI/dealer behavior.

## Screenshots

Below are a few screenshots showing the game's ASCII UI and gameplay screens. The images are referenced from `assets/screenshots/`—place the attached screenshot files there with the names used below so they appear in this README.

![Title Screen / Banner](assets/screenshots/screenshot-01.png)

![How to Play / Instructions Screen](assets/screenshots/screenshot-02.png)

![Gameplay / Bust Example](assets/screenshots/screenshot-03.png)

If the images aren't present in your local copy, you can add them into `assets/screenshots/` (create the directory if needed) and name them `screenshot-01.png`, `screenshot-02.png`, and `screenshot-03.png` respectively. On GitHub the images will render inline once uploaded.

## License

This repository does not include a license file. Add `LICENSE` if you want to specify reuse terms.
