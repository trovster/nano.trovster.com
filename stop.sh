#!/bin/bash

cd $(dirname $0)

docker stop trovster_nano
docker rm trovster_nano