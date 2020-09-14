#!/bin/bash
git init
git add main.cpp
git add include
git add src
git add command.sh
git commit -m "firs version Poker"
git remote add origin https://github.com/slow92/Console-Poker-version-1.0.git
git push origin master -f