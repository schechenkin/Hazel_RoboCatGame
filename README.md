# RoboCat Multiplayer Game on Hazel Engine

![RoboCat](/Resources/Branding/robocat.png?raw=true "Hazel")

## Getting Started
This is port RoboCat game from book [Multiplayer Game Programming: Architecting Networked Games](https://www.amazon.com/Multiplayer-Game-Programming-Architecting-Networked/dp/0134034309) on [Hazel Engine](https://github.com/TheCherno/Hazel)

Visual Studio 2017 or 2019 is recommended, Hazel is officially untested on other development environments whilst we focus on a Windows build.

You can clone the repository to a local destination using git:

`git clone --recursive https://github.com/schechenkin/Hazel_RoboCatGame.git`

Make sure that you do a `--recursive` clone to fetch all of the submodules!

Run 'scripts/Win-GenProjects.bat'

## How to play

- Start server: `RoboCatServer.exe [port]`
- Start cleint: `RoboCatClient.exe 127.0.0.1:[port] [playername]`

Example:
- `RoboCatServer.exe 40000`
- `RoboCatClient.exe 127.0.0.1:40000 player1`
- `RoboCatClient.exe 127.0.0.1:40000 player2`
