# PSU_2016_Tetris

The goal of this project was to recreate the Tetris game in a UNIX terminal, with the Gameboy version rules

### Prerequisites

What things you need to install the Tetris

```
GlibC , GCC and make
```

### Installing

There is a Makefile in the repository

```
make
```

### USAGE

```
Usage: ./tetris [options]$
Options:$
--help Display this help$
-l --level={num} Start Tetris at level num (def: 1)$
-kl --key-left={K} Move the tetrimino LEFT using the K key (def: left arrow)$
-kr --key-right={K} Move the tetrimino RIGHT using the K key (def: right arrow)$
-kt --key-turn={K} TURN the tetrimino clockwise 90d using the K key (def: top arrow)$
-kd --key-drop={K} DROP the tetrimino using the K key (def: down arrow)$
-kq --key-quit={K} QUIT the game using the K key (def: ’q’ key)$
-kp --key-pause={K} PAUSE/RESTART the game using the K key (def: space bar)$
--map-size={row,col} Set the numbers of rows and columns of the map (def: 20,10)$
-w --without-next Hide next tetrimino (def: false)$
-d --debug Debug mode (def: false)$
```

## Authors

* **Quentin Sonnefraud** -*Parsing Tetrimos, falling tetriminos and all parsing* - [Vatoth](https://github.com/Vatoth)
* **Lothaire Noah** -*Ncurses Interface and Assignement Shorcuts for any terminal* -

Made with love at Epitech Paris in 2017
