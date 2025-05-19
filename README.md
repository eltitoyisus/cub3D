# cub3D

![cub3D](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/C-100%25-blue)
[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/eltitoyisus/cub3D)

**cub3D** is a 3D graphics project developed as part of the 42 School curriculum. It uses **raycasting** techniques to render a pseudo-3D world from a 2D map, inspired by the classic game *Wolfenstein 3D*.

---

## 🎯 Project Goals

- Implement a simple graphics engine using raycasting techniques.
- Work with the [`MiniLibX`](https://harm-smits.github.io/42docs/libs/minilibx) graphics library.
- Parse and validate `.cub` map files.
- Simulate a first-person perspective in a 3D environment.
- Manage custom textures and colors for walls, floor, and ceiling.

---

## 🔧 Requirements

- OS: Linux
- Compiler: `gcc`
- Libraries:
  - `MiniLibX`
  - `math.h` (used for trigonometry)

---

## ⚙️ Compilation

Clone this repository and compile using `make`:

```bash
git clone https://github.com/eltitoyisus/cub3D.git
cd cub3D
make
```

---

## 🚀 Execution

```bash
./cub3D maps/map.cub
```

Make sure the `.cub` file is correctly formatted and follows the project rules.

---

## 🧾 Structure of a `.cub` file

```cub
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
1011111101
100N000001
1111111111
```

- `NO`, `SO`, `WE`, `EA`: Wall textures by orientation.
- `F`, `C`: Floor and ceiling colors.
- The map: `1` for walls, `0` for empty space, `N/S/E/W` for the player’s initial position and direction.

---

## 🎮 Controls

- `W`, `A`, `S`, `D`: Move the player
- `←`, `→`: Rotate the camera
- `ESC`: Exit the game

---

## ✅ Features

- [x] Raycasting for 3D rendering
- [x] Full `.cub` map validation
- [x] Player movement and rotation
- [x] Wall texture rendering
- [x] Floor and ceiling color management
- [ ] Sprites, doors, or enemies (optional)
- [ ] Minimap (optional)

---

## 👤 Author

Project developed by [@eltitoyisus](https://github.com/eltitoyisus) (jramos-a)  [42 Madrid](https://42.fr/).

---
