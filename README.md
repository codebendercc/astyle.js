# astyle.js
The astyle [1] library in JavaScript through emscripten

## Requirements
- A working emscripten installation [2] is required (`emcc` executable should be in PATH)

## Build process
- Clone the repository
- Run `./build.sh`
- The build script will download the latest version of the astyle library
- The produced **astyle.js** file will be located at dist/ directory

###### Inspired from [3]

## References
- [1] http://astyle.sourceforge.net/
- [2] https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html
- [3] https://github.com/tzikis/astyle.js
