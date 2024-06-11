# 42 - So Long +

Develop a simple 2D game written in C utilizing MiniLibX. 

```You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want.```

My version will include standing enemies, and pushable boxes.


## Usable external functions 

* open, close, read, write, malloc, free, perror, strerror, exit
* All functions of the math library (-lm compiler option, man man 3 math)
* All functions of the MiniLibX
* your coded printf
## Screenshot

![Last Slime](https://i.imgur.com/4ct15B7.png)


## How to Play

Before all you'll need some dependency, install them:

```bash
sudo apt update && sudo apt install xorg libxext-dev zlib1g-dev libbsd-dev
```

now you can compile the project

```bash
make
```

to start the game use the following syntax

```bash
./so_long <map_file.ber>
```

You'll find different levels in the `./maps` folder
