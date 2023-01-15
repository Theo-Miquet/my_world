# my_world

![my_world](https://github.com/Theo-Miquet/my_world/blob/main/screenshots/Screenshot%20from%202023-01-15%2022-19-49.png)

`my_world` is a university project made in 2018.
The project requirements were to render a 3D world in C using the CSFML library.

Therefore we decided to take on the challenge of creating a world editor with procedural generation.

## Features

Our world generation tool contains a variety of features:
- Generate a new world procedurally based on variable settings (Size, Frequency, Depth)
- Terraform the world by lifting/pushing vertexes with your mouse
- Undo/Redo changes
- Save your world
- Open a save file

## Installation

### Requirements

`my_world` is supported on Linux only.

This project requires the CSFML library to run.
CSFML is the official C library adaptation of the SFML (C++).
To install the CSFML follow this guide:
> https://pryp.in/blog/12/build-sfml-and-csfml-on-linux.html#other

## Run

`my_world` builds using a Makefile, run the following command within the root folder:
> make

then run:
> ./my_world [save_file]

## Team

- **Mathieu Schmerber**: Rendering engine, terraforming, UI
- **Theo Miquet**: File parser, water animation, procedural generation
