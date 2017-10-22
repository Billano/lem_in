# Lem-In

The purpose of this project is to create a "Hex" simulator. This program takes an ant farm as an input and displays the shortest path each ant would take to reach the end. The ant farm includes: the number of ants, the starting room, the finishing room, and the connection between all the rooms. This project explores the graph theory and the different algorithms that could be used to find the shortest path, in my case I implemented Dijkstra.

<img src="extra/grade.png" alt="grade" style="height: 250px;"/>

## Getting Started

### Prerequisites

Clone the repository locally

### Installing

#### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`

## Running the tests

Try running the following:

`./lem_in < extra/maps/big`

`./lem_in < extra/maps/input0`

`./lem_in < extra/maps/simple`

`./lem_in < extra/maps/test`


## Deployment

Made for MacOS, might run/compile different in another OS

## Built With

* C language
* Coffee
* Lots of love

## Authors

* **Eugenio Rodriguez** -- [Billano](https://github.com/Billano)

## Acknowledgments

* 42
