#include "drivers/st7789/st7789.hpp"
#include "drivers/rgbled/rgbled.hpp"
#include "drivers/button/button.hpp"
#include "libraries/pico_vector/pico_vector.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "libraries/pico_display/pico_display.hpp"
#include "libraries/bitmap_fonts/font8_data.hpp"

pimoroni::ST7789 st7789(pimoroni::PicoDisplay::WIDTH, pimoroni::PicoDisplay::HEIGHT, pimoroni::ROTATE_0, false, pimoroni::get_spi_pins(pimoroni::BG_SPI_FRONT));
pimoroni::PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);
pimoroni::Rect text_rect(0, 0, pimoroni::PicoDisplay::WIDTH, pimoroni::PicoDisplay::HEIGHT);

void setup()
{
    graphics.set_font(&font8);
    st7789.set_backlight(200);
}

pimoroni::Point centerText(const std::string& message, float scale)
{
    int32_t width = graphics.measure_text(message, scale);
    int32_t height = 1;

    if (graphics.bitmap_font)
    {
      height = graphics.bitmap_font->height * scale;
    }

    return {(pimoroni::PicoDisplay::WIDTH / 2) - (width / 2), (pimoroni::PicoDisplay::HEIGHT / 2) - (height / 2)};
}

void displayText(const char* message, float scale, pimoroni::Rect& rect)
{
    std::string tempMessage = std::string(message);

    graphics.text(tempMessage, centerText(tempMessage, scale), rect.w, scale);
}

void draw()
{
    // Clear the screen.
    graphics.set_pen(0, 0, 0);
    graphics.clear();

    // Create background rectangle.
    graphics.set_pen(10, 20, 30);
    graphics.rectangle(text_rect);
    text_rect.deflate(10);

    // Create text.
    graphics.set_pen(110, 120, 130);
    displayText("Hello World!", 4.f, text_rect);
}

int main()
{
    setup();

  while(true)
  {
    draw();
    st7789.update(&graphics);
  }

  return 0;
}