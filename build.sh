#!/bin/bash

ASTYLE_DOWNLOAD_URL="https://sourceforge.net/projects/astyle/files/latest/download?source=files"
ASTYLE_ARCHIVE="astyle_linux.tar.gz"
ASTYLE_IMPLEMENTATION="js_format_string.cpp"
ASTYLE_JS="astyle.js"

build() {
    FILES=(
        js_format_string.cpp
        astyle_main.cpp
        ASBeautifier.cpp
        ASFormatter.cpp
        ASEnhancer.cpp
        ASLocalizer.cpp
        ASResource.cpp
    )
    OUTPUT_FILE="astyle.js"
    LDFLAGS="-O3"

    echo "Building: ${OUTPUT_FILE}"
    emcc --memory-init-file 0 -DASTYLE_LIB ${LDFLAGS} ${FILES[@]} -o ${OUTPUT_FILE} -s EXPORTED_FUNCTIONS='["_js_format_string"]'
}

mkdir -p build/
cd build/
curl -L -o ${ASTYLE_ARCHIVE} ${ASTYLE_DOWNLOAD_URL}
tar xvf ${ASTYLE_ARCHIVE}
cp -v ../src/${ASTYLE_IMPLEMENTATION} astyle/src

cd astyle/src
build
cd -
cd ..

mkdir -p dist/
cp -v build/astyle/src/${ASTYLE_JS} dist/

echo ""
echo "Thats all folks! Look for the produced file at dist/ directory."
