<h1 align="center">
  so_long
</h1>

<p align="center">
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LineGM/ft_printf?color=critical"/>
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/LineGM/ft_printf?color=yellow"/>
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/LineGM/ft_printf?color=blue"/>
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/LineGM/ft_printf?color=green"/>
</p>

---

## About the project

> _This project is a very small 2D game.
Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements._

For more detailed information: [**subject**](https://github.com/LineGM/so_long/blob/main/so_long_en.pdf).

## Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```

or

```shell
$ make bonus
```

## How to play

To play the minigame just need to launch it with the following shell command:

```shell
$ ./so_long <map_name>.ber
```

There is some maps if you want to test the game.

**Controls**

You can use WASD to move UP, LEFT, DOWN or RIGHT respectively.
To quit the game press ESC or click on the red cross of window.
If you touch an enemy you loose the game.
To win its necessary to pick up all collectibles and get back to the exit.

**Maps**

You can use any map of your choice as long as you follow the next rules:

* The file extension must be `.ber`.
* Its must be rectangular, and the whole map limits must be a `1`.
* It can only have one exit, one player and at least one collectible.
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | Obstacle                 |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
|     *V*     | Enemy position           |
