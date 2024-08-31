#!/bin/bash

docker context use default
docker build -t "rwilfong/stm8-dev:1.$(date +%y.%m%d-%H%M)" .
docker build -t "rwilfong/stm8-dev" .
