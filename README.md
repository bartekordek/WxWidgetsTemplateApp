# WxWidgetsTemplateApp

[![CMake on Linux Platform](https://github.com/bartekordek/WxWidgetsTemplateApp/actions/workflows/cmake-linux.yml/badge.svg)](https://github.com/bartekordek/WxWidgetsTemplateApp/actions/workflows/cmake-linux.yml)
[![CMake on Windows Platform](https://github.com/bartekordek/WxWidgetsTemplateApp/actions/workflows/cmake-win.yml/badge.svg)](https://github.com/bartekordek/WxWidgetsTemplateApp/actions/workflows/cmake-win.yml)

A simple WxWidgets application template configured with CMake for fast cross-platform setup and development.

## About

CMake is pretty straightforward and works well for a small cross-platform project like this one.

It gives a simple and predictable way to configure the build.

This repository is a small practical example of how to use that setup together with GitHub Actions to compile the app on multiple platforms.

This project is meant to be an easy starting point for a CMake-based build workflow.

## Quick start

Clone the repository and initialize the submodules:

```bash
git clone https://github.com/bartekordek/WxWidgetsTemplateApp.git
cd WxWidgetsTemplateApp
git submodule update --init --recursive
```

Then configure and build from the project root.

### Build

```bash
cmake -S . -B Your_Build_Dir -DCMAKE_BUILD_TYPE=Debug
cmake --build Your_Build_Dir --config Debug
```

## Project structure

```text
WxWidgetsTemplateApp/
├── CMakeLists.txt
├── README.md
├── deps/
│   └── wxWidgets/
├── WxWidgetsTemplateApp/
│   ├── inc/
│   └── src/
```

## License

This project is licensed under the MIT License.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Also, if you like this project, feel free to buy me a beer.
