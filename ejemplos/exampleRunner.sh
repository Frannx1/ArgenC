#!/bin/bash
./../argenCC.out < $1".arg" > $1".c"

make $1
./$1.out