#!/bin/bash

npm run build && npm run deploy && git add . && git commit -a -m 'up' && git push