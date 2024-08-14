#!/bin/bash


find . -name '*.sh' | xargs basename | sed 's/\.sh//'
