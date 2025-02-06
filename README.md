# Caravel User Project

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0) [![UPRJ_CI](https://github.com/efabless/caravel_project_example/actions/workflows/user_project_ci.yml/badge.svg)](https://github.com/efabless/caravel_project_example/actions/workflows/user_project_ci.yml) [![Caravel Build](https://github.com/efabless/caravel_project_example/actions/workflows/caravel_build.yml/badge.svg)](https://github.com/efabless/caravel_project_example/actions/workflows/caravel_build.yml)

## Overview

This repository contains a UART implementation for the [Caravel](https://github.com/efabless/caravel.git) chip user space. It demonstrates integration of the EF_UART IP with Caravel's Wishbone interface and follows the recommended structure for open-mpw shuttle projects.

## Prerequisites

- Docker: [Linux](https://docs.docker.com/desktop/install/linux-install/) | [Windows](https://desktop.docker.com/win/main/amd64/Docker%20Desktop%20Installer.exe) | [Mac with Intel Chip](https://desktop.docker.com/mac/main/amd64/Docker.dmg) | [Mac with M1 Chip](https://desktop.docker.com/mac/main/arm64/Docker.dmg)
- Python 3.8+ with PIP

## Quick Start

1. Clone the repository:

```bash
git clone https://github.com/efabless/caravel_user_UART.git
```

2. Set up your environment:
```bash
cd caravel_user_UART
make setup
```

3. Install the EF_UART IP:
```bash
ipm install EF_UART
```

4. Harden the UART macro:
```bash
make uart_macro_wrapper
```

5. Harden the user project wrapper:
```bash
make user_project_wrapper
```

6. Run simulation:
```bash
# RTL simulation
make verify-uart-rtl

# Gate-level simulation
make verify-uart-gl
```

7. Run timing analysis:
```bash
make extract-parasitics
make create-spef-mapping
make caravel-sta
```

8. Run precheck:
```bash
make precheck
make run-precheck
```

## Documentation

For more details about:
- EF_UART IP: Check the [EF_UART documentation](ip/EF_UART/EF_UART.pdf)
- Caravel integration: See the [Caravel documentation](https://caravel-harness.readthedocs.io/)
- Simulation environment: Visit [Caravel Simulation Infrastructure](https://caravel-sim-infrastructure.readthedocs.io/)

## License

This project is licensed under the Apache License, Version 2.0. See [LICENSE](LICENSE) for details.