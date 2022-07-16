# Gas sensor app

This repository contains an app for the gas sensor on the [MCH2022 badge](https://github.com/badgeteam/mch2022-badge-hardware).

The app displays temperature, relative humidity, pressure and gas sensor resistance.

The app gives the possibbility to configure gas sensor heater set-point and delay.

## License

The source code contained in this repository is licensed under terms of the MIT license, more information can be found in the LICENSE file.

Source code included as submodules is licensed separately, please check the following table for details.

| Submodule                   | License                           | Author                                                 |
|-----------------------------|-----------------------------------|--------------------------------------------------------|
| esp-idf                     | Apache License 2.0                | Espressif Systems (Shanghai) CO LTD                    |
| components/appfs            | THE BEER-WARE LICENSE Revision 42 | Jeroen Domburg <jeroen@spritesmods.com>                |
| components/bus-i2c          | MIT                               | Nicolai Electronics                                    |
| components/i2c-bno055       | MIT                               | Nicolai Electronics                                    |
| components/i2c-bme680       | MIT                               | Andrejs Bondarevs                                      |
| components/mch2022-rp2040   | MIT                               | Renze Nicolai                                          |
| components/pax-graphics     | MIT                               | Julian Scheffers                                       |
| components/pax-keyboard     | MIT                               | Julian Scheffers                                       |
| components/sdcard           | MIT                               | Nicolai Electronics                                    |
| components/spi-ice40        | MIT                               | Nicolai Electronics                                    |
| components/spi-ili9341      | MIT                               | Nicolai Electronics                                    |
| components/ws2812           | MIT                               | Unlicense / Public domain                              |

## How to make
```sh
git clone --recursive https://github.com/abondarevs/mch2022-gas-sensor-app.git
cd mch2022-gas-sensor-app
make prepare
make
```
