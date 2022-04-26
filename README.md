# Battleship

A simple C++ guessing game. The game concept is quite simple:
- Display a board (4x4 by default), and set a ship location at a point
- Get input from the user until they successfully guessed the ship location
- Display the score (fewer attempts will score more)


This project was originally a final group assignment for one of my classes, Praktikum Pemrograman (MII211202). The development of the project happened in a Replit collaborative environment. It is copied here mainly as an archive. Also, it is publicized here as a reference for those new to C++ or taking a similar class.

<img src="https://user-images.githubusercontent.com/30001379/165192301-18e3172f-44a4-4764-8f1b-55d0946122b5.png" width=300>

## Building
Make sure that you have clang and GNU Make installed. Then, using the provided Makefile:
```
make -j $(nproc)
```
You should then see an executable file named `battleship`.

## Authors
- [@ttycelery](https://github.com/ttycelery)
- [@zenxiety](https://github.com/zenxiety)
- Gelora Manalu

## License
Distributed under the MIT License.
