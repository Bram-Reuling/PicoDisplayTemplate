# PicoDisplayTemplate

Template for setting up projects for the Raspberry Pi Pico W and the Pico Display Pack by Pimoroni.

## Hardware
Raspberry Pi Pico WH (W = Wifi & H = Headers)-> https://www.raspberrypi.com/products/raspberry-pi-pico/

I would recommend WH version since I made this template with the same setup. But you can also use others, no guarantees if it works.

Pico Display Pack -> https://shop.pimoroni.com/products/pico-display-pack

## Installation

More info -> https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf

Create a repository of this template project and clone the repository to your pc and run the following commands when you cloned it from GitHub:

```bash
git submodule init
git submodule update
```

Connect the RPI Pico W (with the Pico Display Pack attached to it) to your computer while pressing the `BOOTSEL` button on the board.

Run the project in Visual Studio Code with the Raspberry Pi Pico extension enabled and click on the Run button in the bottom right corner. The project should now be compiled and moved to the Pico.

### Binary

Download `[PROJECT NAME].zip` from the `Releases` section.

Connect the RPI Pico W (with the Pico Display Pack attached to it) to your computer while pressing the `BOOTSEL` button on the board.

**IMPORTANT: DO IT IN THIS ORDER**

First upload the `[PROJECT NAME].bin` to the device.
Then upload the `[PROJECT NAME].utf2` to the device. This will start executing the program.

Enjoy!

## Usage

You should see `Hello World!` on the screen.

## Contributing

Since this is a template, you can just use it and improve it to your own liking. This is just a base to quickly setup projects with the hardware described above.

## License

[MIT](https://choosealicense.com/licenses/mit/)
