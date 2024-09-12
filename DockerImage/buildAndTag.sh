#!/bin/bash

docker context use default
docker build -t "raywilfong/stm8-dev:1.$(date +%y.%m%d-%H%M)" .
docker build -t "raywilfong/stm8-dev" .
