# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.0.2] - 2026-09-05

### Added
- Main source file `src/main.cpp` containing the executable's base structure.
- Dynamic resolution of the user's root directory using environment variables (`HOME`).
- Security validation (early exit) to prevent segmentation faults if the environment variable is undefined.
- Integration of C++17 `<filesystem>` to locate and validate the existence of the test environment (`GTAIV_Pruebas`).
- Changelog added.
- CMakelists.txt added.
- DEV_NOTES added.
- Doxyfile added.


## [0.0.1] - 2026-09-05

### Added

- Initial repository creation
- `.gitignore` file configured to ignore C++ binaries, CMake caches, and local development environment metadata.
- `LICENSE.md` file implementing the MIT License.
- `README.md` file containing the project overview, planned features, and the tool's manifesto.