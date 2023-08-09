# so_long game

Basic 2D game in which a bird can go to the nest after eating all cherries.

**Languages**

[![My Skills](https://skillicons.dev/icons?i=c)](https://skillicons.dev)

**Features**

- The bird’s goal is to collect all cherries present on the map, then go inside the nest chosing the shortest possible route.
- The W, A, S, and D keys can be used to move the bird in 4 directions: up, down, left, right. Arrow keys can also be used alternatively.
- The bird is not able to move into walls.
- At every move, the current number of movements is displayed in the shell.

**Map**

- The map can be composed of only these 6 characters:
  - **0**  empty space,
  - **1**  wall,
  - **C**  collectible/cherry,
  - **E** map exit/nest,
  - **P**  player’s/bird's starting position.
  - **W**  enemy

- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
  
- The map must be rectangular.
  
- The map must be closed/surrounded by walls. If it’s not, the program will return an error.

- Map should have a valid solution.

**Usage**

- Compile and create the executables
  ```
  make
  ```
- Start the game
  ```
  ./so_long <map file path>
  ```
  Example
  ```
  ./so_long maps/big_mapv.ber
  ```

**Resources**

- https://harm-smits.github.io/42docs/libs/minilibx
  
**Result: :one::zero::eight: / :one::zero::zero: :heavy_check_mark:**
