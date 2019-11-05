#!/bin/bash

# sh ./start.sh OR sh ./start.sh --build

cd $(dirname $0)

docker-compose -f ./docker-compose.yaml up -d $1
